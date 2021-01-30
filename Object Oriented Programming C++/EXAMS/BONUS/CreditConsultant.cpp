#include "CreditConsultant.h"

#include <utility>
#include <stdexcept>

void CreditConsultant::addBank(Bank* bank) {
	this->banks.push_back(bank);
}

void CreditConsultant::getCredit(const string& user, double amount) {
	int flag = 0;
	int i = 0;
	for (const auto& iter : users) {
		if (iter == user) {
			++flag;
			break;
		}
		++i;
	}

	Bank* bank = banks[0];
	for (auto iter : banks) {
		if (bank->getInterest(amount) > iter->getInterest(amount))
		{
			bank = iter;
		}
	}

	if (flag){
		bank->getCredit(amount);
		user_earns[i] += (amount * (commission/100));
	}
	else {
		users.push_back(user);
		bank->getCredit(amount);
		user_earns.push_back(amount * (commission/100));
	}
}

double CreditConsultant::getTotalEarned() const {
	double res = 0;
	for (auto iter : user_earns) {
		res += iter;
	}
	return res;
}

double CreditConsultant::getTotalEarned(const string& user) {
	int flag = 0;
	int i = 0;
	for (const auto& iter : users) {
		if (iter == user) {
			++flag;
			break;
		}
		++i;
	}

	return user_earns[i];
}

CreditConsultant::CreditConsultant(string name, int commission)
: name(std::move(name)), commission(commission) {
	if (commission < 5 or commission > 10) {
		throw invalid_argument("Commission should be between 5 and 10.");
	}
}
