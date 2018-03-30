// ----------------------------------------------------------------------------
// RungWheelController.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef RUNG_WHEEL_CONTROLLER_H
#define RUNG_WHEEL_CONTROLLER_H
#include <ArduinoJson.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <ConstantVariable.h>
#include <Functor.h>

#include <ModularClient.h>
#include <OpticalSwitchInterface.h>
#include <EncoderInterfaceSimple.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>
#include <HBridgeController.h>

#include "RungWheelController/Constants.h"


class RungWheelController : public HBridgeController
{
public:
  RungWheelController();
  virtual void setup();
  void flip(const ConstantString * const polarity_ptr);
  bool flipEnabled();

  // Handlers
  virtual void stopPwmHandler(int index);

private:
  modular_server::Property properties_[rung_wheel_controller::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[rung_wheel_controller::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[rung_wheel_controller::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[rung_wheel_controller::constants::CALLBACK_COUNT_MAX];

  volatile bool flipping_;
  volatile bool flip_enabled_;
  volatile long flipper_up_inc_;
  volatile long flipper_down_inc_;
  volatile bool flipper_is_up_;
  volatile long flipper_up_count_;

  ModularClient * optical_switch_interface_ptr_;
  ModularClient * encoder_interface_simple_ptr_;

  // Handlers
  void setClientPropertyValuesHandler();
  void flipEnabledHandler();
  void enableFlipHandler(modular_server::Interrupt * interrupt_ptr);
  void disableFlipHandler(modular_server::Interrupt * interrupt_ptr);
  void flipHandler(modular_server::Interrupt * interrupt_ptr);

};

#endif
