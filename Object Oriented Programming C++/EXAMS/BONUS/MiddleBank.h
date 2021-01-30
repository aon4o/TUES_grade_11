#ifndef CREDIT_CONSULTANT_MIDDLEBANK_H
#define CREDIT_CONSULTANT_MIDDLEBANK_H

#include "Bank.h"

using namespace std;

class MiddleBank : public Bank {
public:
	MiddleBank(string name);
	int getInterest(double amount) override;
};


#endif //CREDIT_CONSULTANT_MIDDLEBANK_H
