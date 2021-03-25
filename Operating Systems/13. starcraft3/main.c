//--------------------------------------------
// NAME: Alexander Naidenov
// CLASS: XIA
// NUMBER: 1
// PROBLEM: #3
// FILE NAME: main.c
// FILE PURPOSE:
// The main file of the programme.
//---------------------------------------------
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

long mineral_blocks_number;
int minerals = 0;
int marines = 0;

struct mineral_block{
	pthread_mutex_t mutex;
	int minerals;
};
typedef struct mineral_block mineral_block;

pthread_mutex_t command_center;
mineral_block* mineral_blocks;

void* scv(void* id)
{
//	CREATING THE STATUS LIST FOR THE MINERAL BLOCKS
	int mineral_blocks_status[mineral_blocks_number];
	for (int i = 0; i < mineral_blocks_number; ++i) {
		mineral_blocks_status[i] = 1;
	}
	int flag;
	int transported_minerals;

	while (1)
	{
		for (int i = 0; i < mineral_blocks_number; ++i)
		{
//			CHECKING IF THERE ARE REMAINING MINERALS ON THE MAP
			flag = 1;
			for (int j = 0; j < mineral_blocks_number; ++j) {
				if (mineral_blocks_status[j]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				return NULL;
			}

//			CHECKING FOR THE CURRENT MINERAL BLOCK STATUS
			if (mineral_blocks_status[i])
			{
//				DOING THE WORK
				sleep(3);
				if (pthread_mutex_trylock(&mineral_blocks[i].mutex) == 0)
				{
//					CHECKING IF THE MINERAL BLOCK REALLY HAS MINERALS
					if (mineral_blocks[i].minerals == 0) {
						mineral_blocks_status[i] = 0;
						if (pthread_mutex_unlock(&mineral_blocks[i].mutex) != 0) {
							perror("pthread_mutex_unlock");
							return (void *) -1;
						}
						continue;
					}

//					CHECKING FOT THE MINERAL'S QUANTITY
					if (mineral_blocks[i].minerals < 8) {
						transported_minerals = mineral_blocks[i].minerals;
					} else {
						transported_minerals = 8;
					}

					mineral_blocks[i].minerals -= transported_minerals;
					printf("SCV %ld is mining from mineral block %d\n", ((long)id)+1, i+1);

					if (pthread_mutex_unlock(&mineral_blocks[i].mutex) != 0) {
						perror("pthread_mutex_unlock");
						return (void *) -1;
					}

					sleep(2);
					printf("SCV %ld is transporting minerals\n", ((long)id)+1);

					if (pthread_mutex_lock(&command_center) != 0) {
						perror("pthread_mutex_lock");
						return (void *) -2;
					}

					minerals += transported_minerals;
					printf("SCV %ld delivered minerals to the Command center\n", ((long)id)+1);

					if (pthread_mutex_unlock(&command_center) != 0) {
						perror("pthread_mutex_unlock");
						return (void *) -3;
					}
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
//	INITIALIZING THE MUTEXES
	if (argc > 1) {
		char *ptr;
		mineral_blocks_number = strtol(argv[1], &ptr, 10);
	} else {
		mineral_blocks_number = 2;
	}

	mineral_block mineral_block_mutexes[mineral_blocks_number];
	mineral_blocks = &mineral_block_mutexes[0];
	
	for (int i = 0; i < mineral_blocks_number; ++i) {
		if (pthread_mutex_init(&mineral_block_mutexes[i].mutex, NULL) != 0) {
			perror("pthread_mutex_init");
			return 0;
		}
		mineral_block_mutexes[i].minerals = 500;
	}
	if (pthread_mutex_init(&command_center, NULL) != 0) {
		perror("pthread_mutex_init");
		return 0;
	}

//	CREATING THE THREADS
	long scvs_number = 5;
	pthread_t* scvs = malloc(sizeof(pthread_t) * scvs_number);
	for (long i = 0; i < scvs_number; ++i) {
		if (pthread_create(&scvs[i], NULL, scv, (void *) i) != 0) {
			perror("pthread_create");
			free(scvs);
			return 0;
		}
	}

//	READING FOR COMMANDS

	while (1)
	{
		char buff;
		if (scanf("%c", &buff) == EOF) {
			printf("Bye\n");
			free(scvs);
			return 0;
		}

		if ((buff == 'm' || buff == 's') && scvs_number + marines >= 200) {
			printf("No more space.");
		} else {
			if (buff == 'm') {
				if (minerals >= 50) {
					if (pthread_mutex_lock(&command_center) != 0)
					{
						perror("pthread_mutex_lock");
						free(scvs);
						return 0;
					}
					minerals -= 50;
					sleep(1);
					++marines;
					printf("You wanna piece of me, boy?\n");
					if (pthread_mutex_unlock(&command_center) != 0)
					{
						perror("pthread_mutex_unlock");
						free(scvs);
						return 0;
					}
				} else {
					printf("Not enough minerals.\n");
				}
			} else if (buff == 's') {
				if (minerals >= 50) {
					if (pthread_mutex_lock(&command_center) != 0)
					{
						perror("pthread_mutex_lock");
						free(scvs);
						return 0;
					}
					minerals -= 50;
					sleep(4);
					++scvs_number;
					scvs = realloc(scvs, sizeof(pthread_t) * scvs_number);
					if (pthread_create(&scvs[scvs_number-1], NULL, scv, (void *) (scvs_number-1)) != 0) {
						perror("pthread_create");
						free(scvs);
						return 0;
					}
					printf("SCV good to go, sir.\n");
					if (pthread_mutex_unlock(&command_center) != 0)
					{
						perror("pthread_mutex_unlock");
						free(scvs);
						return 0;
					}
				} else {
					printf("Not enough minerals.\n");
				}
			}
		}

//		CHECKING IF THE PROGRAM SHOULD STOP
		if (marines == 20) {
			break;
		}
	}

//	JOINING THE THREADS
	for (int i = 0; i < scvs_number; ++i) {
		if (pthread_join(scvs[i], NULL) != 0){
			perror("pthread_join");
			free(scvs);
			return 0;
		}
	}

//	FREEING THE MEMORY
	free(scvs);

//	PRINTING THE END GAME MESSAGE
	printf("Map minerals %ld, player minerals %d, SCVs %ld, Marines %d\n",
		   mineral_blocks_number*500, minerals, scvs_number, marines);

//	DESTROYING THE MUTEXES
	for (int i = 0; i < mineral_blocks_number; ++i) {
		if (pthread_mutex_destroy(&mineral_block_mutexes[i].mutex) != 0) {
			perror("pthread_mutex_destroy");
			return 0;
		}
	}
	if (pthread_mutex_destroy(&command_center) != 0) {
		perror("pthread_mutex_destroy");
		return 0;
	}

	return 0;
}