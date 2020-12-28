main: main.c parse
	gcc -o shell main.c parse_cmdline.o -I.

parse: parse_cmdline.c parse_cmdline.h
	gcc -c parse_cmdline.c

clean:
	-rm *.o
	-rm shell
