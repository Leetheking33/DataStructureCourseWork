CFLAGS=-Wall -O2
MAIN=src/main.cpp
SRCS := $(filter-out $(MAIN), $(wildcard src/*cpp))
BIN=first
CC=g++

.PHONY: compile run clean all

all: compile run
	echo ${SRCS}

compile: ${SRCS}
	${CC} ${CFLAGS} ${SRCS} ${MAIN} -o ${BIN}

%-test:
	cxxtestgen --error-printer -o test/runner.cpp test/$@.cpp
	g++ -o runner test/runner.cpp -I src/ ${SRCS}
	./runner

obj:
	mkdir -p obj

run:
	./${BIN}

clean:
	rm -rf ${BIN} *.o obj
