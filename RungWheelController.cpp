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

  // Set Device ID
  modular_server_.setDeviceName(constants::device_name);

  // Add Device Info
  modular_server_.addFirmwareInfo(constants::firmware_info);

  // Add Storage
  modular_server_.addFieldStorage(fields_);
  modular_server_.addParameterStorage(parameters_);
  modular_server_.addMethodStorage(methods_);

  // Fields

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
