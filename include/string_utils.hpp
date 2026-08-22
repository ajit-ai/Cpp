#pragma once
// Small string utilities used to demonstrate unit testing.

#include <sstream>
#include <string>
#include <vector>

namespace utils {

inline std::string toUpper(std::string s) {
    for (char& c : s)
        if (c >= 'a' && c <= 'z') c = static_cast<char>(c - 'a' + 'A');
    return s;
}

inline std::string trim(const std::string& s) {
    const size_t begin = s.find_first_not_of(" \t\r\n");
    if (begin == std::string::npos) return "";
    const size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(begin, end - begin + 1);
}

inline std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> parts;
    std::stringstream stream(s);
    std::string item;
    while (std::getline(stream, item, delimiter)) parts.push_back(item);
    return parts;
}

inline std::string join(const std::vector<std::string>& parts,
                        const std::string& separator) {
    std::string result;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) result += separator;
        result += parts[i];
    }
    return result;
}

inline bool startsWith(const std::string& s, const std::string& prefix) {
    return s.rfind(prefix, 0) == 0;
}

}  // namespace utils
