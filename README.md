# RungWheelController

Authors:

    Peter Polidoro <polidorop@janelia.hhmi.org>

License:

    BSD

## Ancestors

[ModularServer](https://github.com/janelia-arduino/ModularServer)

[ModularDeviceBase](https://github.com/janelia-arduino/ModularDeviceBase)

[HBridgeController](https://github.com/janelia-arduino/HBridgeController)

## Clients

[OpticalSwitchInterface](https://github.com/janelia-arduino/OpticalSwitchInterface)

[EncoderInterfaceSimple](https://github.com/janelia-arduino/EncoderInterfaceSimple)

## Devices

[modular_device_base](https://github.com/janelia-modular-devices/modular_device_base.git)

[h_bridge_controller](https://github.com/janelia-modular-devices/h_bridge_controller.git)

[optical_switch_interface](https://github.com/janelia-modular-devices/optical_switch_interface.git)

[encoder_interface_simple](https://github.com/janelia-modular-devices/encoder_interface_simple.git)

## API NAMES

```json
{
  "id":"getApi",
  "result":{
    "firmware":["RungWheelController"],
    "verbosity":"NAMES",
    "functions":[
      "setClientPropertyValues",
      "flipEnabled"
    ],
    "properties":[
      "flipperDelay",
      "flipperPeriod",
      "flipperOnDuration",
      "rungUpCountLower",
      "rungUpCountUpper",
      "rungDownCount"
    ],
    "callbacks":[
      "flip",
      "enableFlip",
      "disableFlip"
    ]
  }
}
```

## API GENERAL

[API GENERAL](./api/)

## More Detailed Modular Device Information

[modular-devices](https://github.com/janelia-modular-devices/modular-devices)

## Install Library Dependencies

[arduino-libraries](https://github.com/janelia-arduino/arduino-libraries)
