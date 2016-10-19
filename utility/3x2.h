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
enum {DIGITAL_INPUT_COUNT=2};

extern const size_t di_pins[DIGITAL_INPUT_COUNT];

extern const size_t enable_increment_pin;

// Units

// Fields
// Field values must be long, double, bool, long[], double[], bool[], char[], ConstantString *
extern const bool polarity_reversed_default[h_bridge_controller::constants::CHANNEL_COUNT];

extern const bool channels_enabled_default[h_bridge_controller::constants::CHANNEL_COUNT];


// Parameters

// Methods

// Interrupts

// Errors
}
}
#endif
#endif
