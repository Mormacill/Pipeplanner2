#REV1.1

default:pipeplanner

pipeplanner: Funktionen.o Extras.o main.o
	g++ -g -o pipeplanner Funktionen.o Extras.o main.o

Extras.o: Extras.cpp
	g++ -g -c Extras.cpp

Funktionen.o: Funktionen.cpp
	g++ -g -c Funktionen.cpp

main.o: main.cpp Funktionen.h Extras.h
	g++ -g -c main.cpp

clean:
	rm *.o
