# StarDustComponent

StarDust components are the building blocks of the StarDust framework. They allow for an easy to use and debug environment.

## Initialization

This class cannot be initialized, it must be extended. For example:

In the `control/BetterController.hpp` file, the `BetterController` class extends `StarDustComponent`:

```cpp
class BetterController : public StarDustComponent, public frc::XboxController { //...
```

This means that the `BetterController` class is a `StarDustComponent`, and can be passed into a `StarDustRobot`.

## Functions

#### `virtual void __RobotInit__()=0;`
#### `virtual void __RobotPeriodic__()=0;`
#### `virtual void __AutonomousInit__()=0;`
#### `virtual void __AutonomousPeriodic__()=0;`
#### `virtual void __TeleopInit__()=0;`
#### `virtual void __TeleopPeriodic__()=0;`
#### `virtual void __TestPeriodic__()=0;`

These functions are what a `StarDustComponent` can hook into, allowing for their code to be automatically ran by the `StarDustRobot`

#### `void provideContext(StarDustRobot* r);`

This function allows for a `StarDustRobot` to pass itself into a `StarDustComponent`, allowing for the component to have access to robot-specific variables.

## Variables

#### `std::string __status__="";`

A `StarDustComponent` can set this status flag to whatever they want. Mainly for debugging and testing.

#### `StarDustRobot* __robot__;`

This stores the `StarDustRobot` instance passed in from the `provideContext()` function.