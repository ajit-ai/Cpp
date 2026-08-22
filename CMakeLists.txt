cmake_minimum_required(VERSION 3.15)
project(cpp_examples CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# One executable per example program
file(GLOB_RECURSE EXAMPLE_SOURCES CONFIGURE_DEPENDS
    basic/*.cpp
    features/*.cpp
)

foreach(src ${EXAMPLE_SOURCES})
    get_filename_component(target ${src} NAME_WE)
    add_executable(${target} ${src})
endforeach()

# Unit tests (single runner linking all test files + utility headers)
add_executable(unit_tests
    tests/test_math_utils.cpp
    tests/test_string_utils.cpp
)
target_include_directories(unit_tests PRIVATE include)

enable_testing()
add_test(NAME unit_tests COMMAND unit_tests)
