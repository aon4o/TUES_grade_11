#ifndef TEST3_GAME_H
#define TEST3_GAME_H

#include <string>
#include <list>

#include "Soldier.h"

using namespace std;

class Game {
public:
	list<Soldier> soldiers;

	~Game();

	void sort();
	void add_soldier(const Soldier* soldier);
	void fight(const Soldier* attacker, const Soldier* defender);
	void random_fight();
};


#endif //TEST3_GAME_H
