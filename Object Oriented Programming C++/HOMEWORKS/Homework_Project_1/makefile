main:  routers packages
	g++ -o main main.cpp Router.o Package.o -I.
	-rm *.o

routers: Router.cpp Router.h
	g++ -c Router.cpp

packages: Package.cpp Package.h
	g++ -c Package.cpp
