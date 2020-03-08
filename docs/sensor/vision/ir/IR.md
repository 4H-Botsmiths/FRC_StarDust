# IR

```cpp
#include "StarDust/sensor/vision/ir/IR.hpp"
```

Wrapper class for an analog IR device.

## Initialization

#### `IR(int port)`

Creates an IR device on port `port`.

## RobotFunctions

None.

## Functions

#### `double getV() const`

Returns sensor voltage.

#### `double getVV() const`

Returns sensor value.

#### `double getAV() const`

Returns average voltage.