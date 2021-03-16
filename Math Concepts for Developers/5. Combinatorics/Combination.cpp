#include <iostream>

using namespace std;

void print(int* combinations, int k)
{
	for (int i = 0; i < k; ++i) {
		cout << combinations[i] << " ";
	}
	cout << endl;
}

void print_combinations(int* arr, int n, int* combinations, int k, int current)
{
	if (n < k - current)
	{
		return;
	}
	if (current == k)
	{
		print(combinations, k);
		return;
	}

	combinations[current] = arr[0];

	print_combinations(arr+1, n-1, combinations, k, current+1);
	print_combinations(arr+1, n-1, combinations, k, current);
}

void print_combinations(int* arr, int n, int k)
{
	int *combinations = new int[k];
	print_combinations(arr, n, combinations, k, 0);
	delete[] combinations;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	print_combinations(arr, 5, 3);
	return 0;
}
