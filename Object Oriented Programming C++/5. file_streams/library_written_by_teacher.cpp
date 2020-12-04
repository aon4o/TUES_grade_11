#include<iostream>
#include<fstream>
#include<list>
#include<string>

using namespace std;

class Book
{
	public:
		string title;
		string author;
		int pages;
		int mark;
};

class Library
{
	private:
		list<class Book> books;
	
	public:
		void add_book(class Book b)
		{
			this->books.push_back(b);
		}

		void save_as_csv()
		{
			ofstream ostream;
			ostream.open("library.csv");
			for(list<class Book>::iterator it= this->books.begin(); it!=this->books.end(); it++)
			{
				ostream<<(*it).title<<endl;
				ostream<<(*it).author<<endl;
				ostream<<(*it).pages<<endl;
				ostream<<(*it).mark<<endl;
			}
			ostream.close();		
		}
};


int main()
{
	class Library Sofiq;
	while(true)
	{
		class Book b1;

		cout<<"Title: ";
		getline(cin, b1.title);
		if(b1.title=="Stop")
		{
			break;
		}

		cout<<"Author: ";
		getline(cin, b1.author);

		cout<<"Pages: ";
		cin>>b1.pages;
		cout<<"Mark: ";
		cin>>b1.mark;
		cin.ignore();
		
		Sofiq.add_book(b1);
	}
	Sofiq.save_as_csv();
	
	

	ifstream istream;
	istream.open("library.csv");
	int i=0;
	string title1;
	while(getline(istream, title1))
	{
		cout<<title1<<endl;
	}
	

	istream.close();

	/*ifstream istream;
	istream.open("library.csv");
	int i=0;
	string title1;
	string author1;
	int pages1;
	int mark1;
	while(true)
	{
		i++;
		
		getline(istream, title1);
		if(title1=="")
		{
			break;
		}	
		
		
		getline(istream, author1);

		
		istream >> pages1;
		
		
		istream >> mark1;
		cout << "Title read:" << title1 << endl;
		cout << "Author read:" << author1 << endl;
		cout << "Pages read:" << pages1 << endl;
		cout << "Mark read:" << mark1 << endl;
		istream.ignore();
	}
	

	istream.close();*/

	return 0;
}
