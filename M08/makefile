default: main.o String.o
	g++  main.o String.o -o M08

main.o: main.cpp
	g++ -c -Wall -std=c++14 main.cpp
String.o: String.cpp
	g++ -c -Wall -std=c++14 String.cpp

run:
	./M08

clean:
	rm *.o M08