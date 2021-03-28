#pragma warning(disable : 4996)
#include "Error.hpp"

Error::Error() {
	this->error_type = ErrorType::None;
	this->message = nullptr;
}
Error::Error(ErrorType init_type, const char* init_message) {
	error_type = init_type;
	if (init_message == nullptr) {
		message = nullptr;
	}
	else {
		message = new char[strlen(init_message) + 1];
		strcpy(message, init_message);
	}
}
Error::Error(const Error& other_err) {
	this->error_type = other_err.error_type;
	if (other_err.message == nullptr) {
		message = nullptr;
	}
	else {
		this->message = new char[strlen(other_err.message) + 1];
		strcpy(message, other_err.message);
	}
}
Error& Error::operator=(const Error& other_err) {
	if (this != &other_err) {
		this->error_type = other_err.error_type;
		delete[] this->message;

		if (other_err.message == nullptr) {
			message = nullptr;
		}
		else {
			this->message = new char[strlen(other_err.message) + 1];
			strcpy(message, other_err.message);
		}
	}

	return *this;
}

Error::~Error() {
	delete[] message;
}

bool Error::hasMessage() const {
	return message != nullptr;
}

Error Error::newNone() {
	Error err(ErrorType::None, nullptr);
	return err;
}

Error Error::newBuildFailed(const char* message) {
	Error err(ErrorType::BuildFailed, message);
	return err;
}

Error Error::newWarning(const char* message) {

	Error err(ErrorType::Warning, message);
	return err;
}

Error Error::newFailedAssertion(const char* message) {
	Error err(ErrorType::FailedAssertion, message);
	return err;
}

const char* Error::getMessage() const {
	return message;
}


ErrorType Error::getType() const {
	return error_type;
}