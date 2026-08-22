#include "math_utils.hpp"

#include "test_framework.hpp"

TEST(MathUtils, addBasic) {
    CHECK_EQ(utils::add(2, 3), 5);
}

TEST(MathUtils, addNegativeNumbers) {
    CHECK_EQ(utils::add(-4, -6), -10);
    CHECK_EQ(utils::add(-4, 6), 2);
}

TEST(MathUtils, multiplyBasics) {
    CHECK_EQ(utils::multiply(3, 7), 21);
    CHECK_EQ(utils::multiply(0, 99), 0);
    CHECK_EQ(utils::multiply(-3, 7), -21);
}

TEST(MathUtils, factorialEdgeCases) {
    CHECK_EQ(utils::factorial(0), 1LL);
    CHECK_EQ(utils::factorial(1), 1LL);
    CHECK_EQ(utils::factorial(5), 120LL);
    CHECK_EQ(utils::factorial(10), 3628800LL);
}

TEST(MathUtils, isPrime) {
    CHECK(!utils::isPrime(-7));
    CHECK(!utils::isPrime(0));
    CHECK(!utils::isPrime(1));
    CHECK(utils::isPrime(2));
    CHECK(utils::isPrime(3));
    CHECK(!utils::isPrime(9));
    CHECK(utils::isPrime(97));
    CHECK(!utils::isPrime(100));
}

TEST(MathUtils, fibonacciSequence) {
    CHECK_EQ(utils::fibonacci(0), 0);
    CHECK_EQ(utils::fibonacci(1), 1);
    CHECK_EQ(utils::fibonacci(2), 1);
    CHECK_EQ(utils::fibonacci(10), 55);
}
