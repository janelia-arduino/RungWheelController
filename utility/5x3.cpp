// ----------------------------------------------------------------------------
// 5x3.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "5x3.h"


#if defined(__AVR_ATmega2560__)

namespace rung_wheel_controller
{
namespace constants
{
const size_t di_pins[DIGITAL_INPUT_COUNT] = {21,20};

const size_t enable_increment_pin = 5;

// Units

// Fields
const bool polarity_reversed_default[h_bridge_controller::constants::CHANNEL_COUNT] = {false,true,false,false};

const bool channels_enabled_default[h_bridge_controller::constants::CHANNEL_COUNT] = {true,true,false,false};


// Parameters

// Methods

// Errors
}
}
#endif
