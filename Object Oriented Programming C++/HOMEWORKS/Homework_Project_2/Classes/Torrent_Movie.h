#ifndef OOP_HOMEWORK_2_TORRENT_MOVIE_H
#define OOP_HOMEWORK_2_TORRENT_MOVIE_H

#include <string>

#include "Torrent.h"

using namespace std;

class Torrent_Movie : public Torrent{
private:
	string director;
	int duration;
	string language;

public:
	Torrent_Movie(
			const string& name,
			int size,
			const string& uploader,
			int downloads,
			const string& director,
			int duration,
			const string& language
			);
	Torrent_Movie(const Torrent_Movie& other);

	string getDirector() const;
	int getDuration() const;
	string getLanguage() const;
	string toString() override;
};


#endif //OOP_HOMEWORK_2_TORRENT_MOVIE_H
