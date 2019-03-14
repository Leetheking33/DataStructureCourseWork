#include <stdio.h>
#include <string>
#include <iostream>
#include "binarytree.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    	BinaryTree<int> bt;
	cout << "The hight of a bt of ints is: " << bt.getHeight() << endl;
	//testing put and printInOrder
	bt.put(10);
	cout << "The hight of a bt of ints is: " << bt.getHeight() << endl;
	bt.printInOrder();
	bt.put(15);
	bt.put(4);
	bt.put(7);
	bt.put(2);
	bt.put(100);
	bt.put(-10);
	bt.printInOrder();
	bt.put(2);
	bt.printInOrder();
	bt.put(0);
	bt.printInOrder();
	cout << "The hight of a bt of ints is: " << bt.getHeight() << endl;
	cout << "print an bt of int in one String: ";
	cout << bt.inorderString() << endl;	
	/*
	string bop = "hello there";
	int x = 55;
	string z = to_string(x);
	bop.append(to_string(x) + " ");
	cout << bop << "should be a space b4 this " << endl;
	//test copy constructor
	cout << "This is printinOrder: ";
	BinaryTree<int> copy(bt);
	copy.printInOrder();
		
	BinaryTree<double> dt;
	dt.put(15);
	dt.printInOrder();
	*/
	BinaryTree<string> st;
	st.put("Leroy");
	st.printInOrder();	
	st.put("Henry");
	st.printInOrder();
	st.put("Kyle");
	st.printInOrder();
	st.put("mincraft");
	st.printInOrder();
	st.put("Dr. West");
	st.put("Miss Betty");
	st.inorderString();	

	cout << "String bt in string: ";
       	cout << st.inorderString();	
    	return 0;
	
}
