# Gyro

```cpp
#include "StarDust/motion/Gyro.hpp"
```

Wrapper class for the `ADXRS450` Gyro.

Provides helper functions related to angle calculations.

## Initialization

#### `Gyro() : frc::ADXRS450_Gyro() {}`

Creates the gyro object (on SPI port 0).

## RobotFunctions

```
//reset gyro
RobotInit

//calibrate gyro during pre-match
RobotPeriodic

//updates gyro angle internally
AutonomousInit
AutonomousPeriodic
TeleopInit
TeleopPeriodic
TestPeriodic
```

## Functions

#### `double GetAngle()`

Returns the internally cached value of the gyro in degrees.

#### `double GetAngleMod()`

Returns `GetAngle()` but capped at +/- 360 degrees.

#### `double GetAngleMod(double deg)`

Returns `GetAngle()` but capped at +/- `deg` degrees.

#### `double FastestToZero()`

Returns the fastest angle towards zero.

#### `double FastestTo(double deg)`

Returns the fastest angle towards `deg`.