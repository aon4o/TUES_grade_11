main: main.cpp Vector.o
	g++ -o vector main.cpp Vector.o -I.

Vector.o: Vector.cpp Vector.h
	g++ -c Vector.cpp

clean:
	-rm *.o
	-rm vector