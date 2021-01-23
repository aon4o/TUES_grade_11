#ifndef OOP_HOMEWORK_2_TORRENT_GAME_H
#define OOP_HOMEWORK_2_TORRENT_GAME_H

#include <string>

#include "Torrent.h"

using namespace std;

class Torrent_Game : public Torrent{
private:
	string os;
	char maturity_rating;

public:
	Torrent_Game(const string& name, int size, const string& uploader, int downloads, const string& os, char maturity_rating);
	Torrent_Game(const Torrent_Game &other);

	string getOS() const;
	char getMaturityRating() const;
	string toString() override;
};


#endif //OOP_HOMEWORK_2_TORRENT_GAME_H
