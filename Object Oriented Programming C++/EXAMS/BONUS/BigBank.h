#ifndef CREDIT_CONSULTANT_BIGBANK_H
#define CREDIT_CONSULTANT_BIGBANK_H

#include "Bank.h"

using namespace std;

class BigBank : public Bank {
public:
	BigBank(string name);
	int getInterest(double amount) override;
};


#endif //CREDIT_CONSULTANT_BIGBANK_H
