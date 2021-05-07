#pragma once
#include "Developer.hpp"
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"
#include <vector>

class TeamLead : public Developer{
private:
	vector<Developer*> team;
	vector<LeavingRequest> leavingRequests;
	vector<PromotionRequest> promotionRequests;
public:
	TeamLead(const string& name = "", double salary = 0);

	vector<Developer*> getTeam() const;
	void addDeveloperToTeam(Developer* developer, double salary);
	void removeDeveloperFromTeam(const string& name);
	void increaseTeamSalariesBy(double amount);
	void decreaseTeamSalariesBy(double amount);

	void addLeavingRequest(const LeavingRequest& leavingRequest);
	void addPromotionRequest(const PromotionRequest& promotionRequest);

	void fulfillLeavingRequests();
	void fulfillPromotionRequests();
};
