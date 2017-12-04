nqueens: main.o nqueens.o
	g++ -o nqueens main.o nqueens.o

main.o: main.cpp nqueens.h
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp

nqueens.o: nqueens.cpp nqueens.h
	g++ -c -Wall -pedantic -g -std=c++11 nqueens.cpp

clean:
	rm main.o nqueens.o nqueens
