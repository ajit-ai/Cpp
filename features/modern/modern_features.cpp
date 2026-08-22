// Modern C++ (11/14/17): auto, lambdas, structured bindings, std::optional,
// move semantics, string_view, if-with-initializer.
#include <iostream>
#include <map>
#include <optional>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

using namespace std;

// --- Move semantics: a buffer that owns heap memory ---
class Buffer {
   public:
    explicit Buffer(size_t size) : size_(size), data_(new int[size]{}) {
        cout << "  constructed (" << size_ << " ints)" << endl;
    }

    ~Buffer() { delete[] data_; }

    // Move constructor: steal the resource, leave source empty
    Buffer(Buffer&& other) noexcept : size_(other.size_), data_(other.data_) {
        other.data_ = nullptr;
        other.size_ = 0;
        cout << "  moved" << endl;
    }

    size_t size() const { return size_; }

   private:
    size_t size_;
    int* data_;

    Buffer(const Buffer&) = delete;             // copying disabled for demo
    Buffer& operator=(const Buffer&) = delete;
};

Buffer makeBuffer() { return Buffer(100); }     // move constructor kicks in

// --- std::optional: "maybe a value" without magic numbers/null ---
optional<int> findIndex(const vector<int>& v, int target) {
    for (size_t i = 0; i < v.size(); ++i)
        if (v[i] == target) return static_cast<int>(i);
    return nullopt;
}

int main() {
    // --- auto: let the compiler deduce types ---
    auto count = 42u;                // unsigned int
    auto price = 9.99;               // double
    cout << "count=" << count << ", price=" << price << endl;
    auto names = vector<string>{"Ada", "Linus"};

    // --- lambdas: anonymous functions, capture by value or reference ---
    int factor = 3;
    auto multiply = [factor](int x) { return x * factor; };      // by value
    auto appendTo = [&names](const string& s) { names.push_back(s); };
    cout << "multiply(7) = " << multiply(7) << endl;
    appendTo("Grace");

    // --- structured bindings: unpack pairs/map entries ---
    map<string, int> scores{{"math", 95}, {"cpp", 98}};
    for (const auto& [subject, score] : scores)
        cout << subject << " -> " << score << endl;

    auto [bestSubject, bestScore] = *scores.begin();
    cout << "first entry: " << bestSubject << " " << bestScore << endl;

    // --- optional usage ---
    auto idx = findIndex({10, 20, 30}, 20);
    if (idx.has_value()) cout << "found at index " << idx.value() << endl;

    if (findIndex({10, 20}, 99) == nullopt)
        cout << "99 not found" << endl;

    // --- string_view: non-owning read-only view, no copies ---
    string_view sv = "Hello, Modern C++";
    cout << "prefix: " << sv.substr(0, 5) << ", length: " << sv.size() << endl;

    // --- if with initializer (C++17) ---
    if (int doubled = multiply(21); doubled > 50) {
        cout << "doubled=" << doubled << " is big" << endl;
    }

    // --- move semantics in action ---
    cout << "move demo:" << endl;
    Buffer b1(50);
    Buffer b2 = move(b1);            // explicit move
    Buffer b3 = makeBuffer();        // moved from return value
    cout << "  sizes: " << b1.size() << " " << b2.size()
         << " " << b3.size() << endl;

    return 0;
}
