#include "Torrent.h"

#include <utility>
#include <stdexcept>

using namespace std;

Torrent::Torrent(const string& name, int size, const string& uploader, int downloads)
{
	if (name.empty()) {
		throw std::invalid_argument("Invalid 'name'");
	}
	if (size <= 0) {
		throw std::invalid_argument("Unreal 'size': " + to_string(size));
	}
	if (uploader.empty()) {
		throw std::invalid_argument("Empty 'uploader'");
	}
	if (downloads < 0) {
		throw std::invalid_argument("Unreal 'downloads': " + to_string(downloads));
	}

	this->name = name;
	this->size = size;
	this->uploader = uploader;
	this->downloads = downloads;
}

string Torrent::getName() const {
	return name;
}

int Torrent::getSize() const {
	return size;
}

string Torrent::getUploader() const {
	return uploader;
}

int Torrent::getDownloads() const {
	return downloads;
}

string Torrent::toString() {
	return "Name: " + name + " | "
		   + "Size in MB: " + to_string(size) + " | "
		   + "Uploaded by: " + uploader + " | "
		   + "Downloads: " + to_string(downloads);
}
