#include <iostream>
#include <fstream>

using namespace std;

int main() {
	string name;
	cout << "Enter your name:" << endl;
	getline(cin, name);

	int age;
	cout << "Enter your age:" << endl;
	cin >> age;

	ofstream ostream;
	ostream.open("test.txt");

	ostream << name << endl;
	ostream << age << endl;

	ostream.close();

	ifstream istream;
	istream.open("test.txt");

	string name2;
	getline(istream, name2);

	int age2;
	istream >> age2;

	cout << name2 << endl;
	cout << age2 << endl;

	istream.close();


}
