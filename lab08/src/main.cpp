#include <stdlib.h>
#include <iostream>
#include "sllist.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
   
	//create empty sll
	SLList<int> list;
	cout << list[5] << endl;
	list.print();
	cout << "The length of empty list "<< list.getLength() << endl;
	list.append(500);
	list.print();
	cout << endl << "The length of list after 1 append "<< list.getLength() << endl;
	list.append(500);
	list.print();
	cout << endl << "The length of list after 2 appends "<< list.getLength() << endl;
	list.append(52);
	list.print();
	cout << endl << "The length of list after 3 appends "<< list.getLength() << endl;
	list.append(19);
	list.append(730);
	list.append(213);
	list.print();
	cout << endl << "The length of list after 6 appends "<< list.getLength() << endl;
	
	cout << "This is the new deep copy array: ";
	SLList<int> newList(list);
	newList.print();
}

