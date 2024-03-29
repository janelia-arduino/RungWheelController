// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#ifndef RUNG_WHEEL_CONTROLLER_CONSTANTS_H
#define RUNG_WHEEL_CONTROLLER_CONSTANTS_H
#include <ConstantVariable.h>
#include <HBridgeController.h>


namespace rung_wheel_controller
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{PROPERTY_COUNT_MAX=6};
enum{PARAMETER_COUNT_MAX=1};
enum{FUNCTION_COUNT_MAX=2};
enum{CALLBACK_COUNT_MAX=3};

extern ConstantString device_name;

extern ConstantString firmware_name;
extern const modular_server::FirmwareInfo firmware_info;

extern const uint32_t flipper_channels;
extern const ConstantString * const polarity_up_ptr;
extern const ConstantString * const polarity_down_ptr;

extern const size_t optical_switch_interface_address[1];

extern const size_t encoder_interface_simple_address[2];

// Pins

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]
extern ConstantString flipper_delay_property_name;
extern const long flipper_delay_min;
extern const long flipper_delay_max;
extern const long flipper_delay_default;

extern ConstantString flipper_period_property_name;
extern const long flipper_period_min;
extern const long flipper_period_max;
extern const long flipper_period_default;

extern ConstantString flipper_on_duration_property_name;
extern const long flipper_on_duration_min;
extern const long flipper_on_duration_max;
extern const long flipper_on_duration_default;

extern ConstantString rung_up_count_lower_property_name;
extern const long rung_count_min;
extern const long rung_count_max;
extern const long rung_up_count_lower_default;

extern ConstantString rung_up_count_upper_property_name;
extern const long rung_up_count_upper_default;

extern ConstantString rung_down_count_property_name;
extern const long rung_down_count_default;

// Parameters

// Functions
extern ConstantString set_client_property_values_function_name;
extern ConstantString flip_enabled_function_name;

// Callbacks
extern ConstantString flip_callback_name;

extern ConstantString enable_flip_callback_name;

extern ConstantString disable_flip_callback_name;

// Errors
}
}
#include "5x3.h"
#include "3x2.h"
#endif
