#include "Torrent_Movie.h"

#include <stdexcept>

Torrent_Movie::Torrent_Movie(const string& name, int size, const string& uploader, int downloads,
							 const string& director, int duration, const string& language)
							 : Torrent(name, size, uploader, downloads){
	if (director.empty()) {
		throw invalid_argument("Empty 'director'");
	}
	if (duration <= 0) {
		throw invalid_argument("Invalid 'duration': " + to_string(duration));
	}
	if (language.empty()) {
		throw invalid_argument("Empty 'language'");
	}

	this->director = director;
	this->duration = duration;
	this->language = language;
}

Torrent_Movie::Torrent_Movie(const Torrent_Movie &other) : Torrent(other) {
	this->director = other.director;
	this->duration = other.duration;
	this->language = other.language;
}

string Torrent_Movie::getDirector() const {
	return director;
}

int Torrent_Movie::getDuration() const {
	return duration;
}

string Torrent_Movie::getLanguage() const {
	return language;
}

string Torrent_Movie::toString() {
	return Torrent::toString()
		   + " | " + "Director: " + director + " | "
		   + "Duration: " + to_string(duration) + " | "
		   + "Language: " + language;
}
