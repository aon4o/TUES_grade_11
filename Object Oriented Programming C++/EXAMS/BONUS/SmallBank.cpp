#include "SmallBank.h"

#include <utility>
#include <stdexcept>

SmallBank::SmallBank(string name) : Bank(std::move(name)) {}

int SmallBank::getInterest(double amount) {
	if (amount >= 300000)
		throw invalid_argument("Credit could not be processed.");
	else if (amount >= 100000 and amount < 300000)
		return 7;
	else if (amount < 100000)
		return 2;
}
