# DoubleSolenoid

```cpp
#include "StarDust/pneumatics/DoubleSolenoid.hpp"
```

`DoubleSolenoid` is a wrapper class that provides more expressive commands and built-in functions.

# Initialization

#### `DoubleSolenoid(int port1, int port2)`

Setup a solenoid wired to ports `port1` and `port2` on the PCM.

#### `DoubleSolenoid(int port1, int port2, bool invert)`

Setup a solenoid wired to ports `port1` and `port2` on the PCM. Invert based on if `invert` is true.

## RobotFunctions

None.

## Functions

#### `void Extend()`

Extend the piston.

#### `void Retract()`

Retract the piston.

#### `void Off()`

Turn off the solenoid valves.

#### `void Invert()`

Switch from extended to retracted, and vice versa.
