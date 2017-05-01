# RungWheelController

Authors:

    Peter Polidoro <polidorop@janelia.hhmi.org>

License:

    BSD

## Inherits

[ModularServer](https://github.com/janelia-arduino/ModularServer)

[ModularDeviceBase](https://github.com/janelia-arduino/ModularDeviceBase)

[HBridgeController](https://github.com/janelia-arduino/HBridgeController)

## API

```json
{
  "id":"getApi",
  "result":{
    "firmware":["RungWheelController"],
    "functions":[
      "flipEnabled"
    ],
    "parameters":[],
    "properties":[
      "flipperDelay",
      "flipperPeriod",
      "flipperOnDuration",
      "rungUpCountLower",
      "rungUpCountUpper",
      "rungDownCount"
    ],
    "callbacks":[
      "flip"
    ]
  }
}
```

## More Detailed Modular Device Information

[modular-devices](https://github.com/janelia-modular-devices/modular-devices)

## Install Library Dependencies

[arduino-libraries](https://github.com/janelia-arduino/arduino-libraries)
