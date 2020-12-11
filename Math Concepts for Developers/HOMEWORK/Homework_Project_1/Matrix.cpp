#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;

Matrix::Matrix() {
	m = 0;
	n = 0;
}
Matrix::Matrix(const double *vector, int size) {
	m = size;
	n = 1;
	for (int i = 0; i < size; ++i)
	{
		matrix[i][0] = vector[i];
	}
}
Matrix::Matrix(const string& input_file)
{
//	GETTING THE No. OF LINES IN THE FILE AND SETTING 'm' AND 'n'
	ifstream get_lines_file(input_file);
	if (get_lines_file.is_open()) {
		int file_lines = 0;
		string line;
		while (getline(get_lines_file, line))
		{
			++file_lines;
		}

//		SETTING THE 'M' AND 'N' VALUES OF THE MATRIX
		m = file_lines - 1;
		n = file_lines;

		get_lines_file.close();
		if (get_lines_file.is_open())
		{
			perror("close");
		}
	}
	else
	{
		perror("open");
	}

//	OPENING THE FILE WITH THE NEEDED INFORMATION AND SAVING IT IN FORM OF A MATRIX GOOD FOR GAUSSIAN ELIMINATION
	ifstream file(input_file);
	if (file.is_open())
	{
		string get;

//		GETTING THE SQUARE MATRIX
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (j != m - 1) {
					getline(file, get, ' ');
				} else {
					getline(file, get, '\n');
				}
				matrix[i][j] = stod(get);
			}
		}

//		GETTING THE RESULTS MATRIX
		for (int i = 0; i < m; ++i) {
			getline(file, get, ' ');
			matrix[i][n - 1] = stod(get);
		}

//		CLOSING THE FILE AND CHECKING FOR ERRORS
		file.close();
		if (file.is_open())
		{
			perror("close");
		}
	}
	else
	{
		perror("open");
	}
}

Matrix& Matrix::operator=(const Matrix &m2)
{
	m = m2.m;
	n = m2.n;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			matrix[i][j] = m2.matrix[i][j];
		}
	}

	return *this;
}
bool Matrix::operator==(Matrix& m2) {
	if (m == m2.m and n == m2.n) {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] != m2.matrix[i][j]) {
					return false;
				}
			}
		}
	} else {
		return false;
	}
	return true;
}

void Matrix::print() {
	cout << "Printing matrix -> m: "<< m << " by n: " << n << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
Matrix& Matrix::gaussian_elimination()
{
//	SETTING UP THE NEEDED VALUES
	Matrix m1 = *this;
	auto* answers = new Matrix;
	answers->m = m;
	answers->n = 1;
	double delimiter;

//	PARTIAL PIVOTING
	for (int i = m - 1; i > 0; --i)
	{
		if (m1.matrix[i-1][0] < m1.matrix[i][0])
		{
			for (int j = 0; j <= m; j++)
			{
				delimiter = m1.matrix[i][j];
				m1.matrix[i][j] = m1.matrix[i-1][j];
				m1.matrix[i-1][j] = delimiter;
			}
		}
	}

//	FORWARD ELIMINATION PROCESS
	for (int k = 0; k < m-1; ++k)
	{
		for (int i = k; i <= m-1; ++i)
		{
			delimiter = (m1.matrix[i+1][k] / m1.matrix[k][k]);
			for (int j=0; j <= m; ++j)
			{
				m1.matrix[i+1][j] -= delimiter * m1.matrix[k][j];
			}
		}
	}

//	BACKWARD SUBSTITUTION METHOD
	for (int i = m-1; i >= 0; i--)
	{
		delimiter = 0;
		for (int j=i; j <= m-1; j++)
		{
			delimiter = delimiter + (m1.matrix[i][j] * answers->matrix[j][0]);
		}
		answers->matrix[i][0] = (m1.matrix[i][m] - delimiter) / m1.matrix[i][i];
	}

	return *answers;
}
Matrix& Matrix::compare_prices(const Matrix& supposed_prices, const Matrix& real_prices)
{
//	SETTING UP THE MATRIX FOR RETURNING
	auto* final_price_difference = new Matrix();
	final_price_difference->m = n;
	final_price_difference->n = m;

//	GETTING THE FIRST LINE OF THE FINAL ANSWER
	for (int i = 0; i < m; ++i)
	{
		final_price_difference->matrix[0][i] = matrix[i][n-1];
	}
	double subtrahend = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			subtrahend += matrix[i][j] * supposed_prices.matrix[j][0];
		}
		final_price_difference->matrix[0][i] -= subtrahend;
		subtrahend = 0;
	}

//	GETTING THE OTHER 4 LINE OF THE FINAL ANSWER
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			final_price_difference->matrix[i+1][j] =
					(matrix[i][j] * real_prices.matrix[j][0] -
					matrix[i][j] * supposed_prices.matrix[j][0]) /
					real_prices.matrix[j][0];
		}
	}

	return *final_price_difference;
}
