#include <stdlib.h>
#include <iostream>
#include "array.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
	int Arr[10] = {3,33,9,3,20,59,69,93,6,43};
 	int *ptr = NULL;
	int deez = 0;

	//Print origanal array
	cout << "This is the the original array: ";
	for(int i=0; i<10; i++){
                cout << Arr[i] << ", ";
        }
	cout << endl;
	
	//test pointer construction
    	Array<int> NewArr(Arr, 10);
	cout << "This is the new deep copy array: ";
   	for(int i=0; i<10; i++){
		cout << NewArr[i] << ", ";	
   	}
	cout << endl;

        //test constructor using Referance
	Array<int> RefArr(NewArr);

	cout << "This is the new deep copy array using a reference instead of apointer: ";
        for(int i=0; i<10; i++){
                cout << RefArr[i] << ", ";
        }
	cout << endl;

	//test getLength
	cout << "This is the size of Construct Arr " << NewArr.getLength() << endl;
	cout << "This is the size of Referance Arr " << RefArr.getLength() << endl;
	
	//test == op when Arrays are equal
	cout << "Before removal ";
	if( NewArr == RefArr)
		cout << "arrays are equal" << endl;
	else
		cout << "arrays are not equal" << endl;	
	//get input for indexOf
	cout << "Enter a number to see if its in the array and it's index: ";
	cin >> deez;
	
	//test indexOf
	cout << NewArr.indexOf(deez) << endl;
	
	cout << "Enter index to delete: ";
	cin >> deez;
	
	//test remove
	RefArr.remove(deez);
	
	cout << "This is RefArr after removing entered index: ";
	for(int i=0; i<10; i++){
                cout << RefArr[i] << ", ";
        }
 	cout << endl;

	//Test == when Arrays are not equal
	cout << "After removal ";
	if( NewArr == RefArr) 
                cout << "arrays are equal" << endl;
        else
                cout << "arrays are not equal" << endl;
	

    return 0;
}

