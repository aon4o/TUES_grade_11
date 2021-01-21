#include "Armor.h"

Armor::Armor(int health, int armor) {
	this->health = health;
	this->armor = armor;
}

int Armor::get_power() {
	return (health + armor) * rarity;
}
