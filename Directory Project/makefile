all: hello

hello: main.o hello.o
	g++ main.o Component.o Driver.o -o exe

main.o: main.cpp
	g++ -c main.cpp -std=c++11

hello.o: Driver.cpp 
	g++ -c Driver.cpp Component.cpp -std=c++11

clean:
	rm *.o exe
run:
	./exe
