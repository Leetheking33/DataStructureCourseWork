#include <stdlib.h>
#include <iostream>
#include "map.hpp"
#include <list>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
	std::list<int> myList;
	std::list<int>::iterator it;

	for(int i=0; i < 5; i++) 
		myList.push_back(i);

	for(it=myList.begin(); it!=myList.end(); it++){
		cout << *it << ", ";
	}
	cout << endl;
	
	const char *namer = "Leroy";
	const char *name = "Leroy";
	cout << "name[0] = namer[0]? " << (namer[0] == name[0]) << endl;
	if(namer[0] == name[0]){
		cout << "The first letter in name and namer are =" << name[0]  << endl;
	}

	size_t length = strlen(name);
	/*
	for(size_t i = 0; i < length; i++){
			
	}
	*/
	cout << "Name length = " << length << endl;	
		
	int noob = 0;

	Map help;
	cout << "Map length: " << help.size() << endl;	
	help.add("Leroy Henry", 74);
	help.add("Rick James", 210);
	help.add("Ronnie Harris", 2);
	help.add("Ronald Ragen", 99);
	help.add("Jonathan Glover", 35);
	cout << "Map length after add: " << help.size() << endl;
	help.get("Leroy Henry", noob);
	cout << "This is noob "<< noob << endl;
	help.print();

	cout << "How many names start with Ront? " << help.howMany("Ront") << endl;

	help.remove("Leroy Henry");
	cout << "This is map after removing Leroy" << endl;
	help.print();
	help.remove("Ronnie Harris");	
	cout << "This is map after removing Ronnie" << endl;
	help.print();
	cout << "# of first letter Ron in map " << help.howMany("Ron") << endl;
	return 0;
}

