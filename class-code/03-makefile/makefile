CFLAGS=-Wall -O2
CC=g++

all: compile run clean

compile: first.o second.o
	${CC} ${CFLAGS} *.o -o first

first.o: src/first.cpp
	g++ ${CFLAGS} -c src/first.cpp

second.o: src/second.cpp
	g++ ${CFLAGS} -c src/second.cpp

run:
	./first

clean:
	rm first *.o
