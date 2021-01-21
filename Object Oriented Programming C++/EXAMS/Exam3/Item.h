#ifndef TEST3_ITEM_H
#define TEST3_ITEM_H

#include <string>

using namespace std;

class Item {
public:
	string name;
	int rarity;

	int get_power();
};


#endif //TEST3_ITEM_H
