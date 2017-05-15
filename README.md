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

## Devices

[modular_device_base](https://github.com/janelia-modular-devices/modular_device_base.git)

[h_bridge_controller](https://github.com/janelia-modular-devices/h_bridge_controller.git)

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
      "flip",
      "enableFlip",
      "disableFlip"
    ]
  }
}
```

## API Verbose

```json
{
  "id":"getApiVerbose",
  "result":{
    "firmware":["RungWheelController"],
    "functions":[
      {
        "name":"flipEnabled",
        "parameters":[],
        "result_info":{
          "type":"bool"
        }
      }
    ],
    "parameters":[],
    "properties":[
      {
        "name":"flipperDelay",
        "type":"long",
        "units":"ms",
        "functions":[
          "getValue",
          "setValue",
          "getDefaultValue",
          "setValueToDefault"
        ],
        "parameters":[
          "value"
        ]
      },
      {
        "name":"flipperPeriod",
        "type":"long",
        "units":"ms",
        "functions":[
          "getValue",
          "setValue",
          "getDefaultValue",
          "setValueToDefault"
        ],
        "parameters":[
          "value"
        ]
      },
      {
        "name":"flipperOnDuration",
        "type":"long",
        "units":"ms",
        "functions":[
          "getValue",
          "setValue",
          "getDefaultValue",
          "setValueToDefault"
        ],
        "parameters":[
          "value"
        ]
      },
      {
        "name":"rungUpCountLower",
        "type":"long",
        "functions":[
          "getValue",
          "setValue",
          "getDefaultValue",
          "setValueToDefault"
        ],
        "parameters":[
          "value"
        ]
      },
      {
        "name":"rungUpCountUpper",
        "type":"long",
        "functions":[
          "getValue",
          "setValue",
          "getDefaultValue",
          "setValueToDefault"
        ],
        "parameters":[
          "value"
        ]
      },
      {
        "name":"rungDownCount",
        "type":"long",
        "functions":[
          "getValue",
          "setValue",
          "getDefaultValue",
          "setValueToDefault"
        ],
        "parameters":[
          "value"
        ]
      }
    ],
    "callbacks":[
      {
        "name":"flip",
        "properties":[
          "rungUpCountLower",
          "rungUpCountUpper",
          "rungDownCount"
        ],
        "functions":[
          "trigger",
          "attachTo",
          "detachFrom",
          "detachFromAll"
        ],
        "parameters":[
          "interrupt",
          "mode"
        ]
      },
      {
        "name":"enableFlip",
        "properties":[],
        "functions":[
          "trigger",
          "attachTo",
          "detachFrom",
          "detachFromAll"
        ],
        "parameters":[
          "interrupt",
          "mode"
        ]
      },
      {
        "name":"disableFlip",
        "properties":[],
        "functions":[
          "trigger",
          "attachTo",
          "detachFrom",
          "detachFromAll"
        ],
        "parameters":[
          "interrupt",
          "mode"
        ]
      }
    ]
  }
}
```

## More Detailed Modular Device Information

[modular-devices](https://github.com/janelia-modular-devices/modular-devices)

## Install Library Dependencies

[arduino-libraries](https://github.com/janelia-arduino/arduino-libraries)
