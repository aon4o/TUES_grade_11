//------------------------------------------------------------------------
// NAME: Alexander Naidenov
// CLASS: XIa
// NUMBER: 1
// PROBLEM: #2
// FILE NAME: main.c
// FILE PURPOSE:
// implementation a simple command interpreter
//------------------------------------------------------------------------
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "parse_cmdline.h"

#define SIZE 1

//------------------------------------------------------------------------
// FUNCTION: main
// The main function of a 'C' program.
// PARAMETERS:
// int argc - the number of command line arguments
// char **argv - array storing the command line arguments
//------------------------------------------------------------------------

int main() {
	while (1)
	{
//		SETTING THE NEEDED VARIABLES
		char* buff = (char*) malloc(SIZE);
		ssize_t read_result;
		ssize_t read_bytes = 0;

//		GETTING ARGUMENTS FROM THE COMMAND LINE
		write(STDOUT_FILENO, "$ ", 2);
		do
		{
			read_result = read(STDIN_FILENO, buff+read_bytes, SIZE);
			read_bytes += read_result;
			buff = (char*) realloc(buff, SIZE+read_bytes);

			if (read_result == -1)
			{
				break;
			}
		}
		while (buff[read_bytes-1] != '\n' && read_result != 0);
		if (read_result == -1)
		{
			free(buff);
			perror("read: error reading 'standart input'");
			continue;
		}

//		STOPPING THE PROGRAMME ON CTRL+D
		if (read_result == 0)
		{
			free(buff);
			break;
		}

//		WHITE SPACE CHECK
		int white_space_check = 0;
		for (; buff[white_space_check] == ' '; ++white_space_check);
		if (buff[white_space_check] == '\n')
		{
			free(buff);
			continue;
		}

//		CREATING A CHILD PROCESS AND CHECKING FOR ERRORS
		pid_t proc_id = fork();
		if (proc_id == -1)
		{
			free(buff);
			perror("fork");
			continue;
		}
//		EXECUTES IF THE PROCESS IS A 'CHILD'
		else if (proc_id == 0)
		{
			buff[read_bytes] = '\0';
			char** argv = parse_cmdline(buff);

//			MAKING THE FILENAME
			int start = 0;
			while (buff[start] == ' ')
			{
				++start;
			}
			int end = start;
			while (buff[end] != ' ' && buff[end] != '\n')
			{
				++end;
			}
			char *filename = malloc(end - start);
			for (int i = 0; start < end; ++i)
			{
				filename[i] = buff[start];
				++start;
			}
			filename[start] = '\0';

			int exec_result = execv(filename, &argv[0]);
			if (exec_result == -1)
			{
				perror(filename);
			}
			for (int i =  0; argv[i] != NULL; ++i) {
				free(argv[i]);
			}
			free(filename);
			free(buff);
			free(argv);
			return 0;
		}

		int status;
		pid_t wait_result = waitpid(proc_id, &status, 0);
		if (wait_result == -1)
		{
			perror("wait");
		}

		free(buff);
	}
}
