#pragma once
#include "Request.hpp"

class PromotionRequest : public Request{
protected:
	double amount;
public:
	PromotionRequest(const string& sender, double amount);
	double getAmount() const;
};
