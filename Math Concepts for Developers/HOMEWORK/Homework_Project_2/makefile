main: main.cpp classes
	g++ -o main main.cpp Classes.o -I.

classes: Classes.cpp Classes.h
	g++ -c Classes.cpp

clean:
	-rm *.o
	-rm main
