#pragma once

class IntegerOperation {
private:
	int* numbers;
	int currResult;
	size_t size;

	int calculate(char symbol) const;
public:
	IntegerOperation();
	IntegerOperation(const IntegerOperation& rhs);
	IntegerOperation& operator=(const IntegerOperation& rhs);
	~IntegerOperation();

	void insert(int number);

	int sum();
	int sub();
	int multiply();

	int get_result() const;

	friend int operator+( IntegerOperation& first,  IntegerOperation& second);
	friend int operator-( IntegerOperation& first,  IntegerOperation& second);
	friend int operator*( IntegerOperation& first,  IntegerOperation& second);
};
