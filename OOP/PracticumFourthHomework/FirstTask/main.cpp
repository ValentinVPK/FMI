/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Valentin Krumov
* @idnumber 62539
* @task 1
* @compiler VC
*/
#include <iostream>
#include "PendulumCard.hpp"
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
#include "Duelist.hpp"

int main()
{
    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 43, 3000, 2500);

    MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);

    MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123, CardType::SPELL);

    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 9, CardType::TRAP);

    PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8);

    Duelist firstDuelist("Zhehcko Popov");

    firstDuelist.get_deck().set_deck_name("Magician Deck");
    firstDuelist.get_deck().add_card(&dragon);
    firstDuelist.get_deck().add_card(&swords);
    firstDuelist.get_deck().add_card(&magician);
    firstDuelist.get_deck().add_card(&cylinder);
    firstDuelist.get_deck().add_card(&timegazer);
    firstDuelist.get_deck().shuffle();

    firstDuelist.save_deck("magician_deck.txt");

    MagicCard box("Mystic Box", "Destroy one monster.", 0, CardType::SPELL);

    firstDuelist.get_deck().change_card(1, &box);
    Duelist secondDuelist("Gosho Goshev");
    secondDuelist.get_deck().add_card(&dragon);
    secondDuelist.get_deck().add_card(&swords);
    secondDuelist.get_deck().add_card(&magician);
    secondDuelist.get_deck().add_card(&cylinder);
    secondDuelist.get_deck().add_card(&timegazer);

    firstDuelist.duel(secondDuelist);
}
