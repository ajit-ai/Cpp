// Classes: encapsulation, constructors/destructor, static members,
// operator overloading, friend functions.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
   private:
    // Hidden from outside: only accessible through public methods
    string owner_;
    double balance_;

   public:
    static int instanceCount_;   // shared across ALL objects

    // Delegating constructors
    BankAccount() : BankAccount("unknown", 0.0) {}

    explicit BankAccount(const string& owner, double balance = 0.0)
        : owner_(owner), balance_(balance > 0 ? balance : 0.0) {
        ++instanceCount_;
    }

    // Destructor: called automatically when object goes out of scope
    ~BankAccount() { --instanceCount_; }

    void deposit(double amount) {
        if (amount > 0) balance_ += amount;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance_) return false;
        balance_ -= amount;
        return true;
    }

    const string& owner() const { return owner_; }      // read-only accessor
    double balance() const { return balance_; }

    static int instances() { return instanceCount_; }   // no object needed

    // Operator overloading: += adds another account's half-balance (demo)
    BankAccount& operator+=(const BankAccount& other) {
        balance_ += other.balance_ / 2.0;
        return *this;
    }

    // Friend: allowed to touch privates; enables cout << account
    friend ostream& operator<<(ostream& os, const BankAccount& acc);
};

int BankAccount::instanceCount_ = 0;

ostream& operator<<(ostream& os, const BankAccount& acc) {
    return os << acc.owner_ << ": $" << acc.balance_;
}

struct Point {   // struct = class with public members by default
    int x{0};
    int y{0};
};

int main() {
    {
        BankAccount a("Ajit", 1000);
        BankAccount b("Priya");

        a.deposit(500);
        b.deposit(300);
        b.withdraw(100);

        cout << a << endl;
        cout << b << endl;

        a += b;   // operator overloading in action
        cout << "after += : " << a << endl;

        cout << "live accounts: " << BankAccount::instances() << endl;
    }   // destructors run here

    cout << "live accounts after scope: " << BankAccount::instances() << endl;

    Point p{3, 4};
    cout << "Point(" << p.x << ", " << p.y << ")" << endl;

    return 0;
}
