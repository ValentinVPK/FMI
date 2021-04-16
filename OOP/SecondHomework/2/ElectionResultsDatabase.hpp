#pragma once
#include "SectionVotes.hpp"
#include <vector>
#include <fstream>

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

class ElectionResultsDatabase
{
private:
    vector<SectionVotes> sections;
public:

    void addResultsFromFile(const char* filename);

    int numberOfSections() const;

    int votesForParty(Party party) const;

    Party winningParty() const;

    friend ostream& operator<<(ostream& output, const ElectionResultsDatabase& rhs);
    friend istream& operator>>(istream& input, ElectionResultsDatabase& rhs);
};
