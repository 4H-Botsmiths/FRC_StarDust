# DriveBase

```cpp
#include "StarDust/drive/DriveBase.hpp"
```

`DriveBase` is the base class for all derived driving classes.

On its own, a `DriveBase` object does not drive.

## Initialization

#### `DriveBase()`

Construct a `DriveBase` with default (1.0x) multipliers in the `x`, `y`, and `z` direction.

#### `DriveBase(double x, double y, double rot)`

Construct a `DriveBase` with custom multipliers in the `x`, `y`, and `z` direction.

## RobotFunction

Since `DriveBase` is a base class, it does not implement any robot functions.

## Functions

#### `void Drive(double y)`

Drive forwards at `y` speed.

#### `void Drive(double y, double rot)`

Drive forwards at `y` speed while rotating at `rot` speed.

#### `void Drive(double x, double y, double rot)`

Drive forwards at `y` speed while rotating at `rot` speed and strafing at `x` speed.

#### `void Drive(BetterController* controller)`

Drive based off input from controller.

#### `double getx()`

Return `x` multiplier.

#### `double gety()`

Return `y` multiplier.

#### `double getr()`

Return `rot` multiplier.
