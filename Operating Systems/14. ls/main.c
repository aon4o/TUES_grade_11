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
//	CHECKING FOR OPTIONAL ARGUMENTS
	int flag_a = 0, flag_l = 0, flag_r = 0;
	int option;
	while((option = getopt(argc, argv, "lAR")) != -1) {
		switch(option){
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

//	CHECKING FOR NON OPTIONAL ARGUMENTS
	if (optind == argc) {
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

//		PRINTING THE TOTAL
		if (flag_l) {
			print_total_blocks(dir_path, flag_a);
		}

//		DOING THE WORK
		struct dirent *dir_entry;
		struct stat entry_stat;
		while ((dir_entry = readdir(dir)) != NULL)
		{
//			CHECKING IF THE FILE IS HIDDEN
			if(flag_a) {
				if(!strcmp(dir_entry->d_name, ".") || !strcmp(dir_entry->d_name, "..")) {
					continue;
				}
			} else {
				if(dir_entry->d_name[0] == '.') {
					continue;
				}
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

			if(flag_l) {
				print_long_listing_format(&entry_stat);
			} else {
				printf("%c ", get_entry_type(&entry_stat));
			}

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

//	IF THERE ARE NON OPTIONAL ARGUMENTS
	char previous_option = ' ';
	for(; optind < argc; ++optind)
	{
//		GETTING THE TYPE OF THE CURRENT ARGUMENT
		struct stat argument_stat;
		int stat_value = stat(argv[optind], &argument_stat);
		if (stat_value != 0)
		{
			fprintf(stderr, "ls: cannot access %s: No such file or directory\n", argv[optind]);
			continue;
		}

//		IF NOT DIRECTORY
		if (get_entry_type(&argument_stat) != 'd')
		{
			if (previous_option == 'd') {
				printf("\n");
			}

			if(flag_l) {
				print_long_listing_format(&argument_stat);
			} else {
				printf("%c ", get_entry_type(&argument_stat));
			}
			printf("%s\n", argv[optind]);
			previous_option = get_entry_type(&argument_stat);
		}
//		IF DIRECTORY
		else
		{
//			PRINTING THE PATH
			if (argc > 2) {
				if (previous_option != ' ') {
					printf("\n");
				}
				printf("%s:\n", argv[optind]);
			}

//			OPENING THE DIRECTORY
			DIR *dir = opendir(argv[optind]);
			if (dir == NULL)
			{
				fprintf(stderr, "ls: cannot open directory %s/: Permission denied\n", argv[optind]);
				continue;
			}

//			PRINTING THE TOTAL
			if (flag_l) {
				print_total_blocks(argv[optind], flag_a);
			}

//			DOING THE WORK
			struct dirent *dir_entry;
			struct stat entry_stat;
			while ((dir_entry = readdir(dir)) != NULL)
			{
//				CHECKING IF THE FILE IS HIDDEN
				if(flag_a) {
					if(!strcmp(dir_entry->d_name, ".") || !strcmp(dir_entry->d_name, "..")) {
						continue;
					}
				} else {
					if(dir_entry->d_name[0] == '.') {
						continue;
					}
				}

				char entry_path[NAME_MAX] = "\0";
				strcat(entry_path, argv[optind]);
				strcat(entry_path, "/");
				strcat(entry_path, dir_entry->d_name);
				if (stat(entry_path, &entry_stat) != 0)
				{
					fprintf(stderr, "stat: %s", argv[optind]);
					return 1;
				}

				if(flag_l) {
					print_long_listing_format(&entry_stat);
				} else {
					printf("%c ", get_entry_type(&entry_stat));
				}

				printf("%s\n", dir_entry->d_name);
			}

//			CLOSING THE DIRECTORY
			if (closedir(dir) != 0)
			{
				perror("closedir");
				return 1;
			}
			previous_option = get_entry_type(&argument_stat);
		}
	}
	return 0;
}
