# Math

```cpp
#include "StarDust/util/Math.hpp"
```

`Math` wraps certain functions from `<cmath>` to make them more readable.

`Math` is not a `StarDustComponent`, it does not have any robot functions.

## Functions

#### `double signedAdd(double value, double delta)`

Adds delta to value if positive.

Subtracts delta from value if negative.

#### `double signiness(double value)`

Returns -1 if value is negative, 1 if value is positive.

#### `double updateSign(double& value, double sign)`

Sets value to the signiness of "sign".