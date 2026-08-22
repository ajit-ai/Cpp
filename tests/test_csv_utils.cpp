#include "csv_utils.hpp"

#include "test_framework.hpp"

TEST(CsvUtils, plainFields) {
    auto fields = utils::parseCsvLine("name,age,city");
    CHECK_EQ(fields.size(), 3u);
    CHECK_EQ(fields[0], "name");
    CHECK_EQ(fields[1], "age");
    CHECK_EQ(fields[2], "city");
}

TEST(CsvUtils, singleField) {
    CHECK(utils::parseCsvLine("solo") == std::vector<std::string>{"solo"});
}

TEST(CsvUtils, emptyFieldsBetweenCommas) {
    auto fields = utils::parseCsvLine("a,,c");
    CHECK_EQ(fields.size(), 3u);
    CHECK_EQ(fields[1], "");
}

TEST(CsvUtils, quotedFieldWithComma) {
    auto fields = utils::parseCsvLine("\"Sharma, Dev\",41,Delhi");
    CHECK_EQ(fields.size(), 3u);
    CHECK_EQ(fields[0], "Sharma, Dev");
    CHECK_EQ(fields[1], "41");
    CHECK_EQ(fields[2], "Delhi");
}

TEST(CsvUtils, escapedQuotesInsideQuotedField) {
    auto fields = utils::parseCsvLine("\"she said \"\"hi\"\"\",x");
    CHECK_EQ(fields.size(), 2u);
    CHECK_EQ(fields[0], "she said \"hi\"");
    CHECK_EQ(fields[1], "x");
}

TEST(CsvUtils, emptyLineYieldsSingleEmptyField) {
    auto fields = utils::parseCsvLine("");
    CHECK_EQ(fields.size(), 1u);
    CHECK_EQ(fields[0], "");
}
