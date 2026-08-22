#include "string_utils.hpp"

#include "test_framework.hpp"

TEST(StringUtils, toUpper) {
    CHECK_EQ(utils::toUpper("hello"), "HELLO");
    CHECK_EQ(utils::toUpper("MiXeD 123!"), "MIXED 123!");
    CHECK_EQ(utils::toUpper(""), "");
}

TEST(StringUtils, trim) {
    CHECK_EQ(utils::trim("  hello  "), "hello");
    CHECK_EQ(utils::trim("\t\ntext\r\n"), "text");
    CHECK_EQ(utils::trim("no-spaces"), "no-spaces");
    CHECK_EQ(utils::trim("     "), "");
}

TEST(StringUtils, split) {
    auto parts = utils::split("a,b,c", ',');
    CHECK_EQ(parts.size(), 3u);
    CHECK_EQ(parts[0], "a");
    CHECK_EQ(parts[1], "b");
    CHECK_EQ(parts[2], "c");

    CHECK(utils::split("single", ',').size() == 1);
}

TEST(StringUtils, join) {
    CHECK_EQ(utils::join({"x", "y", "z"}, "-"), "x-y-z");
    CHECK_EQ(utils::join({}, "-"), "");
    CHECK_EQ(utils::join({"only"}, ","), "only");
}

TEST(StringUtils, splitJoinRoundTrip) {
    const std::vector<std::string> words{"one", "two", "three"};
    CHECK_EQ(utils::split(utils::join(words, " "), ' '), words);
}

TEST(StringUtils, startsWith) {
    CHECK(utils::startsWith("Hello, World", "Hello"));
    CHECK(!utils::startsWith("Hello", "World"));
    CHECK(utils::startsWith("", ""));
}
