#include <iostream>

using namespace std;

class Bank_Account
{
private:
	int id;
	string customer;
	double amount;
public:
	Bank_Account(int id, string customer, double amount)
	{
		this->id = id;
		this->customer = customer;
		this->amount = amount;
	}
	auto operator=(const Bank_Account& b)
	{
		this->id = b.id;
		this->customer = b.customer;
		this->amount = b.amount;
	}
	auto operator>(const Bank_Account& b) const
	{
		if (this->amount > b.amount)
		{
			return true;
		}
		else if (this->amount == b.amount)
		{
			return this->id > b.id;
		}
		else
		{
			return false;
		}
	}
	auto operator<(const Bank_Account& b) const
	{
		if (this->amount < b.amount)
		{
			return true;
		}
		else if (this->amount == b.amount)
		{
			return this->id < b.id;
		}
		else
		{
			return false;
		}
	}
	auto operator==(const Bank_Account& b) const
	{
		return this->id == b.id;
	}
	auto operator<<(double money)
	{
		this->amount += money;
		printf("%f leva added to the acc.\nBalance is %f.", money, this->amount);
	}
};

class Bank
{
private:
	Bank_Account accounts;
	int arr_size = 0;
	int account_count = 0;
	bool sort = true;

public:
//	Bank(){}
//	Bank(bool sort_bool)
//	{
//		this->sort = sort_bool;
//	}
	auto size() const
	{
		return account_count;
	}
	auto capacity() const
	{
		return arr_size;
	}
//	auto shrink_to_fit()
//	{
//
//	}
//	auto add(const Bank_Account& b)
//	{
//		if (this->size == this->account_count)
//		{
//			this->size += 10;
//			Bank_Account *buff = new Bank_Account[size];
//		}
//	}
};

int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
