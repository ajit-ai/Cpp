// Smart pointers: RAII ownership, unique_ptr, shared_ptr, weak_ptr.
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Resource {
   public:
    explicit Resource(string name) : name_(move(name)) {
        cout << "  [acquire] " << name_ << endl;
    }
    ~Resource() { cout << "  [release] " << name_ << endl; }
    void use() const { cout << "  using " << name_ << endl; }

   private:
    string name_;
};

// Takes sole ownership: caller's unique_ptr must be moved here
void consume(unique_ptr<Resource> res) { res->use(); }

int main() {
    cout << "--- unique_ptr: exclusive ownership ---" << endl;
    {
        auto res = make_unique<Resource>("file-handle");
        res->use();
        // unique_ptr cannot be copied; ownership is TRANSFERRED by move
        consume(move(res));
        cout << "  res is now nullptr? " << boolalpha << (res == nullptr) << endl;
    }   // memory freed automatically, even on early returns/exceptions

    cout << "--- shared_ptr: shared ownership with ref counting ---" << endl;
    {
        auto shared = make_shared<Resource>("config");
        cout << "  use_count = " << shared.use_count() << endl;
        {
            auto copy = shared;               // both point to same object
            cout << "  use_count = " << shared.use_count() << endl;
        }                                     // copy destroyed, count drops
        cout << "  use_count = " << shared.use_count() << endl;

        vector<shared_ptr<Resource>> cache{shared};
        cache.push_back(shared);
        cout << "  use_count = " << shared.use_count()
             << " (vector holds 2 more refs)" << endl;
    }

    cout << "--- weak_ptr: observes without owning (breaks cycles) ---" << endl;
    {
        auto shared = make_shared<Resource>("cache-entry");
        weak_ptr<Resource> observer = shared;

        if (auto locked = observer.lock()) {   // temporarily promote to shared
            locked->use();
            cout << "  object still alive" << endl;
        }
        shared.reset();                        // owner gone -> object destroyed
        cout << "  after reset, lock succeeded? "
             << boolalpha << static_cast<bool>(observer.lock()) << endl;
    }

    cout << "--- raw pointer is fine for NON-owning access ---" << endl;
    {
        auto res = make_unique<Resource>("temp");
        Resource* raw = res.get();   // just borrows, never deletes
        raw->use();
    }

    return 0;
}
