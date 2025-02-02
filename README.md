# Logger

## Description

The **Logger** is a C++ class for managing and logging messages with different priority levels. It supports multithreading by using **std::mutex** to prevent race conditions during writing.

## Features

- **Priority filtering:** Allows setting a minimum priority to display only relevant messages.
- **ANSI colors:** Messages are printed in different colors for better readability.
- **Variadic template support:** Enables logging multiple arguments in a single log entry.
- **Thread-safe:** Uses `std::mutex` to ensure safety in multithreaded environments.

## Priority Levels

The logger supports the following priority levels:

| Level   | ANSI Code  | Description                                          |
| ------- | ---------- | ---------------------------------------------------- |
| TRACE   | \033[1;36m | Detailed messages for deep debugging                 |
| DEBUG   | \033[0;35m | Useful debugging information                         |
| INFO    | \033[0;32m | General program state information                    |
| WARNING | \033[0;33m | Warnings that may indicate a problem                 |
| ERROR   | \033[0;31m | Errors that do not stop execution but need attention |
| FATAL   | \033[1;31m | Critical errors that may cause program termination   |

## Usage

### Initialization

Since the logger uses static members, there is no need to instantiate it:

```cpp
#include "logger.hpp"

int main() {
    // Set the minimum log level to WARNING
    Logger::setLowerBoundPriority(warningPriority);
    
    Logger::trace("This message will not be printed");
    Logger::debug("This message will not be printed");
    Logger::info("This message will not be printed");
    Logger::warning("Warning!", 42);
    Logger::error("Error detected", "Code", 500);
    Logger::fatal("Fatal error!");

    return 0;
}
