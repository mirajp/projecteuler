all: p1.out p2.out

p1.out: p1.o
	g++ p1.o -o p1.out

p1.o: p1.cpp
	g++ -c p1.cpp

p2.out: p2.o ../lib/fibolib.o
	g++ p2.o ../lib/fibolib.o -o p2.out

p2.o: p2.cpp
	g++ -c p2.cpp

../lib/fibolib.o: ../lib/fibolib.cpp
	g++ -c ../lib/fibolib.cpp -o ../lib/fibolib.o

clean:
	rm *.out *.o
