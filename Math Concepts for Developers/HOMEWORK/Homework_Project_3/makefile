main: Graph.o
	g++ -o main main.cpp Graph.o -I.
	-rm *.o

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp

clean:
	-rm *.o
	-rm main