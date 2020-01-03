# BetterController

```cpp
#include "StarDust/control/BetterController.hpp"
```

`BetterController` is a wrapper class for `frc::XboxController`.

Most, but not all of the functions defined in the `XboxController` class are listed here.

Only functions which change/overload the old class, or are new to the `BetterController` class are documented.

## Initialization:

The `BetterController` class offers much more expansion and reliablility compared to the original `XboxController` class.

One vital feature all teams need is a deadzone for joysticks. This prevents slight, unwanted movement of the drivetrain.

On top of this, `BetterController` offers built-in lambda bindings to automatically run functions based on certain button events.

All parameters are set to `0` by default, and `binds` is `NULL`

#### `BetterController(int n) : frc::XboxController(n) {}`

Like the `XboxController` class, the most common use case is passing only the USB port number:

```cpp
BetterController xbox_left { 0 };
```

#### `BetterController(int n, double s) : frc::XboxController(n), stickDeadzone(s), triggerDeadzone(s) {}`

In addition, joystick deadzone can be specified upon creation:

```cpp
BetterController xbox_left { 0, 0.15 };
```

#### `BetterController(int n, double s, double t) : frc::XboxController(n), stickDeadzone(s), triggerDeadzone(t) {}`

Not only the joysticks, but the left and right triggers can get a deadzone as well:


```cpp
BetterController xbox_left { 0, 0.15, 0.05 };
```

#### `BetterController(int n, double s, double t, std::map<int, std::function<void()>> b) : frc::XboxController(n), stickDeadzone(s), triggerDeadzone(t), binds(b) {}`

This is a more complex yet great addition. This initialization requires the same paramaters as before, but takes in a map of functions bound to events:

```cpp
BetterController xbox_left { 0, 0.15, 0.05, {
    {BetterController::on::AButtonPressed, [=](){
        std::cout << "A Button Was Pressed!\n";
    }},
    {BetterController::on::XButton, [=](){
        std::cout << "X Button Is Being Pressed!\n";
    }}
}};
```

After the first 3 parameters, add a `{}`. Inside, add `int`s and `function` wrapped in `{}`s.

When the component is ran by the `StarDustRobot`, the given lambda on the right is ran if the even on the left is true.

A full list of bindable events for this class can be seen below in the "Events" section.

## RobotFunctions

Below is a list of what this component does during each of the `__robot__` functions.

```
//clears the internal cache, read the about the clearCache() function for more inforamtion
__RobotPeriodic__()

//below functions auto update and auto run the binds (if passed)
//read about the updateBoth() and autorun() functions for more info
__RobotInit__()
__AutonomousInit__()
__AutonomousPeriodic__()
__TeleopInit__()
__TeleopPeriodic__()
__TestPeriodic__()
```

## Functions

#### `void autorun();`

The `autorun()` function will automatically check and run the binds passed in upon initialization (if any).

A bind consists of an event, and a function. Both of the below conditions must be true for the function to run:

* Event is valid (defined in `on::` object)
* Function associated with event was triggered (if `on::AButton` was passed, `AButton()` must also return true)

If multiple binds with the same event was passed in, the bind most recently added will be ran.

#### `void updatePressed();`

This will update the internal state of the pressed button states.

#### `void updatReleased();`

This will update the internal state of the released button states.

#### `void updateBoth();`

The `updateBoth()` function will update the pressed button states, and the released button states.

#### `void clearCache();`

This function will update 2 times, effectively clearing the cache when input is not required/desired.

## Repeated Joystick/Trigger Functions

Below is a list of functions that have similar names, but do the same action.

Where you see `"X"`, it can be replace with `"Y"`.

Where You see `"Left"`, it can be replaced with `"Right"`. It may also be prefixed with `"Trigger"`, for example:

`double GetRightTrigger();`

#### `double GetXLeft();`

This is shorthand for `GetX(frc::GenericHID::JoystickHand::kLeft)` from the `XboxController` class.

#### `double GetXLeftDeadzone();`

This returns `GetXLeft()` With passed in deadzone applied.

#### `double GetXLeftDeadzone(double d);`

This returns `GetXLeft()` with deadzone `d` applied.

## Repeated Button Functions

Below is a list of functions that have similar names, but to the same action.

Where you see `"AButton"`, it could be any of the following:

```
AButton
BButton
XButton
YButton
StartButton
BackButton
LeftBumper
RightBumper
LeftStickButton
RightStickButton
```

#### `bool GetAButtonPressed();`

This will return true if the A button is being pressed, and it was not pressed last time.

#### `bool GetAButtonReleased();`

This will return true if the A button is not being pressed, and it was pressed last time.

## Events

These are a list of the available events for the `BetterController` class:

```
AButton,
AButtonPressed,
AButtonReleased,
BButton,
BButtonPressed,
BButtonReleased,
XButton,
XButtonPressed,
XButtonReleased,
YButton,
YButtonPressed,
YButtonReleased,
StartButton,
StartButtonPressed,
StartButtonReleased,
BackButton,
BackButtonPressed,
BackButtonReleased,
LeftBumper,
LeftBumperPressed,
RightBumperPressed,
LeftBumperReleased,
RightBumperReleased,
LeftStickButtonPressed,
RightStickButtonPressed,
LeftStickButtonReleased,
RightStickButtonReleased
```
