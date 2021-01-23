#ifndef OOP_HOMEWORK_2_TORRENT_SOFTWARE_H
#define OOP_HOMEWORK_2_TORRENT_SOFTWARE_H

#include <string>

#include "Torrent.h"

#define MAJOR 0
#define MINOR 1
#define PATCH 2

class Torrent_Software : public Torrent {
private:
	string manufacturer;
	string os;
	int *version;

public:
	Torrent_Software(
			const string& name,
			int size,
			const string& uploader,
			int downloads,
			string manufacturer,
			const string& os,
			int version[3]
			);
	Torrent_Software(const Torrent_Software& other);

	string getManufacturer() const;
	string getOS() const;
	int getVersion() const;
	string toString() override;
};


#endif //OOP_HOMEWORK_2_TORRENT_SOFTWARE_H
