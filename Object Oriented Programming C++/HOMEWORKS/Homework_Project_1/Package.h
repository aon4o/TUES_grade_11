#ifndef OOP_HW_1_PACKAGE_H
#define OOP_HW_1_PACKAGE_H

#include <string>

using namespace std;


class Package {
private:
	char* content;

	int content_length;
	string sender_ip;
	string receiver_ip;
	int package_number;
	static int package_counter;

public:
	Package(const string& content, const string& sender_ip, const string& receiver_ip);
	~Package();

	int validate();

	char * get_content() const;
	int get_package_number() const;
	string get_receiver_ip() const;
};


#endif //OOP_HW_1_PACKAGE_H
