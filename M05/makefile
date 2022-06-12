default: main.o Bmp.o Topograph.o
	g++  main.o Bmp.o Topograph.o -o M05

main.o: main.cpp
	g++ -c -Wall -std=c++14 main.cpp

Bmp.o : Bmp.cpp
	g++ -c -Wall -std=c++14 Bmp.cpp
Topograph.o : Topograph.cpp
	g++ -c -Wall -std=c++14 Topograph.cpp
run:
	./M05

clean:
	rm *.o M05