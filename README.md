# C++ Examples

A feature-wise C++ learning repository. Each example is a self-contained
program demonstrating one topic; unit tests live under `tests/`.
See [PLAN.md](PLAN.md) for the full roadmap and future ideas.

## Layout

```
basic/          starter programs (types, variables, strings)
features/       topic examples grouped by C++ area
  control_flow/   functions/
  oop/            stl/
  modern/
include/        small utility headers used by tests
tests/          header-only mini framework + unit tests
build.ps1       one-command build & test script (Windows/g++)
CMakeLists.txt  portable build definition
```

## Examples Catalog

| Path | Topics |
|---|---|
| `basic/Hello.cpp` | First program, `iostream` output |
| `basic/datatype/datatype.cpp` | Fundamental types and `sizeof` |
| `basic/datatype/stringdatatype.cpp` | Initialization styles, C-strings vs `std::string` |
| `basic/variabe/variabeexample.cpp` | Declaring and printing variables |
| `basic/variabe/floatex.cpp` | Type conversion basics |
| `features/control_flow/control_flow.cpp` | `if/else`, `switch`, loops, range-based `for`, `break`/`continue` |
| `features/functions/functions.cpp` | Overloading, default args, references vs pointers, templates, recursion, `constexpr` |
| `features/oop/classes_basics.cpp` | Encapsulation, constructors/destructor, static members, operator overloading, `friend` |
| `features/oop/inheritance_polymorphism.cpp` | Inheritance, `virtual`, abstract classes, runtime polymorphism, `dynamic_cast` |
| `features/stl/containers.cpp` | `vector`, `map`, `set`, `unordered_map`, `stack`, `queue` |
| `features/stl/algorithms.cpp` | `sort`, `find_if`, `count_if`, `accumulate`, `transform`, erase-remove idiom |
| `features/modern/smart_pointers.cpp` | RAII, `unique_ptr`, `shared_ptr`, `weak_ptr` |
| `features/modern/modern_features.cpp` | `auto`, lambdas, structured bindings, `std::optional`, move semantics, `string_view` |

## Requirements

- A C++20 compiler. Verified with **g++ 14.2 (MSYS2 UCRT64)**; any recent
  g++ or Clang works.
- Optional: CMake 3.15+ for the CMake build.

## Build & Run (Windows, g++)

Everything builds into `build/bin/`; unit tests run automatically at the end:

```powershell
.\build.ps1              # default is C++20
.\build.ps1 -Std c++17   # different standard if needed
```

Run any single example:

```powershell
.\build\bin\control_flow.exe
```

## Build & Run (CMake)

```powershell
cmake -S . -B build-cmake
cmake --build build-cmake
ctest --test-dir build-cmake --output-on-failure
```

## Tests

Unit tests use a tiny dependency-free framework in
`tests/test_framework.hpp`. Current suite: **12 tests, all passing**.

Add a new test by appending to any file in `tests/` (or creating a new one):

```cpp
#include "test_framework.hpp"

TEST(MySuite, my_case) {
    CHECK(utils::add(1, 2) == 3);
    CHECK_EQ(utils::toUpper("hi"), "HI");
}
```

Then rebuild with `.\build.ps1`. Note `tests/main.cpp` holds the single
`main()` that runs all registered tests — don't add another one.

### Assertions available

| Macro | Use for |
|---|---|
| `CHECK(cond)` | Boolean conditions |
| `CHECK_EQ(a, b)` | Equality (`a == b`) |
| `CHECK_NEAR(a, b, eps)` | Floating-point comparison |

## Adding a New Example

1. Create `features/<topic>/<name>.cpp` with its own `main()`.
2. Run `.\build.ps1` — it is picked up automatically.
3. Optionally document it in the Examples Catalog above and `PLAN.md`.

## Git Workflow

This repo uses a simple two-branch flow:

```
develop   ->  active work lands here first
   |
merge ->  main      stable state of the repo
```

Typical cycle:

```bash
git checkout develop
# ...make changes...
git add -A && git commit -m "describe the change"
git checkout main
git merge develop --no-ff
git push origin main develop
```
