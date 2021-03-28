
#include "VendingMachine.hpp"

VendingMachine::VendingMachine() {
	this->number_of_elements = 0;
	this->income = 0;
	this->drinks = new Drink[number_of_elements];
}

VendingMachine::VendingMachine(const VendingMachine& from) {
	this->number_of_elements = from.number_of_elements;
	this->income = from.income;
	this->drinks = new Drink[this->number_of_elements];
	for (size_t i = 0; i < this->number_of_elements; i++)
	{
		drinks[i] = from.drinks[i];
	}
}
VendingMachine& VendingMachine::operator=(const VendingMachine& from) {
	if (this != &from) {
		this->number_of_elements = from.number_of_elements;
		this->income = from.income;

		delete[] this->drinks;
		this->drinks = new Drink[this->number_of_elements];
		for (size_t i = 0; i < this->number_of_elements; i++)
		{
			drinks[i] = from.drinks[i];
		}
	}

	return *this;
}

VendingMachine::~VendingMachine() {
	delete[] drinks;
}

bool VendingMachine::add_drink(const Drink& to_add) {

	if (search_for_drink(to_add.get_name()) != -1) {
		return false;
	}
	else {

		Drink* temp_arr = new Drink[number_of_elements + 1];

		for (size_t i = 0; i < number_of_elements; i++)
		{
			temp_arr[i] = drinks[i];
		}

		temp_arr[number_of_elements++] = to_add;

		delete[] drinks;

		drinks = temp_arr;

		return true;
	}
}

int VendingMachine::buy_drink(const char* drink_name, const double money) {
	int drink_index = search_for_drink(drink_name);
	if (drink_index == -1) {
		return 2;
	}
	else {
		this->income += money;
		if (drinks[drink_index].get_price() <= money) {
			Drink* temp_arr = new Drink[this->number_of_elements - 1];

			int temp_index = 0;
			for (size_t i = 0; i < this->number_of_elements; i++)
			{
				if (i == drink_index) {
					continue;
				}
				temp_arr[temp_index++] = this->drinks[i];
			}

			delete[] this->drinks;
			--number_of_elements;
			this->drinks = temp_arr;

			return 0;
		}
		else {
			return 1;
		}
	}
}

double VendingMachine::get_income() const {
	return this->income;
}

int VendingMachine::search_for_drink(const char* drink_name) const{

	for (size_t i = 0; i < this->number_of_elements; i++) {
		if (strcmp(drinks[i].get_name(), drink_name) == 0) {
			return i;
		}
	}

	return -1;
}

int VendingMachine::get_number_of_elements() const {
	return this->number_of_elements;
}