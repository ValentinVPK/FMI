
#include <iostream>
#include "TeamLead.hpp"

int main()
{
    Developer dev("Gosho");
    Developer dev2("Vesi");
    Developer dev3("Valio");
    Developer dev4("Niki");
    TeamLead teaml("Ivan", 500);

    teaml.addDeveloperToTeam(&dev, 300);
    teaml.addDeveloperToTeam(&dev2, 200);
    teaml.addDeveloperToTeam(&dev3, 100);
    teaml.addDeveloperToTeam(&dev4, 400);
    //teaml.removeDeveloperFromTeam("Ivan");

    dev.sendLeavingRequest();
    dev2.sendLeavingRequest();
    dev3.sendPromotionRequest(75);
    dev4.sendPromotionRequest(50);

    teaml.fulfillLeavingRequests();
    teaml.fulfillPromotionRequests();
}

