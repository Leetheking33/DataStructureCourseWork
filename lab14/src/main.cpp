#include <stdio.h>
#include "binarytree.hpp"

int main(int argc, char *argv[]) {
    	BinaryTree<int> bt;
	//testing put and printInOrder
	bt.put(10);
	bt.printInOrder();
	bt.put(15);
	bt.put(4);
	bt.put(7);
	bt.put(2);
	bt.put(100);
	bt.printInOrder();
	
	//test copy constructor
	BinaryTree<int> copy(bt);
	copy.printInOrder();
		
    	return 0;
}
