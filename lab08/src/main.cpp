#include <stdlib.h>
#include <iostream>
#include "sllist.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
   
	//test empty constructor
	SLList<int> list;
      	
	//test append and print
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

	//This is the copy constructor test	
	cout << "This is the new deep copy array: ";
	SLList<int> newList(list);
	newList.print();
	cout << endl;

	//test insert funct
	cout << "This is list before the insert of 20 at index 2: ";
	list.print();
	cout << "This is list after: ";
	list.insert(2,20);
	list.print();
	cout << endl;

	//test remove funct
	cout << "This is list before 730 is removed: ";
	list.print();
	list.remove(730);
	cout << "This is list after: ";
	list.print();
	cout << endl;

	//test == operator
	SLList<int> equalList(list);
	cout << "This is equalList: ";
	equalList.print();
	cout << "This is newList: ";
	newList.print();

	//cout << "newList and equalList are equal: " << (newList == equalList) << endl; 


	return 0;
}

