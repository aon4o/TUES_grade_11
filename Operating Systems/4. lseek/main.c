//------------------------------------------------------------------------
// NAME: Aleksandar Naidenov
// CLASS: XIa
// NUMBER: 1
// PROBLEM: #1
// FILE NAME: main.c
// FILE PURPOSE: da nqmam 2 za godinata
//------------------------------------------------------------------------
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define SIZE sizeof(block)

typedef struct{
	char data;
	unsigned char nextElementAddress;
} block;

int main(int argc, const char **argv)
{
//	CHECKING IF THERE'S EXACTLY ONE FILE PASSED AS AN ARGUMENT
	if (argc != 2)
	{
		const char * msg = "You should give exactly 1 argument!\n";
		write(STDOUT_FILENO, msg, 36);
		return 0;
	}

//	OPENING THE FILE AND CHECKING FOR ERRORS
	int file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		perror("open");
		return 1;
	}

	block buff[SIZE];

//	INITIAL READ
	ssize_t read_result = read(file_descriptor, buff, SIZE);
	if (read_result == -1)
	{
		perror("read");
		return 2;
	}

//	READING AND WRITING FROM THE FILE
	while (buff->nextElementAddress != 0)
	{
//		WRITING
		ssize_t write_result = write(STDOUT_FILENO, &buff->data, sizeof(char));
		if (write_result == -1)
		{
			perror("write");
			return 3;
		}

//		READING NEXT ELEMENT
		lseek(file_descriptor, buff->nextElementAddress, SEEK_SET);
		read_result = read(file_descriptor, buff, SIZE);
		if (read_result == -1)
		{
			perror("read");
			return 2;
		}
	}

//	CLOSING THE FILE AND CHECKING FOR ERRORS
	int close_result = close(file_descriptor);
	if (close_result == -1)
	{
		perror("close");
		return 4;
	}

	return 0;
}