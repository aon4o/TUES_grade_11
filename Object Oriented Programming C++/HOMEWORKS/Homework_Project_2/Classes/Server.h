#ifndef OOP_HOMEWORK_2_SERVER_H
#define OOP_HOMEWORK_2_SERVER_H

#include <string>
#include <list>
#include <vector>

#include "Torrent.h"
#include "Torrent_Game.h"
#include "Torrent_Movie.h"
#include "Torrent_Software.h"

using namespace std;

class Server {
private:
	list<string> users;

	list<Torrent*> torrents;

public:
	vector<Torrent*> searchAll(const string& name);
	vector<Torrent*> searchGame(char maturity_rating);
	vector<Torrent*> searchMovie(const string& director);
	vector<Torrent*> searchSoftware(int major_version);

	void addUser(const string& user);
	void addTorrent(Torrent *torrent);

	void sortByName();
	void sortBySize();
	void sortByUploader();
	void sortByDownloads();

//	void sortByPlatform();
//	void sortByMaturityRating();
//
//	void sortByDirector();
//	void sortByDuration();
//	void sortByLanguage();
//
//	void sortByManufacturer();
//	void sortByOS();
//	void sortByVersion();
};


#endif //OOP_HOMEWORK_2_SERVER_H
