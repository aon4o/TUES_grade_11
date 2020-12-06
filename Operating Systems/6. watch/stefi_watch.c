//------------------------------------------------------------------------
// NAME: Stefani Staykova
// CLASS: XIa
// NUMBER: 19
// FILE NAME: watch.c
// FILE PURPOSE:
// имплементация на функцията watch
//------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
    int status = 0;
    int size = strlen(argv[1]);
    while (1) 
    {
		pid_t id = fork();

		if (id == -1) 
        {
			perror("fork");
		}
		else if (id == 0) 
        {
			int result = execv(argv[1], &(argv[1])); 

            if(result == -1)
            {
                write(1, argv[1], size);
                write(1,": ", 2);
                perror("");
            }

            exit(id);
        }
        else
        {
            waitpid(id, &status, 0);
            sleep(2);
        }
        
    }
}