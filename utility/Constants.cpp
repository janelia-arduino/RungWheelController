// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Constants.h"


namespace rung_wheel_controller
{
namespace constants
{
CONSTANT_STRING(device_name,"rung_wheel_controller");

CONSTANT_STRING(firmware_name,"RungWheelController");
// Use semantic versioning http://semver.org/
const modular_server::FirmwareInfo firmware_info =
  {
    .name_ptr=&firmware_name,
    .version_major=1,
    .version_minor=0,
    .version_patch=0,
  };

CONSTANT_STRING(flipper_delay_field_name,"flipper_delay");
const long flipper_delay_min = 0;
const long flipper_delay_max = 10000;
const long flipper_delay_default = 10;

CONSTANT_STRING(flipper_period_field_name,"flipper_period");
const long flipper_period_min = 2;
const long flipper_period_max = 1000;
const long flipper_period_default = 25;

CONSTANT_STRING(flipper_on_duration_field_name,"flipper_on_duration");
const long flipper_on_duration_min = 1;
const long flipper_on_duration_max = 10;
const long flipper_on_duration_default = 4;

CONSTANT_STRING(rung_up_count_lower_field_name,"rung_up_count_lower");
const long rung_count_min = 0;
const long rung_count_max = 1000;
const long rung_up_count_lower_default = 1;

CONSTANT_STRING(rung_up_count_upper_field_name,"rung_up_count_upper");
const long rung_up_count_upper_default = 10;

CONSTANT_STRING(rung_down_count_field_name,"rung_down_count");
const long rung_down_count_default = 1;

const uint32_t flipper_channels = B11;
const ConstantString * const polarity_up_ptr =  &h_bridge_controller::constants::polarity_positive;
const ConstantString * const polarity_down_ptr =  &h_bridge_controller::constants::polarity_negative;

// Units

// Fields

// Parameters

// Methods

// Interrupts
CONSTANT_STRING(flip_interrupt_name,"flip");

// Errors
}
}
