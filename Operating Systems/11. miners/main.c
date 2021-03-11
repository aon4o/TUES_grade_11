#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex;
int gold = 0;

void* miner(void* argv)
{
	long id = (long)argv;
	++id;
	for (int i = 0; i < 20; ++i) {
		if (pthread_mutex_lock(&mutex) != 0)
		{
			perror("pthread_mutex_lock");
			return NULL;
		}
		gold += 10;
		printf("Miner %ld gathered 10 gold\n", id);
		if (pthread_mutex_unlock(&mutex) != 0)
		{
			perror("pthread_mutex_unlock");
			return NULL;
		}
		sleep(2);
	}
	return NULL;
}

void* trader(void* argv)
{
	long id = (long)argv;
	++id;
	for (int i = 0; i < 20; ++i) {
		if (pthread_mutex_lock(&mutex) != 0)
		{
			perror("pthread_mutex_lock");
			return NULL;
		}
		if (gold > 0) {
			gold -= 10;
			printf("Trader %ld sold 10 gold\n", id);
		} else {
			printf("The warehouse is empty, cannot sell!\n");
		}
		if (pthread_mutex_unlock(&mutex) != 0)
		{
			perror("pthread_mutex_unlock");
			return NULL;
		}
		sleep(2);
	}
	return NULL;
}

int main(int argc, char* argv[])
{
//	INITIALIZING THE MUTEX
	if (pthread_mutex_init(&mutex, NULL) != 0) {
		printf("pthread_mutex_init");
		return 1;
	}

//	CREATING THE NEEDED VARIABLES
	int miners;
	int traders;

//	CHECKING FOR ARGUMENTS
	if (argc != 3) {
		miners = 1;
		traders = 1;
	} else {
		miners = atoi(argv[1]);
		traders = atoi(argv[2]);
	}

//	CREATING THE THREADS
	pthread_t miner_threads[miners];
	pthread_t trader_threads[traders];
	for (long i = 0; i < miners; ++i) {
		if (pthread_create(&miner_threads[i], NULL, (void*)miner, (void *)i) != 0)
		{
			perror("pthread_create");
			pthread_mutex_destroy(&mutex);
			return 2;
		}
	}
	for (long i = 0; i < traders; ++i) {
		if (pthread_create(&trader_threads[i], NULL, (void*)trader, (void *)i) != 0)
		{
			perror("pthread_create");
			pthread_mutex_destroy(&mutex);
			return 2;
		}
	}

//	JOINING THE THREADS
	for (int i = 0; i < miners; ++i) {
		if (pthread_join(miner_threads[i], NULL) != 0)
		{
			perror("pthread_join");
			pthread_mutex_destroy(&mutex);
			return 3;
		}
	}
	for (int i = 0; i < traders; ++i) {
		if (pthread_join(trader_threads[i], NULL) != 0)
		{
			perror("pthread_join");
			pthread_mutex_destroy(&mutex);
			return 3;
		}
	}

	printf("Gold: %d\n", gold);
	pthread_mutex_destroy(&mutex);
	return 0;
}
