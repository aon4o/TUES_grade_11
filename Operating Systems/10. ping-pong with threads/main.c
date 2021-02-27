#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

void print_ping()
{
	while (1) {
		if(pthread_mutex_lock(&mutex) != 0)
		{
			perror("pthread_mutex_lock");
			return;
		}
		if(pthread_mutex_unlock(&mutex) != 0)
		{
			perror("pthread_mutex_unlock");
			return;
		}
		write(STDOUT_FILENO, "Ping\n", 5);
	}
}

void print_pong()
{
	while (1) {
		if(pthread_mutex_lock(&mutex) != 0)
		{
			perror("pthread_mutex_lock");
			return;
		}
		if(pthread_mutex_unlock(&mutex) != 0)
		{
			perror("pthread_mutex_unlock");
			return;
		}
		write(STDOUT_FILENO, "Pong\n", 5);
	}
}

int main()
{
//	INITIALIZING THE MUTEX
	pthread_mutex_init(&mutex, NULL);

//	CREATING THE THREADS
	pthread_t threads[2];
	int thread_result1 = pthread_create(&threads[0], NULL, (void*) print_ping, &mutex);
	int thread_result2 = pthread_create(&threads[1], NULL, (void*) print_pong, &mutex);
	if (thread_result1 == -1 || thread_result2 == -1)
	{
		perror("pthread_create");
		pthread_mutex_destroy(&mutex);
		return -1;
	}

//	JOINING THE THREADS
	for (int i = 0; i < 2; ++i) {
		void* status;
		int thread_join_result = pthread_join(threads[i], &status);

		if (thread_join_result == -1)
		{
			perror("pthread_join");
			pthread_mutex_destroy(&mutex);
			return -2;
		}
	}
	pthread_mutex_destroy(&mutex);
	return 0;
}
