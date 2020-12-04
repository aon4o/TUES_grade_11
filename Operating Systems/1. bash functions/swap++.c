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

void swap(void *a, void *b, size_t size);

int main() {
	int a = 5;
	int b = 10;
	printf("a=%d, b=%d\n", a, b);
	swap(&a, &b, sizeof(a));
	printf("a=%d, b=%d\n", a, b);
	return 0;
}

//------------------------------------------------------------------------
// FUNCTION: swap
// the function swaps 2 variables(unknown types)
// PARAMETERS:
// int *a - the address of the first variable we want to swap
// int *b - the address of the second variable we want to swap
//------------------------------------------------------------------------
void swap(void *a, void *b, size_t size){
	unsigned char *x = a;
	unsigned char *y = b;
	unsigned char temp;
	for (int i = 0; i < size; ++i) {
		temp = x[i];
		x[i] = y[i];
		y[i] = temp;
	}
}