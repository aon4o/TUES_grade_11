//------------------------------------------------------------------------
// NAME: Aleksandyr Naidenov
// CLASS: XIa
// NUMBER: 1
// PROBLEM: #1
// FILE NAME: main.c (unix file name)
// FILE PURPOSE:
// The purpose of this file is to recreate the standard UNIX command 'tail'.
//------------------------------------------------------------------------

#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 10000

void get_tail(const char*, int);

//------------------------------------------------------------------------
// FUNCTION: main
// This is the main function of a C program.
// PARAMETERS:
// int argc
// char *argv[]
//------------------------------------------------------------------------

int main(int argc, char *argv[])
{
//	IF STATEMENT TO CHOOSE WHETHER TO READ FROM STDIN OF FROM FILES
	if (argc == 1)
	{
		get_tail("-", 0);
	}
	else
	{
		int file_count = 1;

		int headers;
		if ((argc - 1) != 1) { headers = 1; }
		else { headers = 0; }

//		A CYCLE FOR CALLING get_tail WITH EACH FILE
		for (int files = argc - 1; files > 0; --files)
		{
			get_tail(argv[file_count], headers);

			if ((files) != 1)
			{
				write(STDOUT_FILENO, "\n", 1);
			}

//			MOVING THE FILE_COUNTER TO THE NEXT FILE
			file_count++;
		}
	}
}

//------------------------------------------------------------------------
// FUNCTION: get_tail
// A function which prints the tail of a file.
// PARAMETERS:
// const char* file_name - The name of the file we want to process.
// const int headers - A variable on which depends if headers
// 					will be printed before the tails of each file.
//------------------------------------------------------------------------

