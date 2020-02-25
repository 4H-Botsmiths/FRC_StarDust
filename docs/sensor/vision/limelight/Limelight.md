# Limelight

```cpp
#include "StarDust/sensor/vision/limelight/Limelight.hpp"
```

Wrapper class for the Limelight.

## Initialization

#### `Limelight()`

Creates the limelight.

## RobotFunctions

```
//update internal limelight values
RobotPeriodic
AutonomousInit
AutonomousPeriodic
TeleopInit
TeleopPeriodic
TestPeriodic
```

## Functions

#### `void turnLightsOff()`

Turn limelight lights off.

#### `void turnLightsOn()`

Turn limelight lights on.

#### `double get(std::string key)`

Get custom key from limelight.

#### `bool getTV()`

Returns `true` or `false` based on if there is a valid target.

#### `double getTX()`

Returns target x-offset.

#### `double getTY()`

Returns target Y-offset.

#### `double getTA()`

Returns target area.

#### `double getTS()`

Returns target skew (left or right, in degrees).