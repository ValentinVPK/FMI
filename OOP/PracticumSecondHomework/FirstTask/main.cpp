/**
* Solution to homework assignment 2
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
#include "Backpack.hpp"
#include "Equipment.hpp"
#include "Inventory.hpp"

int main()
{
	// Testing Backpack:

	//1.With Materials
	cout << "BACKPACK TESTING WITH MATERIALS:" << endl;
	Backpack<Materials> materialsPack;
	materialsPack.add_items(65,MaterialTypes::essence);
	materialsPack.add_items(6, MaterialTypes::essence);
	cout << materialsPack.get_slots() << endl; // should return 8 (71 essence)
	materialsPack.extract_items(1,MaterialTypes::essence);
	cout << materialsPack.get_slots() << endl; // should return 7 (70 essense)
	
	materialsPack.add_items(60, MaterialTypes::ores);
	cout << materialsPack.get_slots() << endl; // should return 10 (70 essence, 60 ores)
	materialsPack.add_items(51,MaterialTypes::essence);
	// bag is now full(121 essence - 13 slots, 60 ores - 3 slots)
	materialsPack.add_items(1,MaterialTypes::cloth); // can't add other type of items
	cout << materialsPack.get_slots() << endl; // should return 16
	materialsPack.add_items(9,MaterialTypes::essence); // can add only essense up to 130 max
	// now essense is 130 and ores are 60 - 16 slots total
	materialsPack.add_items(1,MaterialTypes::essence); // can't add anyting anymore

	cout << materialsPack.is_full() << endl; // should return true(1) 
	cout << materialsPack.is_empty() << endl; // should return false(0)

	materialsPack.clear();
	cout << materialsPack.get_slots() << endl; // should return 0;

	//2.With Money
	cout << "BACKPACK TESTING WITH MONEY: " << endl;
	Backpack<Money> moneyPack;
	moneyPack.add_items(250); // should have 2 gold and 50 silver
	moneyPack.clear(); // should have no money
	moneyPack.add_items(450); // should have 4 gold and 50 silver
	moneyPack.extract_items(250); // should have 2 gold and 0 silver
	moneyPack.extract_items(1); // should have 1 gold and 99 silver
	moneyPack.extract_items(200); // should have 0 gold and 0 silver
	cout << moneyPack.get_slots() << endl; // should always return 0
	cout << moneyPack.is_empty() << endl; // should always return true(1)
	cout << moneyPack.is_full() << endl; // should always return false(0) 

	//Testing armor class

	cout << "TESTING ARMOR CLASS" << endl;

	Armor clothArmor(ArmorType::cloth, 250);
	clothArmor.add_effect("Thorns", 50); // should add effect
	clothArmor.change_effect_power("Thorns", 25); // should change effect's power
	clothArmor.remove_effect("Thorns"); // should remove effect

	//Testing equipment with armor class
	cout << "TESTING EQUIPMENT WITH ARMOR CLASS" << endl;
	Equipment<Armor> equipmentArmor;
	clothArmor.add_effect("Thorns1", 25);
	clothArmor.add_effect("Thorns2", 50);

	Armor leatherArmor(ArmorType::leather, 500);
	leatherArmor.add_effect("Spikes1", 50);
	leatherArmor.add_effect("Spikes2", 75);

	Armor mailArmor(ArmorType::mail, 750);
	mailArmor.add_effect("Unbreaking1", 100);
	mailArmor.add_effect("Unbreaking2", 125);

	equipmentArmor.add(clothArmor); // should add armor
	equipmentArmor.add(leatherArmor);
	equipmentArmor.add(mailArmor);

	cout << equipmentArmor.is_full() << endl; // should return false(0)

	Armor bestArmor = equipmentArmor.get_best(); // should return mailArmor
	cout << bestArmor.get_score() << endl; // should return 225

	equipmentArmor.remove(2); // should remove mailArmor

	Equipment<Armor> equipmentArmorCopy = equipmentArmor;
	bool areEqual = equipmentArmor == equipmentArmorCopy;
	cout << areEqual << endl; // should return true(1)

	Equipment<Armor> equipmentArmor1;
	equipmentArmor1.add(bestArmor);

	areEqual = equipmentArmor == equipmentArmor1;

	cout << areEqual << endl; // should return false(0)

	bool areDifferent = equipmentArmor != equipmentArmor1;
	cout << areDifferent << endl; // should return true(1)

	//Testing weapon class
	cout << "TESTING WEAPON CLASS" << endl;

	Weapon testWeapon(WeaponKind::dagger, WeaponType::one_handed, 10, 20);
	testWeapon.change_type(); // Should give message and not change the type
	testWeapon.change_kind(WeaponKind::staff); // Should change kind to staff and give message for the type and change it to two-handed
	testWeapon.change_kind(WeaponKind::axe); // Should change to axe and not change type
	testWeapon.add_effect("Smite", 50);
	testWeapon.add_effect("Sharpness", 30);
	cout << testWeapon.get_score() << endl;//Should return ((10 + 20)/2 + 50 + 30)*1.5 = 142.5


	// Testing equipment with weapon class
	cout << "TESTING EQUIPMENT WITH WEAPON" << endl;
	Equipment<Weapon> equipmentWeapon;
	equipmentWeapon.add(testWeapon);
	Equipment<Weapon> equipmentWeaponCopy = equipmentWeapon;
	areEqual = equipmentWeapon == equipmentWeaponCopy;
	cout << areEqual << endl; //Should return true(1)
	Equipment<Weapon> anotherEquipmentWeapon;
	anotherEquipmentWeapon.add(Weapon(WeaponKind::sword, WeaponType::one_handed, 30, 40));
	areDifferent = equipmentWeapon != anotherEquipmentWeapon;
	cout << areDifferent << endl; // should return true(1)

	// Testing Inventory

	cout << "TESTING INVENTORY" << endl;

	Inventory<Equipment<Armor>> inventoryEquipmentArmor1(equipmentArmor);
	Inventory<Equipment<Armor>> inventoryEquipmentArmor2(equipmentArmor);

	areEqual = inventoryEquipmentArmor1 == inventoryEquipmentArmor2;
	cout << areEqual << endl; // should return true(1);

	areDifferent = inventoryEquipmentArmor1 != inventoryEquipmentArmor2;
	cout << areDifferent << endl; // should return false(0);

	cout << inventoryEquipmentArmor1 << endl;

	Inventory<Equipment<Weapon>> inventoryEquipmentWeapon1(equipmentWeapon);
	Inventory<Equipment<Weapon>> inventoryEquipmentWeapon2(equipmentWeapon);
	areEqual = inventoryEquipmentWeapon1 == inventoryEquipmentWeapon2;
	cout << areEqual << endl; // should return true(1);

	areDifferent = inventoryEquipmentWeapon1 != inventoryEquipmentWeapon2;
	cout << areDifferent << endl; // should return false(0);

	cout << inventoryEquipmentWeapon1 << endl;

	Inventory<Backpack<Materials>> invetoryBackpackMaterials1(materialsPack);
	Inventory<Backpack<Materials>> invetoryBackpackMaterials2(materialsPack);
	areEqual = invetoryBackpackMaterials1 == invetoryBackpackMaterials2;
	cout << areEqual << endl; // should return true(1)

	areDifferent = invetoryBackpackMaterials1 != invetoryBackpackMaterials2;
	cout << areDifferent << endl; // should return false(0);

	cout << invetoryBackpackMaterials1 << endl;

	Inventory<Backpack<Money>> invetoryBackpackMoney1(moneyPack);
	Inventory<Backpack<Money>> invetoryBackpackMoney2(moneyPack);

	areEqual = invetoryBackpackMoney1 == invetoryBackpackMoney2;
	cout << areEqual << endl; // should return true(1)

	areDifferent = invetoryBackpackMoney1 != invetoryBackpackMoney2;
	cout << areDifferent << endl; // should return false(0);

	cout << invetoryBackpackMoney1 << endl;

	return 0;
}



