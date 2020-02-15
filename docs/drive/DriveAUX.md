# DriveAUX

```cpp
#include "StarDust/drive/DriveAUX.hpp"
```

`DriveAUX` is an auxiliary class that combines a `Gyro` with a `DriveBase`.

## Initialization

All `DriveAux` objects need a threshold (minimum amount to move the drivetrain) and a gyro:

#### `DriveAUX(DriveBase driveBase, Gyro gyro, double threshold)`

Creates a `DriveAUX` object with a gyro and a threshold.

## RobotFunctions

None.

## Functions

#### `void GyroRotateToZero(double range)`

Rotate the robot towards 0 degrees +/- `range` degrees.

#### `void GyroRotateTo(double degree, double range)`

Rotoate the robot towards `degree` degrees +/- `range` degrees.

#### `void GyroRotateTo(double degree, double range, double y_mult)`

Rotoate the robot towards `degree` degrees +/- `range` degrees while moving at `y_mult` speed forward.

#### `void DriveAUX::drive(double x, double y, double z, double deg)`

Drive the robot with given `x`, `y`, `z` multipliers relative to the driver.

This requires the degree of the gyro to be fed in as the `deg` parameter.