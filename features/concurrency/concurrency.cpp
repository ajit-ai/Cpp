// Concurrency: threads, mutexes, atomics, and async tasks.
// Build with -pthread (build.ps1 / CMake / CI already do this).
#include <atomic>
#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

long long unsafeCounter = 0;             // NO protection: data race demo
long long mutexCounter = 0;              // protected by mutex
atomic<long long> atomicCounter{0};      // lock-free atomic type

mutex counterMutex;

void worker(int id) {
    cout << "  thread " << id << " started" << endl;
    for (int i = 0; i < 100000; ++i) {
        ++unsafeCounter;                 // race: unsynchronized read-modify-write

        {
            lock_guard<mutex> guard(counterMutex);   // lock until scope ends
            ++mutexCounter;                          // critical section
        }

        ++atomicCounter;                 // atomic: always correct
    }
}

int slowSquare(int x) {
    this_thread::sleep_for(chrono::milliseconds(50));   // pretend to work
    return x * x;
}

int main() {
    // --- Launch a pool of threads and wait for them ---
    vector<thread> pool;
    for (int id = 0; id < 4; ++id) pool.emplace_back(worker, id);
    for (thread& t : pool) t.join();     // main blocks here until all finish

    constexpr long long expected = 4 * 100000;
    cout << "expected count : " << expected << endl;
    cout << "unsafe counter : " << unsafeCounter
         << " (races make this wrong or flaky)" << endl;
    cout << "mutex counter  : " << mutexCounter << endl;
    cout << "atomic counter : " << atomicCounter << endl;

    // --- async/future: background task with a result ---
    future<int> result = async(launch::async, slowSquare, 12);
    cout << "main thread works while the task runs..." << endl;
    cout << "12 squared = " << result.get() << endl;   // blocks until ready

    // --- Hardware hint: how many threads can run truly in parallel ---
    cout << "hardware threads: " << thread::hardware_concurrency() << endl;

    return 0;
}
