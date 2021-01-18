all: compile run

compile:
	g++ -I ./include/ -c ./src/IcAVL.cpp -o ./lib/IcAVL.o
	g++ -I ./include/ -c ./src/DisAVL.cpp -o ./lib/DisAVL.o
	g++ -I ./include/ -o ./bin/Main ./lib/IcAVL.o ./lib/DisAVL.o ./src/main.cpp

run:
	./bin/Main