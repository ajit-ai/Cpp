// File I/O: writing, appending, reading line-by-line, parsing CSV records.
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

#include "csv_utils.hpp"
#include "string_utils.hpp"

using namespace std;

int main() {
    const string path = "people.txt";

    // --- Write: ofstream truncates an existing file by default ---
    {
        ofstream out(path);
        if (!out) {
            cerr << "cannot open " << path << " for writing" << endl;
            return 1;
        }
        out << "name,age,city\n";
        out << "Ajit,30,Pune\n";
        out << "Priya,28,Mumbai\n";
        out << "\"Sharma, Dev\",41,\"New Delhi\"\n";   // quoted CSV field
    }   // destructor flushes and closes the file

    // --- Append mode: ios::app keeps existing content ---
    {
        ofstream out(path, ios::app);
        out << "Ravi,35,Chennai\n";
    }

    // --- Read back line by line ---
    ifstream in(path);
    if (!in) {
        cerr << "cannot open " << path << " for reading" << endl;
        return 1;
    }

    string line;
    int recordCount = 0;
    while (getline(in, line)) {
        ++recordCount;
        if (recordCount == 1) {   // first line is the header row
            cout << "header : " << utils::join(utils::split(line, ','), " | ")
                 << endl;
            continue;
        }
        auto fields = utils::parseCsvLine(line);
        cout << "person : " << fields[0] << ", age " << fields[1]
             << ", city " << fields[2] << endl;
    }
    cout << "processed " << recordCount << " lines total" << endl;
    in.close();   // release the lock so the demo file can be removed (Windows)

    // --- Clean up the demo file ---
    if (remove(path.c_str()) == 0)
        cout << "demo file cleaned up" << endl;

    return 0;
}
