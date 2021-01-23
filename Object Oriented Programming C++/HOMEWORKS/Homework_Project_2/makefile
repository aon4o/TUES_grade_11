main: Server main.cpp
	g++ -o main main.cpp Server.o compare.o Torrent.o Torrent_Game.o Torrent_Movie.o Torrent_Software.o -I.

Torrent: Classes/Torrent.h Classes/Torrent.cpp
	g++ -c Classes/Torrent.cpp

Torrent_Game: Torrent Classes/Torrent_Game.h Classes/Torrent_Game.cpp
	g++ -c Classes/Torrent_Game.cpp

Torrent_Movie: Torrent Classes/Torrent_Movie.h Classes/Torrent_Movie.cpp
	g++ -c Classes/Torrent_Movie.cpp

Torrent_Software: Torrent Classes/Torrent_Software.h Classes/Torrent_Software.cpp
	g++ -c Classes/Torrent_Software.cpp

compare: Torrent Torrent_Game Torrent_Movie Torrent_Software Classes/compare.h Classes/compare.cpp
	g++ -c Classes/compare.cpp Torrent.o Torrent_Game.o Torrent_Movie.o Torrent_Software.o

Server: compare Torrent Torrent_Game Torrent_Movie Torrent_Software Classes/Server.h Classes/Server.cpp
	g++ -c Classes/Server.cpp compare.o Torrent.o Torrent_Game.o Torrent_Movie.o Torrent_Software.o

clean:
	-rm *.o
	-rm main