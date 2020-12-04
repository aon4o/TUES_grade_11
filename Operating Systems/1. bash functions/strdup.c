//------------------------------------------------------------------------
// NAME: Aleksandar Naidenov
// CLASS: XIa
// NUMBER: 1
// PROBLEM: #1
// FILE NAME: main.c (unix file name)
// FILE PURPOSE:
// da nqam 2ka
//------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

char *strdup( const char * );

int main() {
	char string[10] = "MSG?!";
	char *p = strdup(string);
	printf("%s", p);
	return 0;
}

//------------------------------------------------------------------------
// FUNCTION: strdup
// the function returns a duplicate of a given string in dynamic structure
// PARAMETERS:
// const char * string - a pointer to the string we want to duplicate
//------------------------------------------------------------------------
char *strdup( const char * string){
	size_t size = 0;
	for (; string[size] != '\0'; ++size);
	char *p = malloc(size);
	for (int i = 0; i < size; ++i) {
		p[i] = string[i];
	}
	return p;
}