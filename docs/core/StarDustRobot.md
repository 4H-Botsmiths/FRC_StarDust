# StarDustRobot

```cpp
#include "StarDust/core/StarDustRobot.hpp"
```

`StarDustRobot` is the brains of the StarDust framework.

It takes in all available `StarDustComponent`s, and automatically runs code among other things.

## Initialization

For a `StarDustRobot` to be useful, components related to the robot must be passed to it.

#### `StarDustRobot(std::vector<StarDustComponent*> cs)`

This step is pretty easy. Simply create a new robot, passing in all known `StarDustComponents`:

```cpp
//example includes
BetterController xbox_left { 0 };
BetterController xbox_right { 1 };

StarDustRobot NAME {{
    &xbox_left,
    &xbox_right
}}
```

Here, a new `StarDustRobot` named NAME is created, which contains 2 `BetterController` compoents.

## Functions

#### `void RobotInit();`
#### `void RobotPeriodic();`
#### `void AutonomousInit();`
#### `void AutonomousPeriodic();`
#### `void TeleopInit();`
#### `void TeleopPeriodic();`
#### `void TestPeriodic();`

The main functions of the `StarDustRobot` class are very similar.

Each of the above functions will automatically run `StarDustComponent` code based off of the function called.

For example, running `TeleopInit()` is the same as running `__TeleopInit__()` on all of the passed in `StarDustComponents`s.

## Variables

#### `bool isIdle=true;`

`isIdle` is true when the robot has not started teleop or autonomous, but false when it has.

This is due to `RobotPeriodic()` being called even in teleop and auto.

This variable is useful for when wanting to run something only while idle is desired.

#### `std::vector<StarDustComponent*> components;`

`components` is an vector of all of the passed in `StarDustComponents`