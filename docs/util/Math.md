# Math

```cpp
#include "StarDust/util/Math.hpp"
```

`Math` wraps certain functions from `<cmath>` to make them more readable.

`Math` is not a `StarDustComponent`, it does not have any robot functions.

## Functions

#### `double signedAdd(const double value, const double delta)`

Adds delta to value if positive.

Subtracts delta from value if negative.

#### `double signiness(const double value)`

Returns -1 if value is negative, 1 if value is positive.

#### `double updateSign(double& const value, double const sign)`

Sets value to the signiness of "sign".