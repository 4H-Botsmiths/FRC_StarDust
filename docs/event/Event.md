# Event

```cpp
#include "StarDust/event/Event.hpp"
```

The `Event` class is an bare-bones event handling system.

## Initialization

#### `Event(const std::function<bool()> conditional, std::function<void()> action)`

Creates an event that runs `action()` when `conditional()` returns true.

#### `Event(const std::function<bool()> conditional, std::vector<std::function<void()>> actions)`

Creates an event that run all `action()`s inside `action()` when `conditional()` returns true.

## RobotFunctions

For each event for each robot function, `fire()` will be called.

## Functions

#### `void addAction(std::function<void()> action)`

Add the action to the vector of actions to run when an event is fired.

#### `void fire() const`

Fire the event, run all the actions for the event if `conditional()` returns true.