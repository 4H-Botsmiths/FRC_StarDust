# DriveMecanum

```cpp
#include "StarDust/drive/DriveMecanum.hpp"
```

`DriveMecanum` is a 4 motor mecanum drive train.

## Initialization

Wire your motors as such, or pass your motors in accordance with this wiring diagram:

```
        FRONT
      0 ----- 1
      |       |
LEFT  |       | RIGHT
      |       |
      3 ----- 2
        BACK
```

#### `DriveMecanum(frc::SpeedController* motor_0, frc::SpeedController* motor_1, frc::SpeedController* motor_2, frc::SpeedController* motor_3)`

Creates a `DriveMecanum` object with default (1.0x) multipliers.

#### `DriveMecanum(frc::SpeedController* motor_0, frc::SpeedController* motor_1, frc::SpeedController* motor_2, frc::SpeedController* motor_3, double x_mult, double y_mult, double rotation_mult)`

Creates a `DriveMecanum` object with custom multipliers.

## RobotFunctions

Currently there is no interaction with robot functions.

## Functions

#### `void drive(double y)`

Drive forwards at `y` speed.

#### `void drive(double y, double rot)`

Drive forwards at `y` speed while turning at `rot` speed.

#### `void drive(double x, double y, double rot)`

Drive forwards at `y` speed while turning at `rot` speed and strafing at `x` speed.

#### `void drive(double x, double y, double rot, double time)`

Drive forwards at `y` speed while turning at `rot` speed and strafing at `x` speed for `time` seconds.

#### `void drive(BetterController* controller)`

Drive with inputs from controller.
