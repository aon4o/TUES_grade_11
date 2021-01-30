#ifndef CREDIT_CONSULTANT_BANK_H
#define CREDIT_CONSULTANT_BANK_H

#include <string>

using namespace std;

class Bank {
private:
	string name;
	double earned;

public:
	Bank(const string& name);

	virtual int getInterest(double amount) = 0;
	double getTotalEarned() const;
	double getQuote(double amount);
	void getCredit(double amount);
};


#endif //CREDIT_CONSULTANT_BANK_H
