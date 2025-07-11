
#include <iostream>
using namespace std;

int main() {
    int a; // Integer
    unsigned int b; // Unsigned integers only store positive numbers. As a result, they have a higher positive range.
    char c; // Character
    short d; // Short integer
    long e; // Long integer
    float f; // Floating point integer
    double g; // Double-precision floating point integer
    bool h; // Boolean TRUE or FALSE
    auto k = 1; // Automatically infer type. Not a type in itself.

    // Output the sizes of the data types
    std::cout << "Size of int: " << sizeof(a) << " bytes" << std::endl;
    std::cout << "Size of unsigned int: " << sizeof(b) << " bytes" << std::endl;
    std::cout << "Size of char: " << sizeof(c) << " bytes" << std::endl;
    std::cout << "Size of short: " << sizeof(d) << " bytes" << std::endl;
    std::cout << "Size of long: " << sizeof(e) << " bytes" << std::endl;
    std::cout << "Size of float: " << sizeof(f) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(g) << " bytes" << std::endl;
    std::cout << "Size of bool: " << sizeof(h) << " bytes" << std::endl;
    std::cout << "Size of auto: " << sizeof(k) << " bytes" << std::endl;
    std::cout << "Size of long long: " << sizeof(long long) << " bytes" << std::endl;
    std::cout << "Size of long double: " << sizeof(long double) << " bytes" << std::endl;
    return 0;
}