#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define SIZE 1000000

int main()
{
//	OPENING THE FILE AND CHECKING FOR ERRORS
	int file = open("a.txt", O_RDONLY);
	if (file == -1)
	{
		perror("open");
		return 1;
	}

//	SETTING UP THE FILE READ_BUFFER AND THE NEW_LINE COUNTER
	char buff[SIZE];
	int new_lines = 0;

	while (1)
	{
//		READING FROM THE FILE AND CHECKING FOR ERRORS
		ssize_t read_result = read(file, buff, SIZE);
		if (read_result == -1)
		{
			perror("read");
		}

//		COUNTING THE NEW_LINES IN THE READ PART
		for (int i = 0; i != SIZE; ++i) {
			if (buff[i] == '\n')
			{
				++new_lines;
				if (new_lines == 10)
				{
					read_result = i;
				}
			}
		}

//		WRITING THE READ PART TO THE CONSOLE
		for (ssize_t counter = 0; counter != read_result;) {
			ssize_t write_result = write(STDOUT_FILENO, buff + counter, read_result - counter);
			counter += write_result;
			if (read_result == 0)
			{
				printf("\n");
				break;
			}
		}

//		BREAKING THE CYCLE WHEN EVERYTHING IS PRINTED
		if (read_result == 0)
		{
			break;
		}
	}

//	PRINTING THE LAST NEW_LINE AFTER THE LAST LINE
	printf("\n");

//	CLOSING THE FILE AND CHECKING FOR ERRORS
	int close_result = close(file);
	if (close_result == -1)
	{
		perror("close");
		return 4;
	}

	return 0;
}