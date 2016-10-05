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

// Units

// Fields

// Parameters

// Methods

// Errors
}
}
