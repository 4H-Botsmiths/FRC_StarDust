# DriveBasic

```cpp
#include "StarDust/drive/DriveBasic.hpp"
```

`DriveBasic` is a basic 2 motor "arcade" drive train.

## Initialization

All `DriveBasic` constructors takes 2 motors, `0` being left and `1` being right.

#### `DriveBasic(frc::SpeedController* motor_0, frc::SpeedController* motor_1)`

Creates a `DriveBasic` drivetrain with default (1.0x) multipliers.

#### `DriveBasic(frc::SpeedController* motor_0, frc::SpeedController* motor_1, float y_mult, float rotation_mult)`

Creates a `DriveBasic` drivetrain with custom multipliers.

## RobotFunctions

Currently there is no interaction with robot functions.

## Functions

#### `void drive(float y)`

Drive forwards at `y` speed.

#### `void drive(float y, float rot)`

Drive fowrards at `y` speed while rotating at `rot` speed.

#### `void drive(float y, float rot, float timer)`

Drive fowrards at `y` speed while rotating at `rot` speed for `time` seconds.

#### `void drive(BetterController* controller)`

Drive using inputs from controller directly, uses default mode (`0`).

#### `void drive(BetterController* controller, int mode)`

Drive using inputs from controller directly, use differnet mode.

Modes are as followed:

| Mode | Forwards | Turning |
|:----:|:-------- |:------- |
| 0    | LeftStickForward | RightStickLeftRight |
| 1    | LeftStickForward | LeftStickLeftRight |
| 2    | RightStickForward | RightStickLeftRight |
