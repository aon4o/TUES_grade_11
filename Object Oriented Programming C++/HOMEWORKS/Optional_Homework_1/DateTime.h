#ifndef DATETIME_DATETIME_H
#define DATETIME_DATETIME_H

#include <string>
#include <list>

using namespace std;

class DateTime {
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;

	int to_seconds() const;
	static bool compareDates(const DateTime* first, const DateTime* second);

public:
	DateTime();
	DateTime(int year, int month, int day, int hour, int minute, int second);
	DateTime(const DateTime&);

	bool operator==(const DateTime& other) const;
	bool operator!=(const DateTime& other) const;
	bool operator>(const DateTime& other) const;
	bool operator<(const DateTime& other) const;
	bool operator>=(const DateTime& other) const;
	bool operator<=(const DateTime& other) const;
	DateTime operator+(const DateTime& other) const;
	DateTime operator-(const DateTime& other) const;
	friend ostream& operator << (ostream &out, DateTime &date);

	static void sort(list<struct DateTime*>* dates);
};


#endif //DATETIME_DATETIME_H
