//--------------------------------------------
// NAME: Alexander Naidenov
// CLASS: XIa
// NUMBER: 1
// FILE NAME: functions.c
// PURPOSE:
// File with some functions for helping the work of the program.
//---------------------------------------------
#include <sys/stat.h>

char get_entry_type(struct stat* entry_stat) {
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
	}
}
