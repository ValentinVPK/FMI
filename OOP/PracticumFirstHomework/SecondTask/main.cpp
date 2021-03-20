/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Valentin Krumov
* @idnumber 62539
* @task 2
* @compiler VC
*/

#include <iostream>
#include "Duelist.hpp"

int main()
{
    Deck d;

    MonsterCard card("Blue-eyes white dragon", 3000, 2500);
    d.changeMonsterCard(4, card);

    d.changeMagicCard(5, MagicCard("Monster reborn", "revive", "spell"));

    d.printDeck();

    cout << d.getMagicCardsCount() << endl;
    cout << d.getMonsterCardsCount() << endl;

    Duelist player1("Chazz Prinston");
    MonsterCard DarkMagician("Dark Magician", 2500, 2100);
    player1.changeMonsterCardInDeck(2, DarkMagician);
    player1.printDuelistAndDeck();

    Duelist player2("Jayden Yuki");
    MagicCard Reflection("Reflection", "Reflects the last played spell", "trap");
    player2.changeMagicCardInDeck(2, Reflection);
    player2.printDuelistAndDeck();
}

