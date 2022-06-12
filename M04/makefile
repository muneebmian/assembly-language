default: main.o Temperature.o
	g++  main.o Temperature.o -o M05

main.o: main.cpp
	g++ -c -Wall -std=c++14 main.cpp

Temperature.o: Temperature.cpp
	g++ -c -Wall -std=c++14 Temperature.cpp
run:
	./M05

clean:
	rm *.o M05