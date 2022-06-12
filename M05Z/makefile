default: main.o Points.o
	g++  main.o Points.o -o M05

main.o: main.cpp
	g++ -c -Wall -std=c++14 main.cpp

Point.o: Point.cpp
	g++ -c -Wall -std=c++14 Points.cpp
run:
	./M05

clean:
	rm *.o M05