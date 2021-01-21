#include "Weapon.h"

int Weapon::get_power() {
	return this->damage * this->rarity;
}
