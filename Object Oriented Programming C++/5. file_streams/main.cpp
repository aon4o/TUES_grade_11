#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Book {
public:
	string title;
	string author;
	int pages{};
	float rating{};
};

class Library {
public:
	list<Book> books;
	void add_book(const Book& b) {
		this->books.push_back(b);
	}
	void save_as_csv(){
		ofstream ostream;
		ostream.open("lib.csv");
		for (int i = 0; i < this->books.size(); ++i) {
			ostream << this->books.front().title << ", ";
			ostream << this->books.front().author << ", ";
			ostream << this->books.front().pages << ", ";
			ostream << this->books.front().rating << endl;
			this->books.pop_front();
		}
		ostream.close();
	}
	static void print_csv() {
		string get;
		ifstream istream;
		istream.open("lib.csv");
		if (istream.is_open()){
			int i = 0;
			while (getline(istream, get, ',')) {
				switch (i) {
					case 0:
						cout << "Title - " << get << ", ";
						++i;
						break;
					case 1:
						cout << "Author - " << get << ", ";
						++i;
						break;
					case 2:
						cout << "Pages - " << get << ", ";
						++i;
						break;
					case 3:
						cout << "Rating - " << get << endl;
						i = 0;
						break;
				}
			}
		}
	}
};

int main() {
	Library library;
	Book book;
	string stop;
	do {
		cout << "Do you want to add another book?" << endl;
		getline(cin, stop);
		if (stop == "no"){break;}

		cout << "Book title: ";
		getline(cin, book.title);
		cout << "Book author: ";
		getline(cin, book.author);
		cout << "Book No. of pages: ";
		cin >> book.pages;
		cout << "Book rating: ";
		cin >> book.rating;

		library.add_book(book);
	} while (true);

	auto it = library.books.begin();
	for (; it != library.books.end(); ++it) {
		cout << it->title << " " << it->author << endl;
	}

	library.save_as_csv();
//	Library::print_csv();
	return 0;
}