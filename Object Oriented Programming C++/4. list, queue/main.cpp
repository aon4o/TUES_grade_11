#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class Product{
public:
	string name;
	int quantity{};
};
class Purchase{
public:
	Product product;

	bool done = false;
	Purchase(Product product, bool done) {
		this->product = product;
		this->done = done;
	}
	Purchase() {}
};
class Fabric{
public:
	Product products[10];
};

int main() {
	queue<Product> purchases;
	Product product;
	Purchase check;

	Fabric f1;
	f1.products[0] = {"meat", 10};
	f1.products[1] = {"milk", 7};
	f1.products[2] = {"eggs", 4};
	f1.products[3] = {"condoms", 11};

	while (true){
		cout << "Enter the wanted product name:\n";
		cin >> product.name;
		transform(product.name.begin(), product.name.end(), product.name.begin(), ::tolower);
		if (product.name == "stop"){
			break;
		}
		cout << "Enter the wanted product quantity:\n";
		cin >> product.quantity;
		purchases.push(product);
	}

	list<Purchase> done_purchases;
	list<Purchase> not_done_purchases;
	for (int i = 0; i < purchases.size(); ++i) {
		check.product.name = purchases.front().name;
		check.product.quantity = purchases.front().quantity;
		for (int j = 0; j < 10; ++j) {
			if(f1.products[j].name == check.product.name) {
				if (f1.products[j].quantity >= check.product.quantity) {
					check.done = true;
					break;
				}
			}
		}
		if (check.done == true){
			done_purchases.emplace_back(check);
		} else{
			check.done = false;
			not_done_purchases.emplace_back(check);
		}
		purchases.pop();
	}

	//	TEST
	_List_iterator<Purchase> p = done_purchases.begin();
	cout << "Completed purchases:" << endl;
	for (int i = 0; i < done_purchases.size(); ++i) {
		cout << p->product.name << " " << p->product.quantity << endl;
		++p;
	}
	p = not_done_purchases.begin();
	cout << endl << "Not Completed purchases:" << endl;
	for (int i = 0; i < not_done_purchases.size(); ++i) {
		cout << p->product.name << " " << p->product.quantity << endl;
		++p;
	}
	return 0;
}
