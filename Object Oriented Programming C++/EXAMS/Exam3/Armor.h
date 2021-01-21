#ifndef TEST3_ARMOR_H
#define TEST3_ARMOR_H

#include "Item.h"

class Armor : public Item{
public:
	int health;
	int armor;

	Armor(int health, int armor);

	int get_power();
};


#endif //TEST3_ARMOR_H
