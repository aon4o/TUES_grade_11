#include "Package.h"
#include <string>
#include <cstring>

int Package::package_counter = 0;

//	PACKAGE CLASS CONSTRUCTOR
Package::Package(const string& content, const string& sender_ip, const string& receiver_ip) {
	this->content = new char[content.length()];
	for (int i = 0; content[i] != '\0' ; ++i) {
		this->content[i] = content[i];
	}
	this->content_length = content.length();

	this->sender_ip = sender_ip;
	this->receiver_ip = receiver_ip;

	this->package_number = Package::package_counter;
	Package::package_counter++;
}

// PACKAGE CLASS DESTRUCTOR
Package::~Package() {
	delete(this->content);
}

// FUNCTION FOR VALIDATING THE CONTENT LENGTH
int Package::validate() {
	if (strlen(content) == content_length) { return 1; }
	else { return 0; }
}

// SIMPLE GETTER FUNCTIONS
char * Package::get_content() const {
	return content;
}
int Package::get_package_number() const {
	return package_number;
}
string Package::get_receiver_ip() const {
	return this->receiver_ip;
}
