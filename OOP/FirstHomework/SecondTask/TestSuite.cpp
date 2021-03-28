
#include "TestSuite.hpp"

TestSuite::TestSuite(std::string name) {
	this->name = name;
}

TestSuite::TestSuite(const TestSuite& other_test_suite) {
	this->name = other_test_suite.name;
	this->test_cases = other_test_suite.test_cases;
}
TestSuite& TestSuite::operator=(const TestSuite& other_test_suite) {
	if (this != &other_test_suite) {
		this->name = other_test_suite.name;
		this->test_cases = other_test_suite.test_cases;
	}

	return *this;
}

void TestSuite::add(const TestCase& test_case) {
	test_cases.push_back(test_case);
}

std::vector<TestCase> TestSuite::filterPassing() const {
	std::vector<TestCase> filtered;
	for (size_t i = 0; i < test_cases.size(); i++)
	{
		if (test_cases[i].isPassing()) {
			filtered.push_back(test_cases[i]);
		}
	}

	return filtered;
}

std::vector<TestCase> TestSuite::filterFailing() const {
	std::vector<TestCase> filtered;
	for (size_t i = 0; i < test_cases.size(); i++)
	{
		if (!test_cases[i].isPassing()) {
			filtered.push_back(test_cases[i]);
		}
	}

	return filtered;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType type) const {
	std::vector<TestCase> filtered;
	for (size_t i = 0; i < test_cases.size(); i++)
	{
		if (test_cases[i].getErrorType() == type) {
			filtered.push_back(test_cases[i]);
		}
	}

	return filtered;
}

void TestSuite::removeByErrorType(ErrorType type) {
	for (size_t i = 0; i < test_cases.size(); i++)
	{
		if (test_cases[i].getErrorType() == type) {
			test_cases.erase(test_cases.begin() + i);
			i--;
		}
	}
}

std::string TestSuite::getName() const {
	return this->name;
}

void TestSuite::setName(const std::string& name) {
	this->name = name;
}
