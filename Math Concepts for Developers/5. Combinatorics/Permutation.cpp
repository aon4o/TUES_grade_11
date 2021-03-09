#include <iostream>

using namespace std;

void printPermutations(int arr[], int start, int size)
{

//	CHECKING FOR INVALID START
	if (start > size-1)
	{
		perror("Cannot start from there!");
		return;
	}

//	CHECKING FOR PERMUTATION FROM 1
	if (start == size-1)
	{
		for (int i = 0; i < size; ++i) {
			cout<< arr[i] << " ";
		}
		cout << endl;
		return;
	}

//	SWAPPING AND RECURSION
	for (int i = start; i < size; ++i)
	{
		swap(arr[start], arr[i]);

		printPermutations(arr, start+1, size);

		swap(arr[start], arr[i]);
	}
}

int main()
{
	int arr[] = {1,2,3,4};
	printPermutations(arr, 0, 4);

//	int arr[] = {1,2,3};
//	printPermutations(arr, 0, 3);

	return 0;
}