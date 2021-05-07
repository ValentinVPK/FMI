#pragma once
#include <string>
using namespace std;

class TeamLead;

class Developer {
protected:
	string name;
	double salary = 0;
	TeamLead* leader = nullptr;
public:
	Developer(const string& name = "");

	string getName() const;
	double getSalary() const;
	TeamLead* getTeamLead() const;
	void setInitialSalary(double amount);
	
	void setTeamLead(TeamLead* teamLead);
	void setSalary(double amount);

	void sendLeavingRequest();
	void sendPromotionRequest(double amount);
};
