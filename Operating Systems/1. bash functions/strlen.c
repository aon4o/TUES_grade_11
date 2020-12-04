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

size_t strlen( const char * );

int main() {
	char str[50] = "Hello";
	printf("%lu", strlen(str));
	return 0;
}

//------------------------------------------------------------------------
// FUNCTION: strlen
// the function gets the length of a given string
// PARAMETERS:
// const char * string - the sting we want the length of
//------------------------------------------------------------------------
size_t strlen(const char *string){
	size_t i = 0;
	for (; string[i] != '\0'; ++i);
	return i;
}