#include <string>
#include <iostream>

#include "Matrix.h"

using namespace std;

//electricity water heating phone

int main(int argc, char* argv[])
{
//	CHECKING IF A FILE IS GIVEN
	if (argv[1] == nullptr)
	{
		cout << "There's no file given!" << endl;
		return 1;
	}

//	SETTING UP A VECTOR WITH THE SUPPOSED PRICES
	double a[] = {0.129, 1.461, 85.07, 0.132};
	Matrix supposed_prices(a, 4);

//	GETTING THE VALUES OF THE FOR COMPANIES INTO A MATRIX
	Matrix firm_values(argv[1]);

//	GETTING THE REAL PRICES
	Matrix real_prices = firm_values.gaussian_elimination();

//	GETTING A VECTOR OF WHAT SHOULD BE PAID
	Matrix comparison = firm_values.compare_prices(supposed_prices, real_prices);

//	PRINTING THE RESULT
	comparison.print();

	return 0;
}
