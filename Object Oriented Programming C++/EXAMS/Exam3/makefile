main: main.cpp Game.o Weapon.o Armor.o
	g++ -o game main.cpp Game.o Weapon.o Armor.o -I.

Game.o: Game.cpp Game.h Item.o
	g++ -c Game.cpp

Soldier.o: Soldier.cpp Soldier.h Item.o
	g++ -c Soldier.cpp

Item.o: Item.cpp Item.h
	g++ -c Item.cpp

Weapon.o: Weapon.cpp Weapon.h Item.o
	g++ -c Weapon.cpp

Armor.o: Armor.cpp Armor.h Item.o
	g++ -c Armor.cpp

clean:
	-rm *.o
	-rm game
