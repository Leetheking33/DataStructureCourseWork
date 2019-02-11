#include <stdlib.h>
#include <iostream>
#include "array.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
	double arr[8] = {3,10,8,32,1,85,23,-5};
	
	Array<double> copy(arr, 8);

	cout << "Length of copy is: " << copy.getLength() << endl;

	for(int i=0; i < 8; i++){
		cout << copy[i] << ", ";
	}
	cout << endl;

	copy.bubbleSort();

	for(int i=0; i < 8; i++){
                cout << copy[i] << ", ";
        }
        cout << endl;

	cout << "Index of 10: " << copy.binarySearch(10) << endl;
}

