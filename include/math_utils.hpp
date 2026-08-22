#pragma once
// Small math utilities used to demonstrate unit testing.

namespace utils {

inline int add(int a, int b) { return a + b; }

inline int multiply(int a, int b) { return a * b; }

inline long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) result *= i;
    return result;
}

inline bool isPrime(int n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

// Iterative Fibonacci: fib(0)=0, fib(1)=1, fib(2)=1, ...
inline int fibonacci(int n) {
    if (n <= 1) return n;
    int prev = 0, curr = 1;
    for (int i = 2; i <= n; ++i) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

}  // namespace utils
