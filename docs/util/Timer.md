# Timer

```cpp
#include "StarDust/util/Timer.hpp"
```

`Timer` is a timer class to reduce boiler-plate timer code.

`Timer` is not a `StarDustComponent`, it does not have any robot functions.

## Initialization

#### `Timer(const double time)`

Creates a timer that just counts time.

Must manually start/stop.

#### `Timer(const std::function<void()> func, const double time)`

Make a timer that runs a function `func` for `time` seconds.

Must manually call start/stop.

#### `Timer(const bool autoRun, const std::function<void()> func, const double time)`

Make a timer that runs a function `func` for `time` seconds.

Auto runs if `autoRun` is true.

## Functions

#### `bool HasPeriodPassed(const double time)`

Returns true if the timer has ran for longer then `time` seconds.

Timer automatically stops if the time has expired.

#### `void Start()`

Resets and starts the timer.