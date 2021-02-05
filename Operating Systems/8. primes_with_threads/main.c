//------------------------------------------------------------------------
// NAME: Alexander Naidenov
// CLASS: XIa
// NUMBER: 1
// FILE NAME: main.c
//------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void* prime(void* number)
{
	long long int num = (long long int)number;
	int result = 0;
	int is_prime;

	printf("Prime calculation started for N=%lld\n", num);

	for (int n = 2; n < num; n++)
	{
		is_prime = 1;
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0) {
				is_prime = 0;
				break;
			}
		}
		if (is_prime) {
			++result;
		}
	}

	printf("Number of primes for N=%lld is %d\n", num, result);
	pthread_exit(NULL);
}

int main() {
	while (1)
	{
//		SETTING UP THE NEEDED VARIABLES
		char *buff = NULL;
		size_t size;
		size_t read_bytes;

//		GETTING ARGUMENTS FROM THE COMMAND LINE
		read_bytes = getline(&buff, &size, stdin);
		buff[read_bytes-1] = '\0';

//		CHECKING FOR ERROR
		if (read_bytes == -1)
		{
			free(buff);
			perror("read: error reading 'standart input'");
			continue;
		}

		int buff_i = 0;
		while (buff[buff_i] == ' ')
		{
			++buff_i;
		}

		if (buff[0] == 'e')
		{
			free(buff);
			pthread_exit(NULL);
		}
		else if (buff[0] == 'p')
		{
			++buff_i;
			while (buff[buff_i] == ' ')
			{
				++buff_i;
			}
			if (buff[buff_i] == '\n')
			{
				printf("Supported commands:\n");
				printf("p N - Starts a new calculation for the number of primes from 1 to N\n");
				printf("e - Waits for all calculations to finish and exits\n");
				continue;
			}
			char number[size];
			int j = 0;
			for (; buff_i < read_bytes; ++buff_i) {
				if (buff[buff_i] != ' ')
				{
					number[j] = buff[buff_i];
					++j;
				}
			}
			pthread_t thread;
			int rc = pthread_create(&thread, NULL, prime, (void*) atoll(number));
			if (rc)
			{
				perror("pthread_create");
			}
		}
		else
		{
			printf("Supported commands:\n");
			printf("p N - Starts a new calculation for the number of primes from 1 to N\n");
			printf("e - Waits for all calculations to finish and exits\n");
		}
		free(buff);
	}
}
