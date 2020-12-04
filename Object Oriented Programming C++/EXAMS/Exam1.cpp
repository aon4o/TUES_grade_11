#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Animal{
private:
	int id;
	string name;
	int age;
	float monthlyExpenses;
	string type;
public:
	Animal(){};
	Animal(int id, string name, int age, float monthlyExpenses, string type){
		this->id = id;
		this->name = name;
		this->age = age;
		this->monthlyExpenses = monthlyExpenses;
		this->type = type;
	};
	int get_id(){return this->id;}
	void set_id(int id){this->id = id;}
	string get_name(){return this->name;}
	void set_name(string name){this->name = name;}
	int get_age(){return this->age;}
	void set_age(int age){this->age = age;}
	double get_monthlyExpenses(){return this->monthlyExpenses;}
	void set_monthlyExpenses(double monthlyExpenses){this->monthlyExpenses = monthlyExpenses;}
	string get_type(){return this->type;}
	void set_type(string type){this->type = type;}
};

class Cage{
private:
	int id;
	list<Animal> animals;
	int capacity;
	string type;
public:
	Cage(){}
	Cage(int id, int capacity, string type){
		this->id = id;
		this->capacity = capacity;
		this->type = type;
	}
	int get_id(){return this->id;}
	void set_id(int id){this->id = id;}
	int get_capacity(){return this->capacity;}
	void set_capacity(int capacity){this->capacity = capacity;}
	string get_type(){return this->type;}
	void set_type(int type){this->type = type;}

	void addAnimal(Animal animal){
		try {
			if (this->getRemainingCapacity() > 0){
				if (animal.get_type() != this->get_type()){
					throw "Error: The animal you want to add is not the same type as the animals in the cage!";
				} else{
					this->animals.push_back(animal);
				}
			} else {
				throw "Error: Cannot add animal - the cage is full!";
			}
		} catch (string e) {
			cout << e << endl;
		}
	}
	double getMonthlyTotal(){
		double expenses = 0;
		for (list<Animal>::iterator it = this->animals.begin(); it != this->animals.cend(); ++it) {
			expenses += it->get_monthlyExpenses();
		}
		return expenses;
	}
	int getRemainingCapacity(){
		int count = 0;
		list<Animal>::iterator it = this->animals.begin();
		while (it != this->animals.cend()){
			++count;
			++it;
		}
		return this->capacity - count;
	}
};

int main(int argc, char *argv[]) {
	ofstream read;
	try {
		if (argc != 3) {
			throw "Error: There should be 2 arguments - file to write and file to read!";
		}
	}
	catch(const char *e){
		cout << e << endl;
	}
	return 0;
}
