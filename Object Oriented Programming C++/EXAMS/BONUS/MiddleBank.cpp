#include "MiddleBank.h"

#include <utility>

#include "stdexcept"

MiddleBank::MiddleBank(string name) : Bank(std::move(name)) {}

int MiddleBank::getInterest(double amount) {
	if (amount >= 300000)
		return 7;
	else if (amount >= 100000 and amount < 300000)
		return 2;
	else if (amount < 100000)
		return 8;
}
