#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
#include "IntegerOperation.hpp"

IntegerOperation::IntegerOperation()
{
	this->numbers = nullptr;
	this->currResult = 0;
	this->size = 0;
}

IntegerOperation::IntegerOperation(const IntegerOperation& rhs)
{
	this->size = rhs.size;
	this->currResult = rhs.currResult;

	this->numbers = new int[rhs.size];

	for (size_t i = 0; i < rhs.size; i++)
	{
		this->numbers[i] = rhs.numbers[i];
	}
}

IntegerOperation& IntegerOperation::operator=(const IntegerOperation& rhs)
{
	if (this != &rhs) {
		this->size = rhs.size;
		this->currResult = rhs.currResult;

		delete[] this->numbers;
		this->numbers = new int[rhs.size];
		for (size_t i = 0; i < rhs.size; i++)
		{
			this->numbers[i] = rhs.numbers[i];
		}
	}

	return *this;
}

IntegerOperation::~IntegerOperation()
{
	delete[] this->numbers;
}

void IntegerOperation::insert(int number)
{
	int* tempArr = new int[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		tempArr[i] = numbers[i];
	}

	delete[] numbers;

	this->size++;
	this->numbers = new int[this->size];
	for (size_t i = 0; i < this->size - 1; i++)
	{
		this->numbers[i] = tempArr[i];
	}
	this->numbers[this->size - 1] = number;

	delete[] tempArr;
}

int IntegerOperation::sum()
{
	this->currResult = calculate('+');

	return this->currResult;
}

int IntegerOperation::sub()
{
	this->currResult = calculate('-');

	return this->currResult;
}

int IntegerOperation::multiply()
{
	this->currResult = calculate('*');

	return this->currResult;
}

int IntegerOperation::get_result() const
{
	return this->currResult;
}

int IntegerOperation::calculate(char symbol) const
{
	int result = 0;
	if (symbol == '*') {
		result = 1;
	}

	for (size_t i = 0; i < this->size; i++)
	{
		if (symbol == '+') {
			result += this->numbers[i];
		}

		if (symbol == '-') {
			result -= this->numbers[i];
		}

		if (symbol == '*') {
			result *= this->numbers[i];
		}
	}

	return result;
}

int operator+( IntegerOperation& first, IntegerOperation& second)
{
	return first.sum() + second.sum();
}

int operator-( IntegerOperation& first, IntegerOperation& second)
{
	return first.sub() - second.sub();
}

int operator*( IntegerOperation& first,  IntegerOperation& second)
{
	return first.multiply() * second.multiply();
}
