#include "SectionVotes.hpp"


SectionVotes::SectionVotes(const SectionVotes& other)
{
	this->party1Votes = other.party1Votes;
	this->party2Votes = other.party2Votes;
	this->party3Votes = other.party3Votes;
}

SectionVotes& SectionVotes::operator=(const SectionVotes& other)
{
	if (this != &other) 
	{
		this->party1Votes = other.party1Votes;
		this->party2Votes = other.party2Votes;
		this->party3Votes = other.party3Votes;
	}
	
	return *this;
}

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes)
{
	this->party1Votes = party1Votes;
	this->party2Votes = party2Votes;
	this->party3Votes = party3Votes;
}

int SectionVotes::votesForParty(Party party) const
{
	if (party == Party::PARTY1) 
	{
		return this->party1Votes;
	}
	else if (party == Party::PARTY2)
	{
		return this->party2Votes;
	}
	else if (party == Party::PARTY3)
	{
		return this->party3Votes;
	}
	else {
		return 0;
	}

	return 0;
}

bool SectionVotes::is_empty() const
{
	if (this->party1Votes == 0 && this->party2Votes == 0 &&
		this->party3Votes == 0) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

ostream& operator<<(ostream& output, const SectionVotes& rhs)
{
	output << rhs.party1Votes << " " << rhs.party2Votes << " " << rhs.party3Votes;

	return output;
}

istream& operator>>(istream& input, SectionVotes& rhs)
{
	input >> rhs.party1Votes >> rhs.party2Votes >> rhs.party3Votes;
	return input;
}
