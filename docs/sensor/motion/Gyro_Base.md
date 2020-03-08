# Gyro_Base

```cpp
#include "StarDust/motion/Gyro_Base.hpp"
```

Extends the default gyro base for use in StarDust.

## Initialization

#### `Gyro_Base(frc::Gyro* const gyro)`

Create gyro base from existing `frc::Gyro`.

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

#### `double GetAngle() const`

Returns the internally cached value of the gyro in degrees.

#### `double GetAngleMod() const`

Returns `GetAngle()` but capped at +/- 360 degrees.

#### `double GetAngleMod(const double deg) const`

Returns `GetAngle()` but capped at +/- `deg` degrees.

#### `double FastestToZero() const`

Returns the fastest angle towards zero.

#### `double FastestTo(const double deg) const`

Returns the fastest angle towards `deg`.