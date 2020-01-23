# BetterTimer

```cpp
#include "StarDust/util/BetterTimer.hpp"
```

`BetterTimer` is a timer class to reduce boiler-plate timer code.

`BetterTimer` is not a `StarDustComponent`, it does not have any robot functions.

## Initialization

#### `BetterTimer(double time)`

Creates a timer that just counts time.

Must manually start/stop.

#### `BetterTimer(std::function<void()> func, double time)`

Make a timer that runs a function `func` for `time` seconds.

Must manually call start/stop.

#### `BetterTimer(bool autoRun, std::function<void()> func, double time)`

Make a timer that runs a function `func` for `time` seconds.

Auto runs if `autoRun` is true.

#### `bool HasPeriodPassed(double time)`

Returns true if the timer has ran for longer then `time` seconds.

Timer automatically stops if the time has expired.

#### `void Start()`

Resets and starts the timer.