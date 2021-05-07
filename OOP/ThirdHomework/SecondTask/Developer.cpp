#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer(const string& name)
{
	this->name = name;
}

string Developer::getName() const
{
	return this->name;
}

double Developer::getSalary() const
{
	return this->salary;
}

TeamLead* Developer::getTeamLead() const
{
	return this->leader;
}

void Developer::setInitialSalary(double amount)
{
	if (this->salary == 0) 
	{
		this->salary = amount;
	}
}

void Developer::setTeamLead(TeamLead* teamLead)
{
	this->leader = teamLead;
}

void Developer::setSalary(double amount)
{
	this->salary = amount;
}

void Developer::sendLeavingRequest()
{
	if (this->leader == nullptr) 
	{
		return;
	}
	LeavingRequest request(this->name);
	this->leader->addLeavingRequest(request);
}

void Developer::sendPromotionRequest(double amount)
{
	if (this->leader == nullptr)
	{
		return;
	}
	PromotionRequest request(this->name,amount);
	this->leader->addPromotionRequest(request);
}
