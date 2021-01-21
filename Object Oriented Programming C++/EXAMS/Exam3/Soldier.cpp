#include "Soldier.h"

void Soldier::add_item(const Item *item) {
	if (items.size() < 6)
	{
		items.emplace_back(*item);
	}
	else
	{
		int min_power = items.begin()->get_power();
		int index = 0;

		auto iter = items.begin();
		for (int i = 0; i < 6; ++i) {
			if (min_power > iter->get_power()){
				min_power = iter->get_power();
				index = i;
			}
			++iter;
		}

		iter = items.begin();
		for (int i = 0; i < index; ++i) {
			++iter;
		}
		*iter = *item;
	}
}

list<Item> Soldier::get_items() const {
	return items;
}

int Soldier::get_power() {
	int power = 0;
	for (auto& iter : items) {
		power += iter.get_power();
	}

	return power;
}
