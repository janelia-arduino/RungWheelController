// ----------------------------------------------------------------------------
// 3x2.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "3x2.h"


#if defined(__MK20DX256__)

namespace rung_wheel_controller
{
namespace constants
{
const size_t optical_switch_interface_address[1] =
  {
    3,
  };

const size_t encoder_interface_simple_address[2] =
  {
    3,
    3,
  };

// Interrupts

// Units

// Properties
const bool polarity_reversed_default[h_bridge_controller::constants::CHANNEL_COUNT] = {false,true};

const bool channels_enabled_default[h_bridge_controller::constants::CHANNEL_COUNT] = {true,true};


// Parameters

// Functions

// Callbacks

// Errors
}
}
#endif
