Comunication via Json

```c++
#define cmdTopic "home/lighting/bedroom/UnderBedLight/cmd"
#define stateTopic "home/lighting/bedroom/UnderBedLight/state"
```

Json sample
```Json
{
  "brightness": 255,
  "red": 255,
  "green": 255,
  "blue": 255,
  "state": true
}
```

This is a working example for the configguration in HomeAssistant
```c++
light:
  - platform: mqtt
    name: "UnderBedLight"
    command_topic: "bedroom/UnderBedLight/light/set"
    brightness_command_topic: "bedroom/UnderBedLight/brightness/set"
    rgb_command_topic: "bedroom/UnderBedLight/rgb/set"
    state_topic: "bedroom/UnderBedLight/light/status"
    brightness_state_topic: "bedroom/UnderBedLight/brightness/status"
    rgb_state_topic: "bedroom/UnderBedLight/rgb/status"
    payload_on: "ON"
    payload_off: "OFF"
    optimistic: false
```