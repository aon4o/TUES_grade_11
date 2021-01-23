#ifndef OOP_HOMEWORK_2_TORRENT_H
#define OOP_HOMEWORK_2_TORRENT_H

#include <string>

using namespace std;

class Torrent {
protected:
	string name;
	int size;
	string uploader;
	int downloads;

public:
	Torrent(const string& name, int size, const string& uploader, int downloads);
	Torrent(const Torrent& other) = default;

	string getName() const;
	int getSize() const;
	string getUploader() const;
	int getDownloads() const;

	virtual string toString();
};


#endif //OOP_HOMEWORK_2_TORRENT_H
