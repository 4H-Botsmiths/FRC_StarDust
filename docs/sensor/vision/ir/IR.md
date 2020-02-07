# IR

```cpp
#include "StarDust/sensor/vision/ir/IR.hpp"
```

Wrapper class for an analog IR device.

## Initialization

#### `IR(int port)`

Creates an IR device on port `port`.

## RobotFunctions

Currently there are no interactions with robot functions.

## Functions

#### `double getV()`

Returns sensor voltage.

#### `double getVV()`

Returns sensor value.

#### `double getAV()`

Returns average voltage.