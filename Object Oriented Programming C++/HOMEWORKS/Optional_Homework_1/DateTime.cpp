#include "DateTime.h"

#include <stdexcept>

using namespace std;

DateTime::DateTime() {
	year = 1900;
	month = day = hour = minute = second = 0;
}
DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
: year(year+1900), month(month), day(day), hour(hour), minute(minute), second(second) {
	if (year < 0) {
		throw invalid_argument("Invalid 'year': " + to_string(year));
	}
	else if (month < 0 or month > 11) {
		throw invalid_argument("Invalid 'month': " + to_string(month));
	}
	else if (day < 0 or day > 29) {
		throw invalid_argument("Invalid 'day': " + to_string(day));
	}
	else if (hour < 0 or hour > 23) {
		throw invalid_argument("Invalid 'hour': " + to_string(hour));
	}
	else if (minute < 0 or minute> 59) {
		throw invalid_argument("Invalid 'minute': " + to_string(minute));
	}
	else if (second < 0 or second > 59) {
		throw invalid_argument("Invalid 'second': " + to_string(second));
	}
}
DateTime::DateTime(const DateTime& other) {
	year = other.year;
	month = other.month;
	day = other.day;
	hour = other.hour;
	minute = other.minute;
	second = other.second;
}

int DateTime::to_seconds() const {
	return second + minute*60 + hour*60*60 +
	(day+1)*24*60*60 + (month+1)*30*24*60*60 +
	(year)*12*30*24*60*60;
}
bool DateTime::compareDates(const DateTime* first, const DateTime* second) {
	if (*first < *second) {
		return true;
	}
	else {
		return false;
	}
}

bool DateTime::operator==(const DateTime &other) const {
	if (this->to_seconds() == other.to_seconds()) {
		return true;
	}
	else {
		return false;
	}
}
bool DateTime::operator!=(const DateTime &other) const {
	if (this->to_seconds() != other.to_seconds()) {
		return true;
	}
	else {
		return false;
	}
}
bool DateTime::operator>(const DateTime &other) const {
	if (this->to_seconds() > other.to_seconds()) {
		return true;
	}
	else {
		return false;
	}
}
bool DateTime::operator<(const DateTime &other) const {
	if (this->to_seconds() < other.to_seconds()) {
		return true;
	}
	else {
		return false;
	}
}
bool DateTime::operator>=(const DateTime &other) const {
	if (this->to_seconds() >= other.to_seconds()) {
		return true;
	}
	else {
		return false;
	}
}
bool DateTime::operator<=(const DateTime &other) const {
	if (this->to_seconds() <= other.to_seconds()) {
		return true;
	}
	else {
		return false;
	}
}
DateTime DateTime::operator+(const DateTime &other) const {
	DateTime res = DateTime(
			year + other.year - 2*1900,
			month + other.month,
			day + other.day,
			hour + other.hour,
			minute + other.minute,
			second + other.second
			);
	if (res.second >= 59) {
		res.second -= 59;
		++res.minute;
	}
	if (res.minute >= 59) {
		res.minute -= 59;
		++res.hour;
	}
	if (res.hour >= 23) {
		res.hour-= 23;
		++res.day;
	}
	if (res.day >= 29) {
		res.day -= 29;
		++res.month;
	}
	if (res.month >= 11) {
		res.month -= 11;
		++res.year;
	}
	return res;
}
DateTime DateTime::operator-(const DateTime &other) const {
	DateTime res = DateTime(
			year - other.year + 2*1900,
			month - other.month,
			day - other.day,
			hour - other.hour,
			minute - other.minute,
			second - other.second
	);
	if (res.second < 0) {
		res.second += 59;
		--res.minute;
	}
	if (res.minute < 0) {
		res.minute += 59;
		--res.hour;
	}
	if (res.hour < 0) {
		res.hour+= 23;
		--res.day;
	}
	if (res.day < 0) {
		res.day += 29;
		--res.month;
	}
	if (res.month < 0) {
		res.month += 11;
		--res.year;
	}
	return res;
}
ostream& operator<<(ostream& out, DateTime& date) {
	out << to_string(date.year) + "-" +
	to_string(date.month+1) + "-" +
	to_string(date.day+1) + " " +
	to_string(date.hour) + ":" +
	to_string(date.minute) + ":" +
	to_string(date.second);
	return out;
}

void DateTime::sort(list<struct DateTime*>* dates) {
	dates->sort(compareDates);
}
