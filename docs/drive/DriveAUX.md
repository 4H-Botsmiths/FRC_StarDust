# DriveAUX

```cpp
#include "StarDust/drive/DriveAUX.hpp"
```

`DriveAUX` is an auxiliary class that combines a `BetterGyro` with a `DriveBase`.

## Initialization

All `DriveAux` objects need a threshold (minimum amount to move the drivetrain):

#### `DriveAUX(DriveBase* driveBase, double threshold)`

Creates a `DriveAUX` object with no gyro, and a threshold.

#### `DriveAUX(DriveBase* driveBase, BetterGyro* gyro, double threshold)`

Creates a `DriveAUX` object with a gyro and a threshold.

## RobotFunctions

Currently there is no interaction with `DriveAUX` and robot functions.

## Functions

#### `void GyroRotate(double range)`

Rotate the robot towards 0 degrees +/- `range` degrees.

#### `void GyroRotateTo(double degree, double range)`

Rotoate the robot towards `degree` degrees +/- `range` degrees.

#### `void GyroRotateTo(double degree, double range, double y_mult)`

Rotoate the robot towards `degree` degrees +/- `range` degrees while moving at `y_mult` speed forward.
