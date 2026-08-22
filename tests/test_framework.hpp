#pragma once
// Minimal dependency-free test framework.
//
// Usage:
//   TEST(Math, add) { CHECK(utils::add(1, 2) == 3); }
//   int main() { return testing::runAll(); }

#include <cmath>
#include <exception>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace testing {

struct TestCase {
    std::string name;
    std::function<void()> fn;
};

inline std::vector<TestCase>& registry() {
    static std::vector<TestCase> instance;
    return instance;
}

// Object constructed at static-init time registers each TEST macro use.
struct Registrar {
    Registrar(std::string name, std::function<void()> fn) {
        registry().push_back({std::move(name), std::move(fn)});
    }
};

struct CheckFailure : std::exception {
    explicit CheckFailure(std::string msg) : message(std::move(msg)) {}
    const char* what() const noexcept override { return message.c_str(); }

   private:
    std::string message;
};

inline int runAll() {
    int failed = 0;
    for (const auto& tc : registry()) {
        try {
            tc.fn();
            std::cout << "[ PASS ] " << tc.name << "\n";
        } catch (const std::exception& e) {
            ++failed;
            std::cout << "[ FAIL ] " << tc.name << " -> " << e.what() << "\n";
        }
    }
    std::cout << "\n" << (registry().size() - failed) << "/"
              << registry().size() << " tests passed" << std::endl;
    return failed == 0 ? 0 : 1;
}

}  // namespace testing

#define TEST(suite, name)                                                  \
    static void suite##_##name##_impl();                                   \
    static ::testing::Registrar suite##_##name##_reg{                      \
        #suite "." #name, suite##_##name##_impl};                          \
    static void suite##_##name##_impl()

#define CHECK(cond)                                                        \
    do {                                                                   \
        if (!(cond)) {                                                     \
            throw ::testing::CheckFailure(                                 \
                std::string(__FILE__) + ":" + std::to_string(__LINE__) +   \
                ": CHECK(" #cond ") failed");                              \
        }                                                                  \
    } while (false)

#define CHECK_EQ(a, b) CHECK((a) == (b))
#define CHECK_NEAR(a, b, eps) CHECK(std::abs((a) - (b)) < (eps))
