all: obj list main node
	g++ ./obj/*.o -o bind

list:
	g++ -Wall -o obj/list.o -c src/list.cpp

main: 
	g++ -Wall -o obj/main.o -c src/main.cpp

node:
	g++ -Wall -o obj/node.o -c src/node.cpp

obj:
	mkdir obj

run:
	valgrind ./bind

clean: 
	rm -r ./obj/*.o
	rm bind



