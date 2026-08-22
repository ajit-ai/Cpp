// Functions: overloading, default args, references, templates,
// recursion, constexpr.
#include <iostream>
#include <string>

using namespace std;

// --- Function overloading: same name, different parameter types ---
int area(int side) { return side * side; }

double area(double radius) { return 3.14159 * radius * radius; }

int area(int width, int height) { return width * height; }

// --- Default arguments ---
void greet(const string& name, const string& greeting = "Hello") {
    cout << greeting << ", " << name << "!" << endl;
}

// --- Pass by value vs pass by reference ---
void incrementByValue(int x) { x += 10; }              // copy modified only
void incrementByReference(int& x) { x += 10; }         // caller's variable
void incrementByPointer(int* x) { *x += 10; }          // via pointer

// --- Function template: works for any comparable type ---
template <typename T>
T maxOf(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// --- Recursion: factorial ---
long long factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// --- constexpr: computed at compile time ---
constexpr int square(int x) { return x * x; }

int main() {
    cout << "area(4)      = " << area(4) << endl;
    cout << "area(2.5)    = " << area(2.5) << endl;
    cout << "area(3, 4)   = " << area(3, 4) << endl;

    greet("Ajit");
    greet("Ajit", "Welcome");

    int value = 5;
    incrementByValue(value);
    cout << "after by-value      : " << value << endl;
    incrementByReference(value);
    cout << "after by-reference  : " << value << endl;
    incrementByPointer(&value);
    cout << "after by-pointer    : " << value << endl;

    cout << "maxOf(3, 9)     = " << maxOf(3, 9) << endl;
    cout << "maxOf(2.7, 1.4) = " << maxOf(2.7, 1.4) << endl;
    cout << "maxOf(cat, dog) = " << maxOf(string("cat"), string("dog")) << endl;

    cout << "factorial(6) = " << factorial(6) << endl;

    constexpr int s = square(12);   // evaluated during compilation
    cout << "square(12) = " << s << endl;

    return 0;
}
