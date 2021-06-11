#pragma once
#include <string>
using namespace std;

enum class ProblemLevel {
	Low = 1,
	Average = 3,
	High = 5
};

class Vehicle {
protected:
	string brand;
	string model;
	size_t year;
	string problem;
	ProblemLevel level;
public:
	Vehicle(const string& brand = "", const string& model = "", const size_t& year = 0, const string& problem = "", const ProblemLevel& level = ProblemLevel::Low);

	virtual ~Vehicle() = default;

	string getBrand() const;
	string getModel() const;
	size_t getYear() const;
	string getProblem() const;
	ProblemLevel getLevel() const;

	void setBrand(const string& brand);
	void setModel(const string& model);
	void setYear(const size_t& year);
	void setProblem(const string& problem);
	void setLevel(const ProblemLevel& level);

	virtual Vehicle* clone() const = 0;

};
