#ifndef MATRICES_PROJECT_1_MATRIX_H
#define MATRICES_PROJECT_1_MATRIX_H

#include <string>
#define N 50

using namespace std;

//electricity water heating phone

class Matrix {
private:
	double matrix[N][N]{};
	int m, n;

public:
	explicit Matrix();
	explicit Matrix(const double vector[], int size);
	explicit Matrix(const string& file);

	Matrix& operator=(const Matrix& m2);
	bool operator==(Matrix& m2);

	void print();
	Matrix& gaussian_elimination();
	Matrix& compare_prices(const Matrix& supposed_prices, const Matrix& real_prices);
};

#endif //MATRICES_PROJECT_1_MATRIX_H
