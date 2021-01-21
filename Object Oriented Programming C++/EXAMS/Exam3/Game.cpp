#include "Game.h"
#include "Soldier.h"

void Game::sort() {

}

void Game::add_soldier(const Soldier *soldier) {
	soldiers.emplace_back(*soldier);
}

void Game::fight(const Soldier *attacker, const Soldier *defender) {

}

void Game::random_fight() {

}
