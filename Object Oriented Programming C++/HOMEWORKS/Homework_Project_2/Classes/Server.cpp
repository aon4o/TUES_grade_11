#include "Server.h"
#include "compare.h"

#include <stdexcept>

using namespace std;

//	SEARCH METHODS
vector<Torrent*> Server::searchAll(const string &name) {
	vector<Torrent*> result;
	for (auto& torrent : torrents) {
		if (torrent->getName().find(name) != string::npos) {
			result.push_back(torrent);
		}
	}
	return result;
}
vector<Torrent*> Server::searchGame(char maturity_rating) {
	vector<Torrent*> result;
	for (auto& game : torrents) {
		if (((Torrent_Game*)game)->getMaturityRating() == toupper(maturity_rating)) {
			result.push_back(game);
		}
	}
	return result;
}
vector<Torrent*> Server::searchMovie(const string& director) {
	vector<Torrent*> result;
	for (auto& movie : torrents) {
		if (((Torrent_Movie*)movie)->getDirector() == director) {
			result.push_back(movie);
		}
	}
	return result;
}
vector<Torrent*> Server::searchSoftware(int major_version) { //TODO
	vector<Torrent*> result;
	for (auto& program : torrents) {
		if (((Torrent_Software*)program)->getVersion() == major_version) {
			result.push_back(program);
		}
	}
	return result;
}

//	ADD METHODS
void Server::addUser(const string& user) {
	users.push_back(user);
}
void Server::addTorrent(Torrent *torrent) {
	bool flag = true;
	for (auto& user : users) {
		if (user == torrent->getUploader())
			flag = false;
	}
	if (flag) {
		throw invalid_argument("Invalid 'uploader', not registered: " + torrent->getUploader());
	}
	torrents.push_back(torrent);
}

//	SORT METHODS
void Server::sortByName() {
	torrents.sort(compareName);
}
void Server::sortBySize() {
	torrents.sort(compareSize);
}
void Server::sortByUploader() {
	torrents.sort(compareUploader);
}
void Server::sortByDownloads() {
	torrents.sort(compareDownloads);
}

//void Server::sortByPlatform() {
//	torrents.sort(compareOS);
//}
//void Server::sortByMaturityRating() {
//	torrents.sort(compareMaturityRating);
//}
//
//void Server::sortByDirector() {
//	torrents.sort(compareDirector);
//}
//void Server::sortByDuration() {
//	torrents.sort(compareDuration);
//}
//void Server::sortByLanguage() {
//	torrents.sort(compareLanguage);
//}
//
//void Server::sortByManufacturer() {
//	torrents.sort(compareManufacturer);
//}
//void Server::sortByOS() {
//	torrents.sort(compareOS);
//}
//void Server::sortByVersion() {
//	torrents.sort(compareVersion);
//
//}
