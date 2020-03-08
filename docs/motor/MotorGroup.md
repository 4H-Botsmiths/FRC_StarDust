# MotorGroup

```cpp
#include "StarDust/motor/MotorGroup.hpp"
```

## Initialization

#### `MotorGroup(const std::vector<Motor*> motors)`

Create a motor group.

## Functions

#### `void Set(const double input)`

Sets motor speed to `input`.

#### `void Set(const double speed, const double time)`

Sets motor speed to `input` for `time` seconds. By default, will stop when done.