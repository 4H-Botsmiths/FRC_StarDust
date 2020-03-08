# CSVLogger

```cpp
#include "StarDust/loggin/CSVLogger.hpp"
```

`CSVLogger` is used for logging data to a CSV file when debugging.

## Initialization

#### `CSVLogger()`

Creates a header-less logger that writes to `/home/lvuser/data.csv`

#### `CSVLogger(const std::string header)`

Creates a logger with custom header that writes to `/home/lvuser/data.csv`

#### `CSVLogger(const std::string filename, const std::string header)`

Creates a logger with custom header that writes to `filename`

## RobotFunctions

None.

## Functions

#### `void push(const T data, const Ts... args)`

Push many items to the CSV file. Example:

```cpp
CSVLogger csv { "name,age" };

csv.push("bob", 123);
```

#### `void push(const T data)`

Push a single item to CSV file.

#### `void start()`

Clears out old file, allows for pushing data. Called automatically when a `CSVLogger` is created.

#### `void stop()`

Closes the CSV file.