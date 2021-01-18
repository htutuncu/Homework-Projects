all: compile run

compile:
	g++ -I ./include -c ./src/BenimListem.cpp -o ./lib/BenimListem.o
	g++ -I ./include -o ./bin/main ./src/main.cpp ./lib/BenimListem.o
run: 
	./bin/main