
#include "TestCase.hpp"

TestCase::TestCase(const std::string& name, const Error& error) {
	this->name = name;
	this->error = error;
}

TestCase::TestCase(const TestCase& other_testCase) {
	this->name = other_testCase.name;
	this->error = other_testCase.error;
}
TestCase& TestCase::operator=(const TestCase& other_testCase) {
	if (this != &other_testCase) {
		this->name = other_testCase.name;
		this->error = other_testCase.error;
	}

	return *this;
}

std::string TestCase::getName() const {
	return this->name;
}

bool TestCase::isPassing() const {
	return error.getType() == ErrorType::None || error.getType() == ErrorType::Warning;
}

bool TestCase::hasError() const {
	return error.getType() != ErrorType::None;
}

ErrorType TestCase::getErrorType() const {
	return error.getType();
}

std::string TestCase::getErrorMessage() const {
	if (error.getType() == ErrorType::None) {
		return "";
	}
	else {
		return error.getMessage();
	}
}