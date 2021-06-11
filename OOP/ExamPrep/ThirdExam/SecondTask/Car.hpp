#pragma once
#include "Vehicle.hpp"

class Car : public Vehicle {
private:
	bool isPrivatelyOwned;
public:
	Car(const string& brand = "", const string& model = "", const size_t& year = 0, const string& problem = "", const ProblemLevel& level = ProblemLevel::Low, 
		const bool& isPrivatelyOwned = true);

	bool getIsPrivatelyOwned() const;
	void changeOwnership();

	Vehicle* clone() const;
};
