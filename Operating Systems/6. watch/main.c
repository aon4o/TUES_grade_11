//------------------------------------------------------------------------
// NAME: Alexander Naidenov
// CLASS: XIa
// NUMBER: 1
// FILE NAME: main.c
// FILE PURPOSE:
// implementation of unix function 'watch'
//------------------------------------------------------------------------

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

//------------------------------------------------------------------------
// FUNCTION: main
// The main function of a 'C' program.
// PARAMETERS:
// int argc - the number of command line arguments
// char **argv - array storing the command line arguments
//------------------------------------------------------------------------

int main(int argc, char **argv)
{
	while (1)
	{
//		CREATING THE CHILD PROCESS
		pid_t proc_id = fork();

//		EXECUTES IF THE PROGRAMME COULD NOT FORK PROPERLY
		if (proc_id == -1)
		{
			perror("fork");
			sleep(2);
		}
//		EXECUTES IF THE PROCESS IS A 'CHILD'
		else if (proc_id == 0)
		{
			int exec_result = execv(argv[1], &argv[1]);
			if (exec_result == -1)
			{
				perror(argv[1]);
			}
			return 0;
		}
//		EXECUTES IF THE PROCESS IS A 'PARENT'
		else
		{
			int status;
			pid_t wait_result = waitpid(proc_id, &status, 0);
			if (wait_result == -1)
			{
				perror("");
			}
			sleep(2);
		}
	}
}