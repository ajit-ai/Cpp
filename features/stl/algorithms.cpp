// STL algorithms: sorting, searching, counting, transforming.
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> nums{5, 2, 8, 1, 9, 3};

    // --- sort (ascending) and sort with custom comparator ---
    sort(nums.begin(), nums.end());
    cout << "sorted: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    sort(nums.begin(), nums.end(), greater<int>());   // descending
    cout << "descending: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    // --- find / find_if ---
    auto pos = find(nums.begin(), nums.end(), 8);
    if (pos != nums.end()) cout << "found 8 at index " << (pos - nums.begin()) << endl;

    auto firstOdd = find_if(nums.begin(), nums.end(), [](int n) { return n % 2 != 0; });
    if (firstOdd != nums.end()) cout << "first odd: " << *firstOdd << endl;

    // --- count_if + accumulate ---
    int evens = count_if(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; });
    int total = accumulate(nums.begin(), nums.end(), 0);
    cout << "evens=" << evens << " sum=" << total << endl;

    // --- min/max elements ---
    auto [lo, hi] = minmax_element(nums.begin(), nums.end());
    cout << "min=" << *lo << " max=" << *hi << endl;

    // --- transform: square every element in place ---
    transform(nums.begin(), nums.end(), nums.begin(), [](int n) { return n * n; });
    cout << "squared: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    // --- erase-remove idiom: delete all values > 40 ---
    nums.erase(remove_if(nums.begin(), nums.end(),
                         [](int n) { return n > 40; }),
               nums.end());
    cout << "after erase-remove: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    // --- reverse + unique on sorted data ---
    vector<int> dupes{1, 1, 2, 2, 3};
    dupes.erase(unique(dupes.begin(), dupes.end()), dupes.end());
    cout << "unique count: " << dupes.size() << endl;

    // --- all_of / any_of ---
    cout << boolalpha
         << "all positive? " << all_of(nums.begin(), nums.end(),
                                       [](int n) { return n > 0; })
         << ", any > 50? " << any_of(nums.begin(), nums.end(),
                                     [](int n) { return n > 50; })
         << endl;

    return 0;
}
