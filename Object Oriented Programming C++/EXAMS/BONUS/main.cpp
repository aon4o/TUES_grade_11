#include <iostream>

#include "CreditConsultant.h"

using namespace std;

int main() {
	CreditConsultant cc = CreditConsultant("Gosho", 6);
	SmallBank small = SmallBank("small");
	MiddleBank middle = MiddleBank("middle");
	BigBank big = BigBank("big");
}
