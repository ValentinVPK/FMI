#pragma once
#include "Vehicle.hpp"

class Bus : public Vehicle {
private:
	bool hasPassengers;
public:
	Bus(const string& brand = "", const string& model = "", const size_t& year = 0, const string& problem = "", const ProblemLevel& level = ProblemLevel::Low,
		const bool& hasPassengers = false);

	bool getHasPassengers() const;
	void changePassengers();

	Vehicle* clone() const;
};
