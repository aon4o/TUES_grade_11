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

char* strcat( char* destination, const char* source );

int main() {
	char d[50] = "Hello,";
	char s[50] = "world!";
	printf("%s", strcat(d, s));
	return 0;
}

//------------------------------------------------------------------------
// FUNCTION: strcat
// the function sticks 2 strings
// PARAMETERS:
// char * destination - the place we want the second string to come
// const char * source - the string we want to add
//------------------------------------------------------------------------
char* strcat(char *destination, const char *source){
	int i = 0;
	for (; destination[i] != '\0'; ++i);
	for (int j = 0; source[j] != '\0'; ++j) {
		destination[i] = source[j];
		++i;
	}
	return destination;
}