#include <list>
#include <iostream>

using namespace std;

class List {
private:

	list<int> l;

//	CLASS FOR ITERATING OVER LIST
	class Iterator{
		list<int>::iterator it;
	public:
//		CONSTRUCTOR
		explicit Iterator(list<int> lst){
			it = lst.begin();
		}

//		RETURN VALUE
		auto operator*(){
			return *(this->it);
		}
		auto operator++(){ // OPERATOR ++ DOES NOT WORK, i DON'T KNOW WHY
			return it++;
		}
	};

public:
//	ASSIGNMENT
	void operator=(const list<int>& lst) { // NOLINT(misc-unconventional-assign-operator)
		this->l = lst;
	}

//	PUSH_BACK
	list<int> operator+(int value){
		list<int> l1 = this->l;
		l1.push_back(value);
		return l1;
	}
	void operator+=(int value){
		this->l.push_back(value);
	}

//	POP_FRONT
	int operator--(){
		int r = l.front();
		l.pop_front();
		return r;
	}
	void operator-=(int num){
		for (int i = 0; i < num; ++i) {
			operator--();
		}
	}

//	GET_ELEMENT_BY_INDEX
	auto operator[](int index){
		auto it = l.begin();
		for (int i = 0; i < index; ++i) {
			++it;
		}
		return *it;
	}

//	READ/WRITE STREAMS
	void operator>>(int value){
		this->l.push_back(value);
	}
//	void operator<<(const List& lst){
//		string res;
//		auto it = lst.l.begin();
//		for (it; it != lst.l.end(); ++it) {
//			res.append((const char *)*it);
//		}
//	}
//	ZA DA PREDEFINIRAME TAZI OPERACIQ NE TRQBWA LI DA GO NAPRAWIM VYV FUNKCIQ "cout"

//	ITERATOR
	auto operator*(){
		return Iterator(this->l);
	};
};

int main() {
	List l;

//	l = l + 1;
//	l += 2;

//	printf("%d\n", *l);

//	printf("%d\n", --l);
//	printf("%d\n", --l);
//	l -= 2;
//	printf("%d\n", *l);

//	printf("%d", l[0]);
//	printf("%d", l[1]);

//	int a = 1;
//	l >> a;
//	printf("%d", *l);

//	l += 1;
//	l += 2;
//	l += 2;
//
//	auto it = *l;
//	cout << *it;
//	++it;
//	cout << *it;
}
