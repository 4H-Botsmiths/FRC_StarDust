# DriveAUX

```cpp
#include "StarDust/drive/DriveAUX.hpp"
```

`DriveAUX` is an auxiliary class that combines a `Gyro` with a `DriveBase`.

## Initialization

All `DriveAux` objects need a threshold (minimum amount to move the drivetrain) and a gyro:

#### `DriveAUX(DriveBase* driveBase, Gyro_Base* gyro, double threshold)`

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

#### `void GyroRotateTo(double degree, double range, double x_mult double y_mult)`

Rotoate the robot towards `degree` degrees +/- `range` degrees while moving at `x_mult` left/right, and `y_mult` speed forwards/backwards.

#### `void driveGyro(double degree, double range, XboxController* controller)`

Stay within +/- `range` degrees from `degree`, drive with player relative controls from the gyro.

#### `void driveGyro(double degree, double range, double x_mult, double y_mult)`

Move at `x_mult` speed left/right, `y_mult` speed forwards/backwards, and stay within +/- `range` degrees from `degree`.

#### `void DriveAUX::drive(XboxController* controller)`

Run below function with input from controller.

#### `void DriveAUX::drive(double x, double y, double z)`

Drive the robot with given `x`, `y`, `z` multipliers relative to degree of current rotation of gyro.

#### `void DriveAUX::drive(double x, double y, double z, double deg)`

Drive the robot with given `x`, `y`, `z` multipliers relative to degree `deg`.