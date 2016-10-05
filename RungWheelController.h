// ----------------------------------------------------------------------------
// RungWheelController.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef H_BRIDGE_CONTROLLER_H
#define H_BRIDGE_CONTROLLER_H
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

#include "EventController.h"
#include "IndexedContainer.h"

#include "ModularServer.h"
#include "ModularDevice.h"
#include "HBridgeController.h"

#include "utility/Constants.h"


class RungWheelController : public HBridgeController
{
public:
  RungWheelController();
  virtual void setup();
  void setChannelOn(const size_t channel, const h_bridge_controller::constants::Polarity polarity);
  void setChannelOff(const size_t channel);
  void setChannelsOn(const uint32_t channels, const h_bridge_controller::constants::Polarity polarity);
  void setChannelsOff(const uint32_t channels);
  void setAllChannelsOn(const h_bridge_controller::constants::Polarity polarity);
  void setAllChannelsOff();
  int addPwm(const uint32_t channels,
             const h_bridge_controller::constants::Polarity polarity,
             const long delay,
             const long period,
             const long on_duration,
             const long count);
  int startPwm(const uint32_t channels,
               const h_bridge_controller::constants::Polarity polarity,
               const long delay,
               const long period,
               const long on_duration);
  void stopPwm(const int pwm_index);
  void stopAllPwm();
  uint32_t arrayToChannels(ArduinoJson::JsonArray & channels_array);
  h_bridge_controller::constants::Polarity stringToPolarity(const char * string);

private:
  modular_server::Field fields_[h_bridge_controller::constants::FIELD_COUNT_MAX];
  modular_server::Parameter parameters_[h_bridge_controller::constants::PARAMETER_COUNT_MAX];
  modular_server::Method methods_[h_bridge_controller::constants::METHOD_COUNT_MAX];

  IndexedContainer<h_bridge_controller::constants::PulseInfo,
                   h_bridge_controller::constants::INDEXED_PULSES_COUNT_MAX> indexed_pulses_;

  // Callbacks
  void setChannelOnCallback();
  void setChannelOffCallback();
  void setChannelsOnCallback();
  void setChannelsOffCallback();
  void setAllChannelsOnCallback();
  void setAllChannelsOffCallback();
  void addPwmCallback();
  void startPwmCallback();
  void stopPwmCallback();
  void stopAllPwmCallback();
  void setChannelsOnCallback(int index);
  void setChannelsOffCallback(int index);
  void stopPwmCallback(int index);

};

#endif
