// STL containers: vector, map, set, unordered_map, stack, queue, pair.
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    // --- vector: dynamic array ---
    vector<int> nums{3, 1, 4};
    nums.push_back(1);          // append at the end
    nums.emplace_back(5);       // construct in place (avoids a copy)
    cout << "vector size=" << nums.size()
         << " front=" << nums.front()
         << " back=" << nums.back() << endl;
    for (int n : nums) cout << n << " ";
    cout << endl;

    // --- map: sorted key -> value pairs ---
    map<string, int> ages{{"Ajit", 30}, {"Priya", 28}};
    ages["Ravi"] = 35;                          // insert or overwrite
    if (ages.find("Bob") == ages.end()) {       // membership check
        cout << "Bob is not in the map" << endl;
    }
    for (const auto& [name, age] : ages) {      // structured binding
        cout << name << " is " << age << "; ";
    }
    cout << "\nmap keys are kept sorted automatically" << endl;

    // --- unordered_map: hash table, O(1) average lookup ---
    unordered_map<string, int> stock{{"apple", 10}, {"banana", 7}};
    ++stock["apple"];
    cout << "apples in stock: " << stock["apple"] << endl;

    // --- set: unique sorted elements ---
    set<int> uniqueNums{5, 3, 5, 1, 3};
    cout << "set holds " << uniqueNums.size() << " values:";   // duplicates gone
    for (int v : uniqueNums) cout << " " << v;
    cout << endl;

    // --- stack: LIFO ---
    stack<string> history;
    history.push("page1");
    history.push("page2");
    history.pop();
    cout << "top of history: " << history.top() << endl;

    // --- queue: FIFO ---
    queue<int> line;
    line.push(10);
    line.push(20);
    line.pop();
    cout << "front of queue: " << line.front() << endl;

    return 0;
}
