#pragma once
#include <iostream>
#include <cstring>

enum class ErrorType {
    None,
    BuildFailed,
    Warning,
    FailedAssertion,
};


class Error {
private:
    ErrorType error_type;
    char* message;
public:
    Error();
    Error(ErrorType init_type, const char* init_message);
    Error(const Error& other_err);
    Error& operator=(const Error& other_err);
    ~Error();

    bool hasMessage() const;

    const char* getMessage() const;

    ErrorType getType() const;

    static Error newNone();

    static Error newBuildFailed(const char* message);

    static Error newWarning(const char* message);

    static Error newFailedAssertion(const char* message);
};