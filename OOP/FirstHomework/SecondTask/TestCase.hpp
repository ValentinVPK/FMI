#pragma once
#include <string>

#include "Error.hpp"

class TestCase {
private:
    std::string name;
    Error error;
public:
    TestCase(const std::string& name = "", const Error& error = Error::newNone());
    TestCase(const TestCase& other_testCase);

    TestCase& operator=(const TestCase& other_testCase);

    std::string getName() const;

    bool isPassing() const;

    bool hasError() const;

    ErrorType getErrorType() const;

    std::string getErrorMessage() const;
};
