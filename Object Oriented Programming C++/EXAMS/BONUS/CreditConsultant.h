#ifndef CREDIT_CONSULTANT_CREDITCONSULTANT_H
#define CREDIT_CONSULTANT_CREDITCONSULTANT_H

#include <string>
#include <vector>

#include "BigBank.h"
#include "MiddleBank.h"
#include "SmallBank.h"

using namespace std;

class CreditConsultant {
private:
	string name;
	int commission;
	vector<string> users;
	vector<double> user_earns;
	vector<Bank*> banks;

public:
	CreditConsultant(string  name, int commission);

	void addBank(Bank* bank);
	void getCredit(const string& user, double amount);
	double getTotalEarned() const;
	double getTotalEarned(const string& user);
};


#endif //CREDIT_CONSULTANT_CREDITCONSULTANT_H
