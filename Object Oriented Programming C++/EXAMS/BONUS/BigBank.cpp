#include "BigBank.h"

#include <utility>
#include <stdexcept>

BigBank::BigBank(string name) : Bank(std::move(name)) {}

int BigBank::getInterest(double amount) {
	if (amount >= 300000)
		return 3;
	else if (amount >= 100000 and amount < 300000)
		return 5;
	else if (amount < 100000)
		throw invalid_argument("Credit could not be processed.");
}
