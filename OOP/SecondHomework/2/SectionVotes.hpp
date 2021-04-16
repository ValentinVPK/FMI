#pragma once
#include <iostream>
using namespace std;


enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes
{
private:
    int party1Votes;
    int party2Votes;
    int party3Votes;
public:
    SectionVotes(const SectionVotes& other);
    SectionVotes& operator=(const SectionVotes& other);
    SectionVotes(int party1Votes = 0, int party2Votes = 0, int party3Votes = 0);

    int votesForParty(Party party) const;

    friend ostream& operator<<(ostream& output, const SectionVotes& rhs);

    friend istream& operator>>(istream& input, SectionVotes& rhs);
    
    bool is_empty() const;
};

