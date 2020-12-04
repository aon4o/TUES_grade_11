#include <iostream>
#define N 50

using namespace std;

void print_double (double A[][N], int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

//	FUNCTION PRINTING THE RESULT OF GAUSSIAN_ELIMINATION
void gaussian_elimination (double a[][N], int n)
{
//	MAKING DIAGONAL MATRIX
	for (int i = 0; i < n-1; ++i) { //rows
		for (int j = i+1; j < n; ++j) { //cols

//			CASE 0
			int counter = 0;
			do {
				for (int k = i; k < n; ++k) {
					if (a[i][k] == 0) ++counter;
				}
				if (counter > i)
				{
					for (int k = 0; k < n; ++k) {
						a[i][k], a[i+1][k] = a[i+1][k], a[i][k];
					}
				}
			}while (counter > i);

			double delimiter = -(a[j][i]/a[i][i]);
			for (int k = i; k < n+1; ++k) {
				a[j][k] += delimiter*a[i][k];
			}
		}
	}

//	PRINT THE DIAGONAL MATRIX FOR TESTING
	print_double(a, n, n+1);

//	INITIALIZING THE ARRAY WITH X'S (THE ANSWERS)
	double x[N] = {0};

//	GETTING THE X'S
	for (int i = n-1; i >= 0; --i) {
		x[i] = a[i][n] / a[i][i];
		for (int j = n-1; i < j; --j) {
			x[i] -= (x[j] * a[i][j]) / a[i][i];
		}
	}

//	PRINTING THE X'S
	for (int i = 0; i < n; ++i) {
		cout << "x" << i+1 << " = " << x[i] << endl;
	}
}

int main() {
//	INPUT FOR A MATRIX
//
//	int n = 0;
//	cin >> n;
//	double A[][N];
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < n+1; ++j) {
//			cin >> A[i][j];
//		}
//	}

//	EXERCISE 1
//	double A[][N]={
//			{1, 3, 13},
//			{2, -4, 6}
//	};
//	gaussian_elimination(A, 2);

//	EXERCISE 2
//	double A[][N]={
//			{2, 5, -3, 2, 7, -9},
//			{13, -1, -6, 9, -7, 39},
//			{-5, -9, 1, -5, -8, -2},
//			{3, 32, 16, 3, 15, 25},
//			{-7, 6, 8, -4, 2, -28}
//	};
//	gaussian_elimination(A, 5);

//	HOMEWORK 1
//	double A[][N]={
//			{1.2, 4.135, 2.613, 31.18027},
//			{-3.851, -2.719, 16.712, -51.40619},
//			{2.314, 23.187, 5.617, -15.98744}
//	};
//	gaussian_elimination(A, 3);

//	HOMEWORK 2
	double A[][N]={
			{2, 2, 1, 14},
			{1, 1, -1, -11},
			{4, 2, 3, 44}
	};
	gaussian_elimination(A, 3);

	return 0;
}