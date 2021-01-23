#include "Torrent_Game.h"

#include <stdexcept>

Torrent_Game::Torrent_Game(const string& name, int size, const string& uploader, int downloads, const string& os, char maturity_rating)
: Torrent(name, size, uploader, downloads) {
	if (os.empty()) {
		throw invalid_argument("Empty 'platform'");
	}
	if (maturity_rating == ' ') {
		throw invalid_argument("Empty 'maturity rating'");
	}
	else if (maturity_rating != 'E' and maturity_rating != 'M' and maturity_rating != 'P') {
		throw invalid_argument("Invalid 'maturity rating'");
	}

	this->os = os;
	this->maturity_rating = maturity_rating;
}

Torrent_Game::Torrent_Game(const Torrent_Game &other) :	Torrent(other)
{
	os = other.os;
	maturity_rating = other.maturity_rating;
}

string Torrent_Game::getOS() const {
	return os;
}

char Torrent_Game::getMaturityRating() const {
	return maturity_rating;
}

string Torrent_Game::toString() {
	return Torrent::toString()
	+ " | " + "OS: " + os + " | "
	+ "Maturity: " + maturity_rating;
}
