// ----------------------------------------------------------------------------
// RungWheelController.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef RUNG_WHEEL_CONTROLLER_H
#define RUNG_WHEEL_CONTROLLER_H
#include "Flash.h"
#include <EEPROM.h>
#include "Streaming.h"
#include "ArduinoJson.h"
#include "JsonSanitizer.h"
#include "JsonStream.h"
#include "Array.h"
#include "Vector.h"
#include "MemoryFree.h"
#include "ConstantVariable.h"
#include "SavedVariable.h"
#include "Functor.h"

#include "IndexedContainer.h"
#include "FunctorCallbacks.h"
#include "EventController.h"

#include "ModularServer.h"
#include "ModularDevice.h"
#include "HBridgeController.h"

#include "utility/Constants.h"


class RungWheelController : public HBridgeController
{
public:
  RungWheelController();
  virtual void setup();
  void flip(const ConstantString * const polarity_ptr);

  // Callbacks
  virtual void stopPwmCallback(int index);

private:
  modular_server::Field fields_[rung_wheel_controller::constants::FIELD_COUNT_MAX];
  modular_server::Parameter parameters_[rung_wheel_controller::constants::PARAMETER_COUNT_MAX];
  modular_server::Method methods_[rung_wheel_controller::constants::METHOD_COUNT_MAX];

  volatile bool flipping_;
  volatile bool flipping_enabled_;
  volatile long flipper_up_inc_;
  volatile long flipper_down_inc_;
  volatile bool flipper_is_up_;
  volatile long flipper_up_count_;

  // Callbacks
  void flipCallback();

};

#endif
