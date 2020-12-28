#include <string.h>
#include <stdlib.h>
char** parse_cmdline(const char* cmdline)
{
	int argc = 0;
	char** argv = (char **) malloc(sizeof(char*)*2);
	int copy_from = 0;

//	SEARCHING FOR THE FIRST NON WHITE SPACE IN THE COMMAND
	while (cmdline[copy_from] == ' ')
	{
		++copy_from;
	}
	int copy_to = copy_from;

	while (1)
	{
//		GETTING TO A NON WHITE SPACE CHAR
		while(cmdline[copy_to] != ' ' && cmdline[copy_to] != '\n')
		{
			++copy_to;
		}

//		SETTING THE SIZE OF THE CURRENT ARGV
		argv[argc] = (char *) malloc((copy_to - copy_from) + 1);
		argv[argc][copy_to - copy_from] = '\0';

//		FILLING THE CURRENT ARGV
		for (int i = 0; copy_from < copy_to; ++i)
		{
			argv[argc][i] = cmdline[copy_from];
			++copy_from;
		}

		if (cmdline[copy_to] == ' ')
		{
			while (cmdline[copy_to] == ' '){
				++copy_to;
			}
			copy_from = copy_to;

			if (cmdline[copy_to] == '\n')
			{
				argv[argc+1] = NULL;
				break;
			}

			++argc;
			argv = (char **) realloc(argv, sizeof(char*)*(argc+2));
			continue;
		}
		if (cmdline[copy_to] == '\n')
		{
			argv[argc+1] = NULL;
			break;
		}
	}

	return argv;
}