#ifndef TEST3_SOLDIER_H
#define TEST3_SOLDIER_H

#include <string>
#include <list>

#include "Item.h"

using namespace std;

class Soldier {
public:
	string name;
	list<Item> items;

	~Soldier();

	void add_item(const Item* item);
	list<Item> get_items() const;
	int get_power();
};


#endif //TEST3_SOLDIER_H
