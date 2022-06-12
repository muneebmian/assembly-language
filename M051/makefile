default: main.o Temperatures.o
	g++  main.o Temperatures.o -o M05

main.o: main.cpp
	g++ -c -Wall -std=c++14 main.cpp

Temperatures.o: Temperatures.cpp
	g++ -c -Wall -std=c++14 Temperatures.cpp
run:
	./M05

clean:
	rm *.o M05