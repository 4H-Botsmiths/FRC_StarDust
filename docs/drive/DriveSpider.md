# DriveSpider

```cpp
#include "StarDust/drive/DriveSpider"
```

`DriveSpider` is a mecanum and classic arcade drive hybrid drivetrain.

Switches between the 2 modes using pneumatic solenoids.

Refer to the [DriveMecanum](/docs/drive/DriveMecanum.md) docs for wiring instructions.

## Initialization

#### `DriveSpider(frc::SpeedController* motor_0, frc::SpeedController* motor_1, frc::SpeedController* motor_2, frc::SpeedController* motor_3, BetterDoubleSolenoid* solenoid)`

Creates a `DriveSpider` object with default (1.0x) multipliers.

#### `DriveSpider(frc::SpeedController* motor_0, frc::SpeedController* motor_1, frc::SpeedController* motor_2, frc::SpeedController* motor_3, BetterDoubleSolenoid* solenoid, float x_mult, float y_mult, float rotation_mult)`

Creates a `DriveSpider` object with custom multipliers.

## RobotFunctions

Currently there is no interaction with robot functions.

## Functions

In each of the drive functions, the robot may drive differently when in different modes.

When not in mecanum drive, the `x` axis is set to `0` as normal wheels cannot strafe.

#### `void drive(BetterController* controller)`

Drive with inputs from controller.

#### `void drive(float x, float y, float rot)`

Drive forwards at `y` speed while turning at `rot` speed and strafing at `x` speed.

#### `void drive(float x, float y, float rot, float time)`

Drive forwards at `y` speed while turning at `rot` speed and strafing at `x` speed for `time` seconds.

#### `void invert()`

Swaps whether the robot is in normal or mecanum mode.

Also inverts the state of the solenoid.

#### `void useMecanum()`

Enables the solenoid so that the mecanum wheels are in use.

#### `void useNormal()`

Enables the solenoid so that the normal wheels are in use.
