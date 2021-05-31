//--------------------------------------------
// NAME: Alexander Naidenov
// CLASS: XIa
// NUMBER: 1
// FILE NAME: functions.c
// PURPOSE:
// File with some functions for helping the work of the program.
//---------------------------------------------
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

char get_entry_type(struct stat* entry_stat)
{
	unsigned int mode = entry_stat->st_mode;
	if (S_ISREG(mode)){
		return '-';
	} else if (S_ISDIR(mode)){
		return 'd';
	} else if (S_ISCHR(mode)){
		return 'c';
	} else if (S_ISBLK(mode)){
		return 'b';
	} else if (S_ISFIFO(mode)){
		return 'p';
	} else if (S_ISLNK(mode)){
		return 'l';
	} else if (S_ISSOCK(mode)){
		return 's';
	} else {
		return ' ';
	}
}

void print_total_blocks(char dir_path[NAME_MAX], int flag_a)
{
//	OPENING THE DIRECTORY
	DIR *dir = opendir(dir_path);
	if (dir == NULL)
	{
		perror("opendir");
		return;
	}

//	GETTING THE NUMBER OF BLOCKS
	struct dirent *dir_entry;
	long total = 0;
	struct stat entry_stat;

	while ((dir_entry = readdir(dir)) != NULL)
	{
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
			return;
		}

		total += entry_stat.st_blocks;
	}

	printf("total %ld\n", total/2);

//	CLOSING THE DIRECTORY
	if (closedir(dir) != 0)
	{
		perror("closedir");
		return;
	}
}

void print_long_listing_format(struct stat* entry_stat)
{
	unsigned int mode = entry_stat->st_mode;

//	PRINTING PERMISSIONS
	printf("%c", get_entry_type(entry_stat));
	printf((mode & S_IRUSR) ? "r" : "-");
	printf((mode & S_IWUSR) ? "w" : "-");
	printf((mode & S_IXUSR) ? "x" : "-");
	printf((mode & S_IRGRP) ? "r" : "-");
	printf((mode & S_IWGRP) ? "w" : "-");
	printf((mode & S_IXGRP) ? "x" : "-");
	printf((mode & S_IROTH) ? "r" : "-");
	printf((mode & S_IWOTH) ? "w" : "-");
	printf((mode & S_IXOTH) ? "x" : "-");
	printf(" %li ", entry_stat->st_nlink);

//	PRINTING USER AND GROUP
	struct passwd* user;
	struct group* group;

	if((user = getpwuid(entry_stat->st_uid)) == NULL) {
		perror("getpwuid");
	}
	if((group = getgrgid(entry_stat->st_gid)) == NULL) {
		perror("getgrgid");
	}

	printf("%s ", user->pw_name);
	printf("%s ", group->gr_name);

//	PRINTING SIZE AND TIMESTAMP
	struct tm *time_now;
	char time_string[100];
	time_t file_time = entry_stat->st_mtime;

	if((time_now = localtime(&file_time)) == NULL) {
		perror("localtime");
	}
	strftime(time_string, sizeof(time_string), "%b %d %R", time_now);

	printf("%ld ", entry_stat->st_size);
	printf("%s ", time_string);
}
