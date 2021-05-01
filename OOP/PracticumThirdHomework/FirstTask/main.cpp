/**
* Solution to homework assignment 1
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
    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500);
    MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);
    MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", CardType::SPELL);
    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", CardType::TRAP);
    PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 1200, 600, 8, CardType::SPELL);
    Duelist firstDuelist("Ivan Ivanov");
    firstDuelist.get_deck().set_deck_name("Magician Deck");
    firstDuelist.get_deck().add_monster(dragon);
    firstDuelist.get_deck().add_magic(swords);
    firstDuelist.get_deck().add_monster(magician);
    firstDuelist.get_deck().add_magic(cylinder);
    firstDuelist.get_deck().add_pendulum(timegazer);

    firstDuelist.save_deck("magician_deck.txt");

    firstDuelist.load_deck("magician_deck.txt");

    MagicCard box("Mystic Box", "Destroy one monster.", CardType::SPELL);
    firstDuelist.get_deck().change_magic(1, box);

}
