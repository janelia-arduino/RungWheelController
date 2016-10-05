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

  // Pin Setup
  for (int digital_input=0; digital_input<constants::DIGITAL_INPUT_COUNT; ++digital_input)
  {
    pinMode(constants::di_pins[digital_input],INPUT_PULLUP);
  }

  for (int digital_output=0; digital_output<constants::DIGITAL_OUTPUT_COUNT; ++digital_output)
  {
    pinMode(constants::do_pins[digital_output],OUTPUT);
    digitalWrite(constants::do_pins[digital_output],LOW);
    // output_state_[digital_output] = LOW;
  }

  pinMode(constants::enable_increment_pin,INPUT_PULLUP);

  // Set Device ID
  modular_server_.setDeviceName(constants::device_name);

  // Add Device Info
  modular_server_.addFirmwareInfo(constants::firmware_info);

  // Add Storage
  modular_server_.addFieldStorage(fields_);
  modular_server_.addParameterStorage(parameters_);
  modular_server_.addMethodStorage(methods_);

  // Fields
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

// Callbacks must be non-blocking (avoid 'delay')
//
// modular_server_.getParameterValue must be cast to either:
// const char *
// long
// double
// bool
// ArduinoJson::JsonArray &
// ArduinoJson::JsonObject &
//
// For more info read about ArduinoJson parsing https://github.com/janelia-arduino/ArduinoJson
//
// modular_server_.getFieldValue type must match the field default type
// modular_server_.setFieldValue type must match the field default type
// modular_server_.getFieldElementValue type must match the field array element default type
// modular_server_.setFieldElementValue type must match the field array element default type
