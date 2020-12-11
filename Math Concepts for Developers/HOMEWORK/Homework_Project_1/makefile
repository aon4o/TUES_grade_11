main: Matrix.o
	g++ -o main main.cpp Matrix.o -I.
	-rm *.o

Matrix.o: Matrix.cpp Matrix.h
	g++ -c Matrix.cpp

clean:
	-rm *.o
	-rm main