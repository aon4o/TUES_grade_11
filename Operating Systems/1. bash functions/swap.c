//------------------------------------------------------------------------
// NAME: Aleksandyr Naidenov
// CLASS: XIa
// NUMBER: 1
// PROBLEM: #1
// FILE NAME: main.c (unix file name)
// FILE PURPOSE:
// da nqmam 2ka
//------------------------------------------------------------------------
#include <stdio.h>

void swap(int *a, int *b);

int main() {
	int a = 5;
	int b = 10;
	printf("a=%d, b=%d\n", a, b);
	swap(&a, &b);
	printf("a=%d, b=%d\n", a, b);
	return 0;
}

//------------------------------------------------------------------------
// FUNCTION: swap
// the function swaps 2 integers
// PARAMETERS:
// int *a - the address of the first int we want to swap
// int *b - the address of the second int we want to swap
//------------------------------------------------------------------------
void swap(int *a, int *b){
	int i = *a;
	*a = *b;
	*b = i;
}