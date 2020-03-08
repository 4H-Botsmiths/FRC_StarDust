# Motor

```cpp
#include "StarDust/motor/Motor.hpp"
```

`Motor` is a wrapper class for `PWMSpeedController`.

It allows for easy dampening and inversion of motor controllers.

## Initialization

#### `Motor(int port)`

Creates a motor attached to PWM port `port`

#### `Motor(int port, const bool invert)`

Creates a motor attached to PWM port `port`, invert based on `invert`.

#### `Motor(int port, const double dampen, const bool invert)`

Creates a motor attached to PWM port `port`, invert based on `invert`. Dampen imputs by `damp` amount.

## Functions

#### `void Set(const double input)`

Sets motor speed to `input` with `dampen` amount applied.

#### `void Set(const double speed, const double time)`

Sets motor speed to `input` with `dampen` amount applied for `time` seconds. By default, will stop when done.

> This function is blocking! It will run until it time has expired.

> Use `AsyncSet` below for non-blocking version.

#### `void Set(const double speed, const double time, const bool brake)`

Sets motor speed to `input` with `dampen` amount applied for `time` seconds. Brakes if `brake` is set.

> This function is blocking! It will run until it time has expired.

> Use `AsyncSet` below for non-blocking version.

#### `void AsyncSet(const double speed, const double time)`

Set motor to speed `speed` for `time` seconds. Does not block execution.

## RobotFunctions

```
//These functions will run update a motor that has been called with AsyncSet()
__AutonomousInit__
__AutonomousPeriodic__
__TeleopInit__
__TeleopPeriodic__
__TestPeriodic__
```