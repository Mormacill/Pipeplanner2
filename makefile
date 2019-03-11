#REV1.0

default:pipeplanner

pipeplanner: Funktionen.o main.o
	g++ -g -o pipeplanner Funktionen.o main.o

Funktionen.o: Funktionen.cpp
	g++ -g -c Funktionen.cpp

main.o: main.cpp Funktionen.h
	g++ -g -c main.cpp

clean:
	rm *.o
