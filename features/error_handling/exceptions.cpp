// Error handling: try/catch, the stdexcept hierarchy, custom exceptions
// with state, rethrowing, stack unwinding, and noexcept.
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// Custom exception: derives from a standard type and carries context
class InsufficientFundsError : public runtime_error {
   public:
    InsufficientFundsError(double requested, double available)
        : runtime_error("insufficient funds"),
          requested_(requested),
          available_(available) {}

    double requested() const { return requested_; }
    double available() const { return available_; }

   private:
    double requested_, available_;
};

void withdraw(double& balance, double amount) {
    if (amount <= 0) throw invalid_argument("amount must be positive");
    if (amount > balance) throw InsufficientFundsError(amount, balance);
    balance -= amount;
}

int safeDivide(int a, int b) {
    if (b == 0) throw domain_error("division by zero");
    return a / b;
}

int main() {
    // --- Throw and catch with exception state ---
    double balance = 100;
    try {
        withdraw(balance, 30);
        cout << "withdrew 30, balance = " << balance << endl;
        withdraw(balance, 500);   // throws here
        cout << "this line is never reached" << endl;
    } catch (const InsufficientFundsError& e) {   // most specific first
        cout << "bank says no: " << e.what() << " (wanted " << e.requested()
             << ", had " << e.available() << ")" << endl;
    } catch (const exception& e) {                // base catches everything else
        cout << "error: " << e.what() << endl;
    }

    // --- Hierarchy: out_of_range IS-A logic_error ---
    try {
        throw out_of_range("index 42 is out of range");
    } catch (const logic_error& e) {
        cout << "logic error caught: " << e.what() << endl;
    }

    // --- Rethrow: inner handler logs, outer handler decides ---
    try {
        try {
            throw runtime_error("original problem");
        } catch (const exception&) {
            cout << "inner handler: logging and rethrowing" << endl;
            throw;   // rethrows the SAME exception object
        }
    } catch (const exception& e) {
        cout << "outer handler got: " << e.what() << endl;
    }

    // --- Standard library throws too (.at() bounds-checks) ---
    vector<int> data{1, 2, 3};
    try {
        cout << data.at(10) << endl;
    } catch (const out_of_range& e) {
        cout << "caught: " << e.what() << "; data still intact ("
             << data.size() << " items)" << endl;
    }

    // --- Domain errors ---
    try {
        safeDivide(5, 0);
    } catch (const domain_error& e) {
        cout << "math error: " << e.what() << endl;
    }

    return 0;
}
