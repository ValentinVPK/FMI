#pragma once
#include <string>
#include <vector>

#include "TestCase.hpp"

class TestSuite {
private:
    std::string name;
    std::vector<TestCase> test_cases;
public:
    TestSuite(std::string name);
    TestSuite(const TestSuite& other_test_suite);
    TestSuite& operator=(const TestSuite& other_test_suite);

    void add(const TestCase& test_case);

    std::vector<TestCase> filterPassing() const;

    std::vector<TestCase> filterFailing() const;

    std::vector<TestCase> filterByErrorType(ErrorType type) const;

    void removeByErrorType(ErrorType type);

    std::string getName() const;

    void setName(const std::string& name);
};