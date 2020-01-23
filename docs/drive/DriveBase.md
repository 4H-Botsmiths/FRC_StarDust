# DriveBase

```cpp
#include "StarDust/drive/DriveBase.hpp"
```

`DriveBase` is the base class for all derived driving classes.

On its own, a `DriveBase` object does not drive.

## Initialization

#### `DriveBase()`

Construct a `DriveBase` with default (1.0x) multipliers in the `x`, `y`, and `z` direction.

#### `DriveBase(float x, float y, float rot)`

Construct a `DriveBase` with custom multipliers in the `x`, `y`, and `z` direction.

## RobotFunction

Since `DriveBase` is a base class, it does not implement any robot functions.

## Functions

#### `void Drive(float y)`

Drive forwards at `y` speed.

#### `void Drive(float y, float rot)`

Drive forwards at `y` speed while rotating at `rot` speed.

#### `void Drive(float x, float y, float rot)`

Drive forwards at `y` speed while rotating at `rot` speed and strafing at `x` speed.

#### `void Drive(BetterController* controller)`

Drive based off input from controller.

#### `float getx()`

Return `x` multiplier.

#### `float gety()`

Return `y` multiplier.

#### `float getr()`

Return `rot` multiplier.
