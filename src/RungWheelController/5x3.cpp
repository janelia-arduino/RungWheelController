// ----------------------------------------------------------------------------
// 5x3.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "5x3.h"


#if defined(__MK64FX512__)

namespace rung_wheel_controller
{
namespace constants
{
// Pins

// Units

// Properties
const bool polarity_reversed_default[h_bridge_controller::constants::CHANNEL_COUNT] = {false,true,false,false};

const bool channels_enabled_default[h_bridge_controller::constants::CHANNEL_COUNT] = {true,true,false,false};


// Parameters

// Functions

// Callbacks

// Errors
}
}

#elif defined(__AVR_ATmega2560__)

namespace rung_wheel_controller
{
namespace constants
{
// Pins

// Units

// Properties
const bool polarity_reversed_default[h_bridge_controller::constants::CHANNEL_COUNT] = {false,true,false,false};

const bool channels_enabled_default[h_bridge_controller::constants::CHANNEL_COUNT] = {true,true,false,false};


// Parameters

// Functions

// Callbacks

// Errors
}
}
#endif
