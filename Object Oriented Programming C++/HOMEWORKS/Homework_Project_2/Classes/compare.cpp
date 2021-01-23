#include "compare.h"

#include <string>

using namespace std;

////	TORRENT COMPARISON
bool compareName(const Torrent* first, const Torrent* second) {
	for (int i = 0; (i < first->getName().length()) && (i < second->getName().length()); ++i)
	{
		if (tolower(first->getName()[i]) < tolower(second->getName()[i]))
		{
			return true;
		}
		else if (tolower(first->getName()[i]) > tolower(second->getName()[i]))
		{
			return false;
		}
	}
	return (first->getName().length() < second->getName().length());
}
bool compareSize(const Torrent* first, const Torrent* second) {
	if (first->getSize() < second->getSize())
		return true;
	else
		return false;
}
bool compareUploader(const Torrent* first, const Torrent* second) {
	for (int i = 0; (i < first->getUploader().length()) && (i < second->getUploader().length()); ++i)
	{
		if (tolower(first->getUploader()[i]) < tolower(second->getUploader()[i]))
		{
			return true;
		}
		else if (tolower(first->getUploader()[i]) > tolower(second->getUploader()[i]))
		{
			return false;
		}
	}
	return (first->getUploader().length() < second->getUploader().length());
}
bool compareDownloads(const Torrent* first, const Torrent* second) {
	if (first->getDownloads() < second->getDownloads())
		return true;
	else
		return false;
}

////	GAME COMPARISON
//bool compareOS(const Torrent_Game* first, const Torrent_Game* second) {
//	for (int i = 0; (i < first->getOS().length()) && (i < second->getOS().length()); ++i)
//	{
//		if (tolower(first->getOS()[i]) < tolower(second->getOS()[i]))
//		{
//			return true;
//		}
//		else if (tolower(first->getOS()[i]) > tolower(second->getOS()[i]))
//		{
//			return false;
//		}
//	}
//	return (first->getOS().length() < second->getOS().length());
//}
//bool compareMaturityRating(const Torrent_Game* first, const Torrent_Game* second) {
//	if (first->getMaturityRating() == 'M' and second->getMaturityRating() == 'E')
//	{
//		return true;
//	}
//	else if (first->getMaturityRating() == 'P' and
//	(second->getMaturityRating() == 'E' or second->getMaturityRating() == 'M'))
//	{
//		return true;
//	}
//	return false;
//}
//
////	MOVIE COMPARISON
//bool compareDirector(const Torrent_Movie* first, const Torrent_Movie* second) {
//	for (int i = 0; (i < first->getDirector().length()) && (i < second->getDirector().length()); ++i)
//	{
//		if (tolower(first->getDirector()[i]) < tolower(second->getDirector()[i]))
//		{
//			return true;
//		}
//		else if (tolower(first->getDirector()[i]) > tolower(second->getDirector()[i]))
//		{
//			return false;
//		}
//	}
//	return (first->getDirector().length() < second->getDirector().length());
//}
//bool compareDuration(const Torrent_Movie* first, const Torrent_Movie* second) {
//	if (first->getDuration() < second->getDuration())
//		return true;
//	else
//		return false;
//}
//bool compareLanguage(const Torrent_Movie* first, const Torrent_Movie* second) {
//	for (int i = 0; (i < first->getLanguage().length()) && (i < second->getLanguage().length()); ++i)
//	{
//		if (tolower(first->getLanguage()[i]) < tolower(second->getLanguage()[i]))
//		{
//			return true;
//		}
//		else if (tolower(first->getLanguage()[i]) > tolower(second->getLanguage()[i]))
//		{
//			return false;
//		}
//	}
//	return (first->getLanguage().length() < second->getLanguage().length());
//}
//
////	SOFTWARE COMPARISON
//bool compareManufacturer(const Torrent_Software* first, const Torrent_Software* second) {
//	for (int i = 0; (i < first->getManufacturer().length()) && (i < second->getManufacturer().length()); ++i)
//	{
//		if (tolower(first->getManufacturer()[i]) < tolower(second->getManufacturer()[i]))
//		{
//			return true;
//		}
//		else if (tolower(first->getManufacturer()[i]) > tolower(second->getManufacturer()[i]))
//		{
//			return false;
//		}
//	}
//	return (first->getManufacturer().length() < second->getManufacturer().length());
//}
//bool compareVersion(const Torrent_Software* first, const Torrent_Software* second) {
//	if (first->getVersion() < second->getVersion())
//		return true;
//	else
//		return false;
//}
