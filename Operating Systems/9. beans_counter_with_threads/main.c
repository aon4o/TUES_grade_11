//------------------------------------------------------------------------
// NAME: Alexander Naidenov
// CLASS: XIa
// NUMBER: 1
// FILE NAME: main.c
//------------------------------------------------------------------------
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define SIZE 100000

//	A STRUCTURE FOR THE ARGS OF BEANS FUNCTION
struct beans_t
{
	int tid;
	int black;
	int white;
};
typedef struct beans_t beans_args;

//	A THREAD FUNCTION
void* beans(void* arguments)
{
	beans_args* args = (beans_args*) arguments;

//	OPENING THE FILE
	int file = open("old_beans.txt", 'r');
	if (file == -1)
	{
		perror("open");
		return (void *) -1;
	}

//	MOVING THE FILE DESCRIPTOR
	int lseek_result = lseek(file, ((args->tid) * SIZE), SEEK_SET);
	if (lseek_result == -1)
	{
		perror("lseek");
		return (void *) -1;
	}

//	READING FROM THE FILE
	char buff[SIZE+1];
	int read_result, read_bytes = 0;
	do
	{
		read_result = read(file, buff+read_bytes, SIZE-read_bytes);
		read_bytes += read_result;
		if (read_result == -1)
		{
			perror("read");
			return (void *) -1;
		}
	}
	while (read_result != 0 || read_bytes != SIZE);
	buff[read_bytes] = '\0';

//	COUNTING THE BEANS
	for (int i = 0; buff[i] != '\0'; ++i) {
		if (buff[i] == '1')
		{
			args->black++;
		}
		else if (buff[i] == '0')
		{
			args->white++;
		}
	}

//	CLOSING THE FILE
	int close_result = close(file);
	if (close_result == -1)
	{
		perror("close");
		return (void *) -1;
	}

	pthread_exit(NULL);
}

int main()
{
	char* filename = "old_beans.txt";

//	GETTING THE FILE SIZE
	struct stat file_stats;
	if (stat(filename, &file_stats) == -1)
	{
		perror("stat");
		return 0;
	}

//	CREATING DYNAMIC ARRAY FOR STORING THE THREADS
	long long int num_threads = file_stats.st_size / SIZE;
	pthread_t threads[num_threads];
	beans_args beans_counter[num_threads];

//	CREATING THE THREADS
	for (int i = 0; i < num_threads; ++i)
	{
		beans_counter[i].tid = i;
		beans_counter[i].black = 0;
		beans_counter[i].white = 0;

		int thread_result = pthread_create(&threads[i], NULL, beans, (void*) &beans_counter[i]);
		if (thread_result == -1)
		{
			perror("pthread_create");
			return 0;
		}
	}
	
//	JOINING THE THREADS
	for (int i = 0; i < num_threads; ++i) {
		void* status;
		int thread_join_result = pthread_join(threads[i], &status);
		if (thread_join_result == -1)
		{
			perror("pthread_join");
			return 0;
		}
		if ((int)threads[i] == -1)
		{
			return -1;
		}
	}

	int white = 0, black = 0;
	for (int i = 0; i < num_threads; ++i) {
		white += beans_counter[i].white;
		black += beans_counter[i].black;
	}
	printf("White beans: %d, Black beans: %d, Beans sum: %d.", white, black, white + black);
	return 0;
}
