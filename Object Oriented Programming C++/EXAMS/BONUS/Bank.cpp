#include "Bank.h"

#include <stdexcept>

Bank::Bank(const string& name) : name(name), earned(0) {
	if (name.empty())
		throw invalid_argument("Name should not be empty.");
}

double Bank::getTotalEarned() const {
	return this->earned;
}

double Bank::getQuote(double amount) {
	return amount + amount * (getInterest(amount)/100);
}

void Bank::getCredit(double amount) {
	this->earned += (amount * (getInterest(amount)/100));
}
