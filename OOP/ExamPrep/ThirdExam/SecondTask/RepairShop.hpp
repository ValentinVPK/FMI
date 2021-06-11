#pragma once
#include "Vehicle.hpp"
#include <iostream>
#include <vector>
using namespace std;

class RepairShop {
private:
	static RepairShop* instance;

	RepairShop() = default;
	RepairShop(const RepairShop& rhs);
	RepairShop& operator=(const RepairShop& rhs);

	vector<Vehicle*> vehicles;
	const size_t MAX_CAPACITY = 10;

	size_t calcCapacity() const;
public:
	static RepairShop* getInstance();

	~RepairShop();

	void add(const Vehicle* vehicle);

	bool hasCapacity() const;
};
