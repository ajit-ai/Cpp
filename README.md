# C++ Examples

A feature-wise C++ learning repository. Each example is a self-contained
program demonstrating one topic; unit tests live under `tests/`.
See [PLAN.md](PLAN.md) for the full roadmap.

## Layout

```
basic/       starter programs (types, variables, strings)
features/    topic examples grouped by C++ area
  control_flow/  functions/
  oop/           stl/
  modern/        (smart pointers, lambdas, move semantics...)
include/     small utility headers used by tests
tests/       header-only mini framework + unit tests
```

## Build & Run (Windows, g++)

Requires g++ (MSYS2/MinGW-w64). Everything builds into `build/bin/`.

```powershell
.\build.ps1            # compiles all examples + runs unit tests
```

Run any single example:

```powershell
.\build\bin\control_flow.exe
```

## Build & Run (CMake)

```powershell
cmake -S . -B build-cmake
cmake --build build-cmake
ctest --test-dir build-cmake
```

## Tests

Unit tests use a tiny dependency-free framework in
`tests/test_framework.hpp`. Add a new test by writing:

```cpp
#include "test_framework.hpp"

TEST(MySuite, my_case) {
    CHECK(utils::add(1, 2) == 3);
}
```

Then rebuild with `.\build.ps1`.
