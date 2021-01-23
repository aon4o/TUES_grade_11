#include "Torrent_Software.h"

#include <stdexcept>

Torrent_Software::Torrent_Software(const string& name, int size, const string& uploader, int downloads, string manufacturer,
								   const string& os, int version[3]) : Torrent(name, size, uploader, downloads) {
	if (manufacturer.empty()) {
		throw invalid_argument("Empty 'manufacturer'");
	}
	if (os.empty()) {
		throw invalid_argument("Empty 'os'");
	}
	if (*version < 0) {
		throw invalid_argument("Invalid 'major version': " + to_string(*version));
	}
	if (*(version+1) < 0) {
		throw invalid_argument("Invalid 'minor version': " + to_string(*(version+1)));
	}
	if (*(version+2) < 0) {
		throw invalid_argument("Invalid 'patch version': " + to_string(*(version+2)));
	}

	this->manufacturer = std::move(manufacturer);
	this->os = os;
	this->version = version;
	this->version[MAJOR] = *version;
	this->version[MINOR] = *(version+1);
	this->version[PATCH] = *(version+2);
}

Torrent_Software::Torrent_Software(const Torrent_Software &other) : Torrent(other) {
	manufacturer = other.manufacturer;
	os = other.os;
	version = other.version;
}

string Torrent_Software::getManufacturer() const {
	return manufacturer;
}

string Torrent_Software::getOS() const {
	return os;
}

int Torrent_Software::getVersion() const {
	return version[0];
}

string Torrent_Software::toString() {
	return Torrent::toString()
		   + " | "+ "Manufacturer: " + manufacturer + " | "
		   + "OS: " + os + " | "
		   + "Version: " + to_string(version[0]) + "." + to_string(version[1]) + "." + to_string(version[2]);
}
