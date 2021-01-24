main: main.cpp DateTime.o
	g++ -o main main.cpp DateTime.o -I.

DateTime.o: DateTime.cpp DateTime.h
	g++ -c DateTime.cpp

clean:
	-rm *.o
	-rm main
