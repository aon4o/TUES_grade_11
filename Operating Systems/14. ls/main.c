//--------------------------------------------
// NAME: Alexander Naidenov
// CLASS: XIa
// NUMBER: 1
// FILE NAME: main.c
//---------------------------------------------
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#include "functions.c"

int main(int argc, char **argv)
{
//	CHECKING FOR CASE WITH NO ARGUMENTS
	if (argc < 2)
	{
//		GETTING THE PATH TO THE CURRENT DIRECTORY
		char dir_path[PATH_MAX];
		if (getcwd(dir_path, sizeof(dir_path)) == NULL)
		{
			perror("getcwd");
			return 1;
		}

//		OPENING THE DIRECTORY
		DIR *dir = opendir(dir_path);
		if (dir == NULL)
		{
			perror("opendir");
			return 1;
		}

//		DOING THE WORK
		struct dirent *dir_entry;
		struct stat entry_stat;
		while ((dir_entry = readdir(dir)) != NULL)
		{
//			CHECKING IF THE FILE IS HIDDEN
			if(dir_entry->d_name[0] == '.') {
				continue;
			}

			char entry_path[NAME_MAX] = "\0";
			strcat(entry_path, dir_path);
			strcat(entry_path, "/");
			strcat(entry_path, dir_entry->d_name);

			int stat_value = stat(entry_path, &entry_stat);
			if (stat_value != 0)
			{
				fprintf(stderr, "stat: %s", dir_path);
				return 1;
			}
			printf("%c ", get_entry_type(&entry_stat));
			printf("%s\n", dir_entry->d_name);
		}

//		CLOSING THE DIRECTORY
		if (closedir(dir) != 0)
		{
			perror("closedir");
			return 1;
		}
		return 0;
	}

//	CHECKING FOR OPTIONAL ARGUMENTS
	int flag_a = 0, flag_l = 0, flag_r = 0;
	int option;
	// put ':' at the starting of the string so compiler can distinguish between '?' and ':'
	while((option = getopt(argc, argv, "lAR")) != -1){ //get option from the getopt() method
		switch(option){
			//For option i, r, l, print that these are options
			case 'A':
				flag_a = 1;
				break;
			case 'l':
				flag_l = 1;
				break;
			case 'R':
				flag_r = 1;
				break;
			case '?': //used for some unknown options
				printf("unknown option: %c\n", optopt);
				break;
			default:
				break;
		}
	}

	for(; optind < argc; optind++)
	{
//		TEST
//		printf("%s\n", argv[optind]);

//		GETTING THE NAME OF THE FILE OR THE PATH TO THE DIRECTORY DIRECTORY
//		char argument[PATH_MAX];

//		OPENING THE DIRECTORY
		DIR *dir = opendir(argv[optind]);
		if (dir == NULL)
		{
			perror("opendir");
			return 1;
		}

//		DOING THE WORK
		struct dirent *dir_entry;
		struct stat entry_stat;
		while ((dir_entry = readdir(dir)) != NULL)
		{
//			CHECKING IF THE FILE IS HIDDEN
			if(dir_entry->d_name[0] == '.') {
				continue;
			}

			char entry_path[NAME_MAX] = "\0";
			strcat(entry_path, argv[optind]);
			strcat(entry_path, "/");
			strcat(entry_path, dir_entry->d_name);

			int stat_value = stat(entry_path, &entry_stat);
			if (stat_value != 0)
			{
				fprintf(stderr, "stat: %s", argv[optind]);
				return 1;
			}
			printf("%c ", get_entry_type(&entry_stat));
			printf("%s\n", dir_entry->d_name);
		}

//		CLOSING THE DIRECTORY
		if (closedir(dir) != 0)
		{
			perror("closedir");
			return 1;
		}
		return 0;
	}

	return 0;
}
