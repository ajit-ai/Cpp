# C++ Learning Repository - Enhancement Plan

This roadmap grows the repo from basic syntax programs into a structured,
feature-wise C++ learning collection with unit tests and an automated build.

## Current State (Phase 0 - done)

| Folder | File | Topic |
|---|---|---|
| `basic/` | `Hello.cpp` | First program, iostream |
| `basic/datatype/` | `datatype.cpp` | Fundamental types + `sizeof` |
| `basic/datatype/` | `stringdatatype.cpp` | Initialization styles, C-strings vs `std::string` |
| `basic/variabe/` | `variabeexample.cpp`, `floatex.cpp` | Variables, type conversion |

## Phase 1 - Core Language Features (done)

| Path | Topics covered |
|---|---|
| `features/control_flow/control_flow.cpp` | `if/else`, `switch`, `for`, `while`, `do-while`, range-based `for`, `break`/`continue` |
| `features/functions/functions.cpp` | Overloading, default arguments, pass-by-value/reference, templates, recursion, `constexpr` |

## Phase 2 - OOP (done)

| Path | Topics covered |
|---|---|
| `features/oop/classes_basics.cpp` | Classes, encapsulation, constructors/destructor, static members, operator overloading |
| `features/oop/inheritance_polymorphism.cpp` | Inheritance, `virtual`, abstract classes, polymorphism, `dynamic_cast` |

## Phase 3 - Standard Library / STL (done)

| Path | Topics covered |
|---|---|
| `features/stl/containers.cpp` | `vector`, `map`, `set`, `unordered_map`, `stack`, `queue`, `pair` |
| `features/stl/algorithms.cpp` | `sort`, `find_if`, `count_if`, `accumulate`, `transform`, erase-remove idiom |

## Phase 4 - Modern C++ (11/14/17) (done)

| Path | Topics covered |
|---|---|
| `features/modern/smart_pointers.cpp` | `unique_ptr`, `shared_ptr`, `weak_ptr`, RAII ownership |
| `features/modern/modern_features.cpp` | Lambdas, structured bindings, `std::optional`, move semantics, `string_view`, init-statements |

## Phase 5 - Testing & Build Automation (done)

| Item | Description |
|---|---|
| `include/math_utils.hpp` | Small utility library the tests exercise |
| `include/string_utils.hpp` | String helpers (`to_upper`, `trim`, `split`, `join`) |
| `tests/test_framework.hpp` | Minimal header-only test framework (no external deps): `TEST`, `CHECK`, `CHECK_EQ`, `CHECK_NEAR` |
| `tests/test_math_utils.cpp` | Unit tests for math utils |
| `tests/test_string_utils.cpp` | Unit tests for string utils |
| `build.ps1` | One-command build + test runner for Windows/g++ |
| `CMakeLists.txt` | Portable build (works with CMake generators) |

## Future Ideas (Phase 6+)

- [x] GitHub Actions CI workflow building examples + running tests on push
- [ ] Exception handling and error handling patterns
- [ ] Templates deep-dive: class templates, variadic templates, concepts
- [ ] Concurrency: `std::thread`, `mutex`, `atomic`, `async`
- [ ] File I/O: `fstream`, serialization
- [ ] Move to GoogleTest/Catch2 when external deps are acceptable
