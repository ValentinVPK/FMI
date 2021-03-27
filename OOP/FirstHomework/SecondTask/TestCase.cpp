#include "TestCase.hpp"

TestCase::TestCase(const std::string& name = "", const Error& error = Error::newNone()) {
	this->name = name;
	this->error = error;

}