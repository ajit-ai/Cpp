#pragma once
// Minimal CSV parsing used by the file I/O example and unit tests.

#include <string>
#include <vector>

namespace utils {

// Splits one CSV line into fields.
// Handles double-quoted fields that may contain commas or
// escaped quotes written as "" (RFC 4180 style).
inline std::vector<std::string> parseCsvLine(const std::string& line) {
    std::vector<std::string> fields;
    std::string field;
    bool inQuotes = false;

    for (size_t i = 0; i < line.size(); ++i) {
        const char c = line[i];
        if (inQuotes) {
            if (c == '"') {
                if (i + 1 < line.size() && line[i + 1] == '"') {
                    field += '"';   // "" inside quotes is one literal quote
                    ++i;
                } else {
                    inQuotes = false;
                }
            } else {
                field += c;
            }
        } else if (c == '"') {
            inQuotes = true;        // quoted field may contain commas
        } else if (c == ',') {
            fields.push_back(field);
            field.clear();
        } else {
            field += c;
        }
    }
    fields.push_back(field);        // the last field has no trailing comma
    return fields;
}

}  // namespace utils
