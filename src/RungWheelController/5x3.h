// ----------------------------------------------------------------------------
// 5x3.h
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#ifndef RUNG_WHEEL_CONTROLLER_5X3_CONSTANTS_H
#define RUNG_WHEEL_CONTROLLER_5X3_CONSTANTS_H
#include "Constants.h"


#if defined(__MK64FX512__)

namespace rung_wheel_controller
{
namespace constants
{
// Pins

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]
extern const bool polarity_reversed_default[h_bridge_controller::constants::CHANNEL_COUNT];

extern const bool channels_enabled_default[h_bridge_controller::constants::CHANNEL_COUNT];

// Parameters

// Functions

// Callbacks

// Errors
}
}

#endif

#endif
