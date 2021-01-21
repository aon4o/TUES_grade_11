#ifndef TEST3_WEAPON_H
#define TEST3_WEAPON_H

#include "Item.h"

class Weapon : public Item{
public:
	int damage;

	Weapon() = default;

	int get_power();
};


#endif //TEST3_WEAPON_H
