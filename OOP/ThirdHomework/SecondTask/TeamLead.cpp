#include "TeamLead.hpp"

TeamLead::TeamLead(const string& name, double salary)
	:Developer(name)
{
	this->salary = salary;
	this->leader = this;
}

vector<Developer*> TeamLead::getTeam() const
{
	return this->team;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
	if (developer == nullptr) 
	{
		return;
	}

	developer->setTeamLead(this);
	developer->setInitialSalary(salary);
	this->team.push_back(developer);
}

void TeamLead::removeDeveloperFromTeam(const string& name)
{
	for (int i = (int)team.size() - 1; i >= 0; i--)
	{
		if (team[i]->getName() == name) 
		{
			team[i]->setTeamLead(nullptr);
			team[i]->setSalary(0);
			team.erase(team.begin() + i);
			break;
		}
	}
}

void TeamLead::increaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < (int)team.size(); i++)
	{
		team[i]->setSalary(team[i]->getSalary() + amount);
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < (int)team.size(); i++)
	{
		team[i]->setSalary(team[i]->getSalary() - amount);
	}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	this->leavingRequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	this->promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests()
{
	for (int i = 0; i < (int)leavingRequests.size(); i++)
	{
		this->removeDeveloperFromTeam(leavingRequests[i].getSender());
	}

	leavingRequests.clear();
}

void TeamLead::fulfillPromotionRequests()
{
	for (int i = 0; i < (int)promotionRequests.size(); i++)
	{
		for (int j = 0; j < (int)team.size(); j++)
		{
			if (team[j]->getName() == promotionRequests[i].getSender()) 
			{
				team[j]->setSalary
				(team[j]->getSalary() + promotionRequests[j].getAmount());
				break;
			}
		}
	}

	promotionRequests.clear();
}
