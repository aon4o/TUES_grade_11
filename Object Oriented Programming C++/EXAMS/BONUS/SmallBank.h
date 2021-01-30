#ifndef CREDIT_CONSULTANT_SMALLBANK_H
#define CREDIT_CONSULTANT_SMALLBANK_H

#include "Bank.h"

using namespace std;

class SmallBank : public Bank {
public:
	SmallBank(string name);
	int getInterest(double amount) override;
};


#endif //CREDIT_CONSULTANT_SMALLBANK_H
