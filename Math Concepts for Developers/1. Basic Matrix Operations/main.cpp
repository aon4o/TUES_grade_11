#include <iostream>
#define N 50
using namespace std;

void print (int A[][N], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
bool equal (int A[][N], int m1, int n1, int B[][N], int m2, int n2) {
    if (m1 == m2 and n1 == n2) {
        for (int i = 0; i < m1; ++i) {
            for (int j = 0; j < n1; ++j) {
				if (A[i][j] != B[i][j]) {
					return false;
				}
            }
        }
    } else {
        return false;
    }
	return true;
}
void sum (int A[][N], int B[][N], int C[][N], int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}
void transpose (int A[][N], int B[][N], int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			B[j][i] = A[i][j];
		}
	}
}
void sMult (int A[][N], int R[][N], int m, int n, int s) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			R[i][j] = A[i][j] * s;
		}
	}
}
void sub (int A[][N], int B[][N], int C[][N], int m, int n) {
	int D[m][N];
	sMult(B, D, 3, 3, -1);
	sum(A, D, C, m, n);
}

int main() {
    int A[3][N] = {
            {12, 64, -34},
            {-234, 12, 823},
			{657, 283, -123},
    };
	int B[3][N] = {
			{1, 1, -1},
			{-9, 1, 2},
			{7, 3, -6}
	};
	int C[3][N];

//	if(equal(A, 3, 3, B, 3, 3)) {	//EQUAL TEST
//		cout << "true";
//	} else {
//		cout << "false";
//	}

//	sum( A, B, C, 3, 3);	//SUM TEST
//	print(C, 3, 3);

//	transpose(A, C, 4, 3);	//TRANSPOSE TEST
//	print(C, 3, 4);			//EVEN WORKS WITH NON SQUARE MATRIXES

//	sMult(A, C, 3, 3, 2);	//sMult TEST
//	print(C, 3, 3);

//	sub(A, B, C, 3, 3);		//SUB TEST
//	print(C, 3, 3);
	return 0;
}
