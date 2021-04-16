#include "ElectionResultsDatabase.hpp"


void ElectionResultsDatabase::addResultsFromFile(const char* filename)
{
    ifstream infile(filename, ios::app); // could be changed to :app
    if (infile.is_open()) {
        while (infile.good()) {
            SectionVotes currSection;
            infile >> currSection;
            if (!currSection.is_empty()) 
            {
                this->sections.push_back(currSection);
            }
        }
    }

    infile.close();  
}

int ElectionResultsDatabase::numberOfSections() const
{

    return (int)this->sections.size();
}

int ElectionResultsDatabase::votesForParty(Party party) const
{
    int sum = 0;
    for (int i = 0; i < (int)this->sections.size(); i++)
    {
        sum += this->sections[i].votesForParty(party);
    }

    return sum;
}

Party ElectionResultsDatabase::winningParty() const
{
    int votesParty1 = this->votesForParty(Party::PARTY1);
    int votesParty2 = this->votesForParty(Party::PARTY2);
    int votesParty3 = this->votesForParty(Party::PARTY3);

    if (votesParty1 >= votesParty2 && votesParty1 >= votesParty3) {
        return Party::PARTY1;
    }

    if (votesParty2 > votesParty1 && votesParty2 >= votesParty3) {
        return Party::PARTY2;
    }

    if (votesParty3 > votesParty1 && votesParty3 > votesParty2) {
        return Party::PARTY3;
    }

    return Party::PARTY1;
}

ostream& operator<<(ostream& output, const ElectionResultsDatabase& rhs)
{
    for (int i = 0; i < (int)rhs.sections.size(); i++)
    {
        if (i == (int)rhs.sections.size() - 1) 
        {
            output << rhs.sections[i];
        }
        else 
        {
            output << rhs.sections[i] << '\n';
        }
    }

    return output;
}

istream& operator>>(istream& input, ElectionResultsDatabase& rhs)
{
    SectionVotes currSection;
    input >> currSection;
    if (!currSection.is_empty())
    {
        rhs.sections.push_back(currSection);
    }

    return input;
}
