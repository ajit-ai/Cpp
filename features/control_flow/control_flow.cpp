// Control flow: if/else, switch, all loop kinds, break/continue.
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // --- if / else if / else ---
    int score = 78;
    if (score >= 90) {
        cout << "Grade: A" << endl;
    } else if (score >= 75) {
        cout << "Grade: B" << endl;
    } else if (score >= 60) {
        cout << "Grade: C" << endl;
    } else {
        cout << "Grade: F" << endl;
    }

    // --- Ternary operator: compact if/else expression ---
    int temp = 31;
    cout << "It is a " << (temp > 30 ? "hot" : "pleasant") << " day" << endl;

    // --- switch ---
    switch (score / 10) {
        case 10:
        case 9:
            cout << "Excellent" << endl;
            break;
        case 8:
        case 7:
            cout << "Good" << endl;
            break;
        default:
            cout << "Needs improvement" << endl;
            break;
    }

    // --- Classic counting loop ---
    for (int i = 1; i <= 5; ++i) {
        cout << i << (i == 5 ? "\n" : " ");
    }

    // --- while loop: sum digits of 4936 ---
    int n = 4936, sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    cout << "digit sum of 4936 = " << sum << endl;

    // --- do-while: body runs at least once ---
    int attempts = 0;
    do {
        ++attempts;
    } while (attempts < 3);
    cout << "attempts = " << attempts << endl;

    // --- Range-based for over array and vector ---
    int primes[] = {2, 3, 5, 7};
    vector<string> names = {"Ada", "Alan", "Grace"};
    for (int p : primes) cout << p << " ";
    cout << endl;
    for (const string& name : names) cout << name << " ";
    cout << endl;

    // --- break and continue ---
    for (int i = 1; i <= 10; ++i) {
        if (i % 2 == 0) continue;   // skip even numbers
        if (i > 7) break;           // stop after 7
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
