all: hw6

hw6: main.o hw6.o
	g++ main.o Catalog.o -o exe

main.o: main.cpp
	g++ -c main.cpp -std=c++11

hw6.o: Catalog.cpp 
	g++ -c Catalog.cpp -std=c++11

clean:
	rm *.o output.txt exe
run:
	./exe
	subl output.txt
	
