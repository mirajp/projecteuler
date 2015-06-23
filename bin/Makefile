all: p1.out p2.out p3.out p4.out p5.out p6.out p7.out p8.out p9.out p10.out

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

p3.out: p3.o ../lib/prime.o
	g++ p3.o ../lib/prime.o -o p3.out

p3.o: p3.cpp
	g++ -c p3.cpp

../lib/prime.o: ../lib/prime.cpp
	g++ -c ../lib/prime.cpp -o ../lib/prime.o

p4.out: p4.o
	g++ p4.o -o p4.out

p4.o: p4.cpp
	g++ -c p4.cpp

p5.out: p5.o ../lib/prime.o
	g++ p5.o ../lib/prime.o -o p5.out

p5.o: p5.cpp
	g++ -c p5.cpp

p6.out: p6.o
	g++ p6.o -o p6.out

p6.o: p6.cpp
	g++ -c p6.cpp

p7.out: p7.o
	g++ p7.o -o p7.out

p7.o: p7.cpp
	g++ -c p7.cpp

p8.out: p8.o
	g++ p8.o -o p8.out

p8.o: p8.cpp
	g++ -c p8.cpp

p9.out: p9.o
	g++ p9.o -o p9.out

p9.o: p9.cpp
	g++ -c p9.cpp

p10.out: p10.o
	g++ p10.o -o p10.out

p10.o: p10.cpp
	g++ -c p10.cpp

clean:
	rm *.out *.o
