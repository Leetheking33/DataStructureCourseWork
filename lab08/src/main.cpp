#include <stdlib.h>
#include <iostream>
#include "sllist.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
   
	//test empty constructor
	DLList<int> list;

	      	
	//test append and print
	list.print();
	cout << "The length of empty dll "<< list.getLength() << endl;
	list.append(3);
	cout << endl << "The length of dll after 1 append is "<< list.getLength() << endl;
        list.print();
	list.append(10);
	cout << endl << "The length of dll after 2 appends is "<< list.getLength() << endl;
        list.print();
	list.append(8);
	cout << endl << "The length of dll after 3 appends is "<< list.getLength() << endl;
        list.print();
	
	list.insert(0,25);
	cout << endl << "Dll after inserting 25 at 0 index: ";
        list.print();

	list.remove(8);
	cout << endl << "Dll after removing 8: ";
	list.print();
	
	cout << endl << "Append 50: ";
	list.append(50);
	list.print();
	
	cout << endl << "Insert 67 at index 1: ";
	list.insert(1,67);
	list.print();

	cout << endl << "Length of dll: " << list.getLength() << endl;
		
	/*	
	//This is the copy constructor test	
	cout << "This is the new deep copy dll: ";
	DLList<int> newList(list);
	newList.print();
	cout << endl;
	*/

	/*
	//test insert funct
	cout << "This is list before the insert of 20 at index 2: ";
	list.print();
	cout << "This is list after: ";
	list.insert(2,20);
	list.print();	
	
	//test remove funct
	cout << "This is list before 10 is removed: ";
	list.print();
	list.remove(10);
	cout << "This is list after: ";
	list.print();
	cout << endl;

	//test == operator
	SLList<int> equalList(newList);
	cout << "This is equalList: ";
	equalList.print();
	cout << "This is newList: ";
	newList.print();
	

	cout << "newList and equalList are equal: " << (newList == equalList) << endl; 
	cout << "list and newList are equal: " << (list == newList) << endl;

	//test [] operator
	cout << "20 + 3 = " << (list[1] + list[0]) << endl;
	*/	
	return 0;
}

