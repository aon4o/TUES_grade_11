//------------------------------------------------------------------------
// NAME: Aleksandar Naidenov
// CLASS: XIa
// NUMBER: 1
// PROBLEM: #1
// FILE NAME: main.c (unix file name)
// FILE PURPOSE:
// da imam poveche ot 3
//------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	size_t size;
	size_t capacity;
	int *elements;
} stack;

void stack_init( stack * );
void stack_destroy( stack * );

int stack_empty( stack * );
void stack_push( stack *, int );
int stack_top( stack * );
void stack_pop( stack * );

int main(int argc, const char* argv[]) {
	return 0;
}

//------------------------------------------------------------------------
// FUNCTION: stack_init
// the function initializes a stack structure
// PARAMETERS:
// stack* s - the stack we want to initialise
//------------------------------------------------------------------------
void stack_init(stack* s){
	s->size = 0;
	s->capacity = 0;
	s->elements = NULL;
}
//------------------------------------------------------------------------
// FUNCTION: stack_empty
// the function empties a given stack
// PARAMETERS:
// stack* s - the stack we wanna' empty up
//------------------------------------------------------------------------
int stack_empty(stack* s){
	return s->size == 0;
}
//------------------------------------------------------------------------
// FUNCTION: stack_push
// the function pushes a given element into a given stack
// PARAMETERS:
// stack* s - the stack we wanna' push in
// int value - the value we want to push
//------------------------------------------------------------------------
void stack_push(stack* s, int value){
	if (s->capacity < s->size + 1){
		s->capacity = s->capacity == 0 ? 2 : s->capacity * 2;
		s->elements = realloc(s->elements, s->capacity * sizeof(s->capacity));
	}
	s->elements[s->size] = value;
	s->size++;
}
//------------------------------------------------------------------------
// FUNCTION: stack_top
// the function returns the last element in the stack
// PARAMETERS:
// stack* s - the stack we want to read from
//------------------------------------------------------------------------
int stack_top (stack* s){
	if (s->elements == NULL){ return 0; }
	if (s->size == 0){ return 0; }
	return s->elements[s->size - 1];
}
//------------------------------------------------------------------------
// FUNCTION: stack_pop
// the function removes the last element in a given stack
// PARAMETERS:
// stack* s - the stack we wanna' pop from
//------------------------------------------------------------------------
void stack_pop(stack* s) {
	if (s->elements == NULL){return;}
	else if (s->size == 0){return;}
	else{
		s->size -= 1;
	}
}
//------------------------------------------------------------------------
// FUNCTION: stack_destroy
// the function frees the malloced space of a given stack
// PARAMETERS:
// stack* s - the stack we want to destroy
//------------------------------------------------------------------------
void stack_destroy(stack * s){
	free(s->elements);
	s->elements = NULL;
	s->size = 0;
	s->capacity = 0;
}