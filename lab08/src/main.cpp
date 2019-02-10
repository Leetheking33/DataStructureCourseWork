#include <stdlib.h>
#include <iostream>
#include "sllist.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
   
	//test empty constructor
	SLList<int> list;
	/*list.append(10);
	list.append(23);
	list.append(55);
	list.remove(10);
	SLList<int> list2(list);
	cout << "List: ";
	list.print();
	
	cout << "List2: ";
	list2.print(); */

	      	
	//test append and print
	list.print();
	cout << "The length of empty list "<< list.getLength() << endl;
	list.append(3);
	cout << endl << "The length of list after 1 append is "<< list.getLength() << endl;
        list.print();
	list.append(10);
	cout << endl << "The length of list after 2 appends is "<< list.getLength() << endl;
        list.print();
	list.append(8);
	cout << endl << "The length of list after 3 appends is "<< list.getLength() << endl;
        list.print();
	
	
	//This is the copy constructor test	
	cout << "This is the new deep copy array: ";
	SLList<int> newList(list);
	newList.print();
	cout << endl;
	
	cout << "Another deep copy of list: ";
	SLList<int> shit(list);
	shit.print();
	cout << endl;
	
	cout << "Bullshit seg fault: ";
	SLList<int> why(shit);
	why.print();
	cout << endl;	
	
	//test insert funct
	/*
	SLList<int> Deez(list);
	cout << "Deez: ";
	Deez.print();
	*/
	cout << "This is list before the insert of 20 at index 2: ";
	list.print();
	cout << "This is list after: ";
	list.insert(2,20);
	list.print();
	
	/*
	SLList<int> Boop(list);
	cout << "Boop: ";
	Boop.print();
	cout << endl;
	*/	
	
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
	return 0;
}

