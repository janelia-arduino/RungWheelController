// ----------------------------------------------------------------------------
// RungWheelController.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "RungWheelController.h"


using namespace rung_wheel_controller;

RungWheelController::RungWheelController()
{
}

void RungWheelController::setup()
{
  // Parent Setup
  HBridgeController::setup();

  // Variable Setup
  flipping_ = false;
  flipping_enabled_ = true;

  // Pin Setup
  for (int digital_input=0; digital_input<constants::DIGITAL_INPUT_COUNT; ++digital_input)
  {
    pinMode(constants::di_pins[digital_input],INPUT_PULLUP);
  }

  pinMode(constants::enable_increment_pin,INPUT_PULLUP);

  // Interrupt Setup
  FunctorCallbacks::Callback callback = FunctorCallbacks::add(makeFunctor((Functor0 *)0,*this,&RungWheelController::flipCallback));
  if (callback)
  {
    for (int digital_input=0; digital_input<constants::DIGITAL_INPUT_COUNT; ++digital_input)
    {
      noInterrupts();
      attachInterrupt(digitalPinToInterrupt(constants::di_pins[digital_input]),callback,FALLING);
      interrupts();
    }
  }

  // Set Device ID
  modular_server_.setDeviceName(constants::device_name);

  // Add Hardware Info

  // Add Firmware
  modular_server_.addFirmware(constants::firmware_info,
                              fields_,
                              parameters_,
                              methods_);

  // Fields
  modular_server_.field(h_bridge_controller::constants::polarity_reversed_field_name).setDefaultValue(constants::polarity_reversed_default);

  modular_server_.field(h_bridge_controller::constants::channels_enabled_field_name).setDefaultValue(constants::channels_enabled_default);

  modular_server::Field & flipper_delay_field = modular_server_.createField(constants::flipper_delay_field_name,constants::flipper_delay_default);
  flipper_delay_field.setRange(constants::flipper_delay_min,constants::flipper_delay_max);
  flipper_delay_field.setUnits(h_bridge_controller::constants::ms_unit);

  modular_server::Field & flipper_period_field = modular_server_.createField(constants::flipper_period_field_name,constants::flipper_period_default);
  flipper_period_field.setRange(constants::flipper_period_min,constants::flipper_period_max);
  flipper_period_field.setUnits(h_bridge_controller::constants::ms_unit);

  modular_server::Field & flipper_on_duration_field = modular_server_.createField(constants::flipper_on_duration_field_name,constants::flipper_on_duration_default);
  flipper_on_duration_field.setRange(constants::flipper_on_duration_min,constants::flipper_on_duration_max);
  flipper_on_duration_field.setUnits(h_bridge_controller::constants::ms_unit);

  modular_server::Field & rung_up_count_lower_field = modular_server_.createField(constants::rung_up_count_lower_field_name,constants::rung_up_count_lower_default);
  rung_up_count_lower_field.setRange(constants::rung_count_min,constants::rung_count_max);

  modular_server::Field & rung_up_count_upper_field = modular_server_.createField(constants::rung_up_count_upper_field_name,constants::rung_up_count_upper_default);
  rung_up_count_upper_field.setRange(constants::rung_count_min,constants::rung_count_max);

  modular_server::Field & rung_down_count_field = modular_server_.createField(constants::rung_down_count_field_name,constants::rung_down_count_default);
  rung_down_count_field.setRange(constants::rung_count_min,constants::rung_count_max);

  // Parameters

  // Methods

}

void RungWheelController::flip(const ConstantString * const polarity_ptr)
{
  if (!flipping_ && flipping_enabled_)
  {
    flipping_ = true;
    long flipper_delay;
    modular_server_.field(constants::flipper_delay_field_name).getValue(flipper_delay);
    long flipper_period;
    modular_server_.field(constants::flipper_period_field_name).getValue(flipper_period);
    long flipper_on_duration;
    modular_server_.field(constants::flipper_on_duration_field_name).getValue(flipper_on_duration);
    addPwm(constants::flipper_channels,
           polarity_ptr,
           flipper_delay,
           flipper_period,
           flipper_on_duration,
           1);
  }
}

void RungWheelController::stopPwmCallback(int index)
{
  HBridgeController::stopPwmCallback(index);
  flipping_ = false;
}

// Callbacks must be non-blocking (avoid 'delay')
//
// modular_server_.parameter(parameter_name).getValue(value) value type must be either:
// fixed-point number (int, long, etc.)
// floating-point number (float, double)
// bool
// const char *
// ArduinoJson::JsonArray *
// ArduinoJson::JsonObject *
//
// For more info read about ArduinoJson parsing https://github.com/janelia-arduino/ArduinoJson
//
// modular_server_.field(field_name).getValue(value) value type must match the field default type
// modular_server_.field(field_name).setValue(value) value type must match the field default type
// modular_server_.field(field_name).getElementValue(value) value type must match the field array element default type
// modular_server_.field(field_name).setElementValue(value) value type must match the field array element default type

void RungWheelController::flipCallback()
{
  if (!flipping_ && flipping_enabled_)
  {
    long rung_up_count_lower;
    modular_server_.field(constants::rung_up_count_lower_field_name).getValue(rung_up_count_lower);
    long rung_up_count_upper;
    modular_server_.field(constants::rung_up_count_upper_field_name).getValue(rung_up_count_upper);
    long rung_down_count;
    modular_server_.field(constants::rung_down_count_field_name).getValue(rung_down_count);
    if (flipper_is_up_ && (flipper_up_inc_ == flipper_up_count_))
    {
      if (rung_down_count > 0)
      {
        flipper_is_up_ = false;
      }
      flipper_up_inc_ = 0;
    }
    else if (!flipper_is_up_ && (flipper_down_inc_ == rung_down_count))
    {
      if (rung_up_count_upper > 0)
      {
        flipper_is_up_ = true;
        flipper_up_count_ = random(rung_up_count_lower,rung_up_count_upper);
      }
      flipper_down_inc_ = 0;
    }
    if (flipper_is_up_ && (flipper_up_inc_ < flipper_up_count_))
    {
      flip(constants::polarity_up_ptr);
      ++flipper_up_inc_;
    }
    else if (!flipper_is_up_ && (flipper_down_inc_ < rung_down_count))
    {
      flip(constants::polarity_down_ptr);
      ++flipper_down_inc_;
    }
  }
}
