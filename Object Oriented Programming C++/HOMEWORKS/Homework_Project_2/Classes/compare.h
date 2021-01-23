#ifndef OOP_HOMEWORK_2_COMPARE_H
#define OOP_HOMEWORK_2_COMPARE_H

#include "Torrent.h"
#include "Torrent_Game.h"
#include "Torrent_Movie.h"
#include "Torrent_Software.h"

bool compareName(const Torrent* first, const Torrent* second);
bool compareSize(const Torrent* first, const Torrent* second);
bool compareUploader(const Torrent* first, const Torrent* second);
bool compareDownloads(const Torrent* first, const Torrent* second);

//bool compareOS(const Torrent_Game* first, const Torrent_Game* second);
//bool compareMaturityRating(const Torrent_Game* first, const Torrent_Game* second);
//
//bool compareDirector(const Torrent_Movie* first, const Torrent_Movie* second);
//bool compareDuration(const Torrent_Movie* first, const Torrent_Movie* second);
//bool compareLanguage(const Torrent_Movie* first, const Torrent_Movie* second);
//
//bool compareManufacturer(const Torrent_Software* first, const Torrent_Software* second);
//bool compareVersion(const Torrent_Software* first, const Torrent_Software* second);

#endif //OOP_HOMEWORK_2_COMPARE_H
