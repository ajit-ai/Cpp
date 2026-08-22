// Templates deep-dive: class templates, specialization, variadic templates,
// fold expressions, and C++20 concepts.
#include <concepts>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// --- Class template with a default template argument ---
template <typename T, size_t Capacity = 4>
class FixedStack {
   public:
    void push(const T& value) {
        if (size_ >= Capacity) throw overflow_error("stack is full");
        data_[size_++] = value;
    }

    T pop() {
        if (size_ == 0) throw underflow_error("stack is empty");
        return data_[--size_];
    }

    size_t size() const { return size_; }

   private:
    T data_[Capacity]{};
    size_t size_ = 0;
};

// --- Primary template + specializations for specific types ---
template <typename T>
struct Descriptor {
    static string name() { return "unknown type"; }
};

template <>
struct Descriptor<int> {
    static string name() { return "integer"; }
};

template <>
struct Descriptor<string> {
    static string name() { return "string"; }
};

// --- Variadic template + C++17 fold expression ---
template <typename... Args>
auto sumAll(Args... args) {
    return (args + ...);   // expands to a + b + c + ...
}

// --- C++20 concept: a named constraint on template arguments ---
template <typename T>
concept Numeric = integral<T> || floating_point<T>;

template <Numeric T>
T average(const vector<T>& values) {
    T total{};
    for (const T& v : values) total += v;
    return total / static_cast<T>(values.size());
}

int main() {
    // Class templates in action
    FixedStack<int> ints;                 // capacity defaults to 4
    ints.push(1);
    ints.push(2);
    ints.push(3);
    cout << "popped " << ints.pop() << ", size now " << ints.size() << endl;

    FixedStack<string, 8> words;          // custom capacity
    words.push("hello");
    words.push("templates");
    cout << "words stack holds " << words.size() << " items" << endl;

    // Specialization lookup happens at compile time
    cout << "Descriptor<int>:    " << Descriptor<int>::name() << endl;
    cout << "Descriptor<string>: " << Descriptor<string>::name() << endl;
    cout << "Descriptor<double>: " << Descriptor<double>::name() << endl;

    // Variadic + fold
    cout << "sumAll(1, 2, 3, 4)  = " << sumAll(1, 2, 3, 4) << endl;
    cout << "sumAll(0.5, 0.25)   = " << sumAll(0.5, 0.25) << endl;

    // Concepts: only numeric types compile here
    cout << "average({1, 2, 3})     = " << average<int>({1, 2, 3}) << endl;
    cout << "average({1.5, 2.5})    = " << average<double>({1.5, 2.5}) << endl;

    return 0;
}
