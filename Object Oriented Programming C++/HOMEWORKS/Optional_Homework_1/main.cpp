#include <iostream>

#include "DateTime.h"

using namespace std;

int main() {
	try {
		list<DateTime*> dates;

		DateTime a = DateTime(2, 2, 2, 2, 2, 2);
		DateTime b = DateTime(3, 3, 3, 3, 3, 3);
		DateTime c = DateTime(1, 1, 1, 1, 1, 1);
		DateTime d = b + c;

		dates.push_back(&d);
		dates.push_back(&a);
		dates.push_back(&b);
		dates.push_back(&c);

		if (a > b) cout << "true" << endl;
		else cout << "false" << endl;

//		PRINT BEFORE SORT
		cout << "Before Sort" << endl;
		for (auto& date : dates) {
			cout << *date << endl;
		}

//		SORT
		DateTime::sort(&dates);

//		PRINT AFTER SORT
		cout << "After Sort" << endl;
		for (auto& date : dates) {
			cout << *date << endl;
		}
	}
	catch (invalid_argument& msg) {
		cerr << msg.what() << endl;
	}

	return 0;
}
