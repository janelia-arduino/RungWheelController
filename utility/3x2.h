// ----------------------------------------------------------------------------
// 3x2.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef RUNG_WHEEL_CONTROLLER_3X2_CONSTANTS_H
#define RUNG_WHEEL_CONTROLLER_3X2_CONSTANTS_H
#include "Constants.h"


#if defined(__MK20DX256__)

namespace rung_wheel_controller
{
namespace constants
{
enum {DIGITAL_INPUT_COUNT=3};
enum {FLIP_INPUT_COUNT=2};
enum {ENABLE_DISABLE_INPUT=2};

extern const size_t di_pins[DIGITAL_INPUT_COUNT];

// Units

// Fields
// Field values must be long, double, bool, long[], double[], bool[], char[], ConstantString *
extern const bool polarity_reversed_default[h_bridge_controller::constants::CHANNEL_COUNT];

extern const bool channels_enabled_default[h_bridge_controller::constants::CHANNEL_COUNT];


// Parameters

// Methods

// Callbacks

// Errors
}
}
#endif
#endif