void get_tail(const char* file_name, const int headers)
{
	ssize_t read_result;

//	CHECKING IF WE NEED TO READ FROM A FILE OR STDIN
	if (strcmp(file_name, "-") == 0)
	{
//		PRINTING A HEADER IF THERE ARE MORE THAN ONE FILES
		if (headers)
		{
			write(STDOUT_FILENO, "==> standard input <==\n", 23);
		}

//		SETTING UP THE READ_BUFFER AND THE NEW_LINE COUNTER
		char *buff = malloc(SIZE);
		int new_lines = 0;
		int read_bytes = 0;
		int print_from;

//		READING FROM STDIN 'TILL EOF
		do
		{
			read_result = read(STDIN_FILENO, buff+read_bytes, SIZE);
			read_bytes += read_result;
			buff = realloc(buff, SIZE+read_bytes);
			if (read_result == -1)
			{
				perror("tail: error reading 'standart input'");
				free(buff);
				return;
			}
		}
		while (read_result != 0);

//		CHECKING IF THE BUFFER IS EMPTY
		if (read_bytes == 0 || read_bytes == 1)
		{
			print_from = 0;
		}
		else
		{
//			COUNTING THE NEW_LINES IN THE READ PART
			print_from = read_bytes-1;
			if (buff[print_from] == '\n')
			{
				--print_from;
			}
			for (; print_from != 0; --print_from)
			{
				if (buff[print_from] == '\n')
				{
					++new_lines;
					if (new_lines == 10)
					{
						++print_from;
						break;
					}
				}
			}

//			CHECKING IF THE CYCLE SHOULD STOP OR CONTINUE
			if (new_lines != 10)
			{
				print_from = 0;
			}
		}

//		WRITING THE READ PART TO STDOUT AND CHECKING FOR ERRORS
		ssize_t counter = print_from;
		do
		{
			ssize_t write_result = write(STDOUT_FILENO, buff + counter, read_bytes - counter);
			if (write_result == -1)
			{
				perror("tail: error writing 'standard output'");
				return;
			}
			else
			{
				counter += write_result;
			}
		} while (counter != read_bytes);

//		FREEING THE BUFFER
		free(buff);
	}
	else
	{
//		OPENING THE FILE AND CHECKING FOR ERRORS
//		ELSE CONTINUE WITH PROCESSING THE FILE
		int file = open(file_name, O_RDONLY);
		if (file == -1)
		{
			char open_error[100];
			open_error[0] = '\0';
			strcat(open_error, "tail: cannot open '");
			strcat(open_error, file_name);
			strcat(open_error, "' for reading");
			perror(open_error);
		}
		else
		{
//			PRINTING A HEADER IF THERE ARE MORE THAN ONE FILES
			if (headers)
			{
				write(STDOUT_FILENO, "==> ", 4);
				write(STDOUT_FILENO, file_name, strlen(file_name));
				write(STDOUT_FILENO, " <==\n", 5);
			}

//			SETTING UP THE FILE READ_BUFFER AND THE NEW_LINE COUNTER
			char buff[SIZE];
			int new_lines = 0;


//			NEW STRAT BITCH

			ssize_t file_len = lseek(file, 0, SEEK_END);

//			CHECKING IF THE FILE IS SMALLER THAN THE BUFFER SO WE KNOW HOW TO PRINT IT
			int big_file = 1;
			if (file_len < SIZE)
			{
				big_file = 0;
			}

//			CHECKING IF THE FILE IS EMPTY
			if (file_len == 0)
			{
				return;
			}
//			CHECKING IF THERE'S ONLY ONE BYTE IN THE FILE
			else if (file_len == 1)
			{
				lseek(file, 0, SEEK_SET);
				char new_buff[1];
				read_result = read(file, new_buff, sizeof(new_buff));
				if (read_result == -1)
				{
					perror("read");
				}
				ssize_t write_result = write(STDOUT_FILENO, new_buff, 1);
				if (write_result == -1)
				{
					perror("tail: error writing 'standard output'");
					return;
				}
				return;
			}
//			IF THE FILE IS BIG
			else
			{
//				INITIAL READING FROM THE FILE AND CHECKING FOR ERRORS
//				ELSE CONTINUE WITH PROCESSING THE FILE
				lseek(file, -SIZE, SEEK_END);
				read_result = read(file, buff, SIZE);

				if (read_result == 0) { read_result = file_len; }
				if (read_result == -1)
				{
					char read_error[100];
					strcat(read_error, "tail: error reading '");
					strcat(read_error, file_name);
					strcat(read_error, "'");
					perror(read_error);
					read_error[0] = '\0';
				}
				else
				{

//					CYCLE FOR GETTING THE NUMBER OF THE BYTE WHERE THE 10TH NEW LINE FROM THE END OF THE FILE
					int buff_num = -1;
					while (1)
					{
						buff_num += 1;

//					COUNTING THE NEW_LINES IN THE READ PART
						ssize_t i = read_result-2;
						for (; i != 0; --i)
						{
							if (buff[i] == '\n')
							{
								++new_lines;
								if (new_lines == 10)
								{
									read_result = i + 1;
									break;
								}
							}
						}
						printf("%d", new_lines);
//					CHECKING IF THE CYCLE SHOULD STOP OR CONTINUE
						if (new_lines == 10)
						{
							break;
						}
						if (!big_file)
						{
							read_result = 0;
							break;
						}

//					MOVING THE FILE DESCRIPTOR AND READING THE NEXT PART OF THE FILE IF NECESSERY
						lseek(file, -(SIZE*(buff_num+2)), SEEK_END);
						read_result = read(file, buff, SIZE);
						if (read_result == -1)
						{
							char read_error[100];
							read_error[0] = '\0';
							strcat(read_error, "tail: error reading '");
							strcat(read_error, file_name);
							strcat(read_error, "'");
							perror(read_error);
							read_error[0] = '\0';
						}
					}

//					MOVING THE FILE DESCRIPTOR TO THE 10TH NEW LINE
					if (big_file)
					{
						lseek(file, -((buff_num+1)*SIZE-read_result), SEEK_END);
					}
					else
					{
						lseek(file, (buff_num*SIZE + read_result), SEEK_SET);
					}

//					READING THE PART OF THE FILE WHICH SHOULD BE PRINTED
					char new_buff[SIZE*(buff_num+1)];
					read_result = read(file, new_buff, sizeof(new_buff));
					if (read_result == -1)
					{
						perror("read");
					}

//					WRITING THE READ PART TO STDOUT AND CHECKING FOR ERRORS
					for (ssize_t counter = 0; counter != read_result;)
					{
						ssize_t write_result = write(STDOUT_FILENO, new_buff + counter, read_result - counter);
						if (write_result == -1)
						{
							perror("tail: error writing 'standard output'");
							return;
						}
						else
						{
							counter += write_result;
//						PRINTING A NEW LINE AFTER THE END OF THE FILE
							if (read_result == 0)
							{
//							write(STDOUT_FILENO, "\n", 1);
								break;
							}
						}
					}

				}
			}

//			CLOSING THE FILE AND CHECKING FOR ERRORS
			int close_result = close(file);
			if (close_result == -1)
				{
					char close_error[100];
					close_error[0] = '\0';
					strcat(close_error, "tail: error reading '");
					strcat(close_error, file_name);
					strcat(close_error, "'");
					perror(close_error);
					close_error[0] = '\0';
				}
		}
	}
}