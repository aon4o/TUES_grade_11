#include <iostream>
#define N 50
using namespace std;

typedef int matrix[][N];
void print (int A[][N], int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
int vectorMult(const int A[], const int B[], int n1, int n2){
	if(n1 != n2){
		cout << "The Vectors doesn't have the same length!" << endl;
		return 0;
	}
	int c = 0;
	for (int i = 0; i < n1; ++i) {
		c += A[i] * B[i];
	}
	return c;
}
void vectorMatrixMult(const int A[], int B[][N], int C[], int v, int m1, int m2){
	if(v != m2){
		cout << "The Vector and the Matrix are not multipliable!" << endl;
	}
	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < m2; ++j) {
			for (int k = 0; k < m2; ++k) {
				C[i] += A[i] * B[j][k];
			}
		}
	}
}
void MatrixMult(const int A[][N], int B[][N], int C[][N], int n1, int m1, int n2, int m2){
	if(m1 != n2){
		cout << "The Matrixes are not multipliable!" << endl;
		return;
	}
	else {
		for (int i = 0; i < n1; ++i) {
			for (int j = 0; j < m2; ++j) {
				C[i][j] = 0;
				for (int k = 0; k < m1; ++k) {
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
	}
}

int main() {
	matrix A = {
			{1, 1, 1},
			{1, 1, 1},
			{1, 1, 1}
	};
	matrix B = {
			{1, 1, 2},
			{1, 1, 2},
			{1, 1, 2}
	};
	int C[N][N];

//	TEST VECTOR * MATRIX
//	vectorMatrixMult(A, B, C, 3, 2, 3);
//	for (int i = 0; i < 10; ++i) {
//		cout << C[i] << endl;
//	}

	MatrixMult(A,B,C,3,3,3,3);
	print(C,3,3);

	return 0;
}