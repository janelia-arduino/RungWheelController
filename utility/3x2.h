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

// Parameters

// Methods

// Errors
}
}
#endif
#endif
