// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef RUNG_WHEEL_CONTROLLER_CONSTANTS_H
#define RUNG_WHEEL_CONTROLLER_CONSTANTS_H
#include "ConstantVariable.h"
#include "HBridgeController.h"


namespace rung_wheel_controller
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{FIELD_COUNT_MAX=6};
enum{PARAMETER_COUNT_MAX=1};
enum{METHOD_COUNT_MAX=1};

extern ConstantString device_name;

extern ConstantString firmware_name;
extern const modular_server::FirmwareInfo firmware_info;

extern const uint32_t flipper_channels;
extern const ConstantString * const polarity_up_ptr;
extern const ConstantString * const polarity_down_ptr;

// Units

// Fields
// Field values must be long, double, bool, long[], double[], bool[], char[], ConstantString *
extern ConstantString flipper_delay_field_name;
extern const long flipper_delay_min;
extern const long flipper_delay_max;
extern const long flipper_delay_default;

extern ConstantString flipper_period_field_name;
extern const long flipper_period_min;
extern const long flipper_period_max;
extern const long flipper_period_default;

extern ConstantString flipper_on_duration_field_name;
extern const long flipper_on_duration_min;
extern const long flipper_on_duration_max;
extern const long flipper_on_duration_default;

extern ConstantString rung_up_count_lower_field_name;
extern const long rung_count_min;
extern const long rung_count_max;
extern const long rung_up_count_lower_default;

extern ConstantString rung_up_count_upper_field_name;
extern const long rung_up_count_upper_default;

extern ConstantString rung_down_count_field_name;
extern const long rung_down_count_default;

// Parameters

// Methods

// Errors
}
}
#include "5x3.h"
#include "3x2.h"
#endif
