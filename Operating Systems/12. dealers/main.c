#include <stdio.h>
#include <pthread.h>

#define DRIVERS 20
#define CARS 5

pthread_mutex_t cars[CARS];

void* driver(void* id) {
	while (1) {
		for (int i = 0; i < CARS; ++i) {
			if (pthread_mutex_trylock(&cars[i]) == 0) {
				printf("Buyer %ld takes car %d.\n", ((long)id)+1, i+1);
				printf("Buyer %ld returns car %d.\n", ((long)id)+1, i+1);
				if (pthread_mutex_unlock(&cars[i]) != 0) {
					perror("pthread_mutex_unlock");
				}
				return NULL;
			}
		}
	}
}

int main() {
//	INITIALIZING THE MUTEXES
	for (int i = 0; i < CARS; ++i) {
		if (pthread_mutex_init(&cars[i], NULL) != 0) {
			perror("pthread_mutex_init");
			return 0;
		}
	}

//	CREATING THE THREADS
	pthread_t drivers[DRIVERS];
	for (long i = 0; i < DRIVERS; ++i) {
		if (pthread_create(&drivers[i], NULL, driver, (void *) i) != 0){
			perror("pthread_create");
			return 0;
		}
	}

//	JOINING THE THREADS
	for (int i = 0; i < DRIVERS; ++i) {
		if (pthread_join(drivers[i], NULL) != 0){
			perror("pthread_join");
			return 0;
		}
	}
	
	return 0;
}
