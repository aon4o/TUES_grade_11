#include <iostream>

#include "Classes/Server.h"

int main()
{
	Server server = Server();
	server.addUser("shura");
	server.addUser("gosho");

	try
	{
		Torrent torrent = Torrent("32077", 12, "shura", 420);
		Torrent_Game torrent_game = Torrent_Game("62077 game", 30, "gosho", 69, "Win", 'M');
		Torrent_Movie torrent_movie = Torrent_Movie("12077 movie", 20, "shura", 69420, "Shura Shurev", 12, "bg");
		int ver[] = {1,2,3};
		Torrent_Software torrent_software = Torrent_Software("102077 ", 1, "gosho", 42069, "ShuraWare", "mint(debian)", ver);

		server.addTorrent(&torrent);
		server.addTorrent(&torrent_game);
		server.addTorrent(&torrent_movie);
		server.addTorrent(&torrent_software);

////	BASIC SORT TESTS
		server.sortByName();
//		server.sortBySize();
//		server.sortByUploader();
//		server.sortByDownloads();

////	SEARCH BY NAME TEST
		auto res = server.searchAll("20");
		for (auto & r : res) {
			cout << r->toString() << endl;
		}

////	SEARCH BY MATURITY RATING TEST
//		auto res = server.searchGame('M');
//		for (auto & r : res) {
//			cout << r->toString() << endl;
//		}

////	SEARCH BY DIRECTOR TEST	TODO
//		auto res = server.searchMovie("Shura Shurev");
//		for (auto & r : res) {
//			cout << r->toString() << endl;
//		}

////	SEARCH BY MAJOR VERSION TEST TODO
//		auto res = server.searchSoftware(1);
//		for (auto & r : res) {
//			cout << r->toString() << endl;
//		}
	}
	catch(invalid_argument& msg)
	{
		cerr << msg.what() << endl;
	}

	return 0;
}
