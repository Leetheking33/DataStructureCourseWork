#include <stdlib.h>
#include <iostream>
#include "array.hpp"
#include <time.h>
using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */

	/*
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
	*/
	
	srand(100);

	//This is where timing starts
	clock_t start, diff;

    // timeAmount is used to print out the time in seconds.
    double timeAmount;

    // We want to run our algorithm over varying sizes.
    for (int i = 10000; i < 3000000; i += 100000) {
        
	    int *bigArray = new int[i];
       		for(int j=0; j < i; j++){
		bigArray[j] = rand();
		}

        Array<int> time(bigArray, i);
	

	// Capture the start clock
        start = clock();

        // This is were your algorithm should be called.
        // Keep in mind that i is the SIZE of the input -- you may have to change it!
        time.binarySearch(i);

        // Capture the clock and subtract the start to get the total time elapsed.
        diff = clock() - start;

        // Convert clock_t into seconds as a floating point number.
        timeAmount = diff * 1.0 / CLOCKS_PER_SEC;

        // Print out first the size (i) and then the elapsed time.
        std::cout << i << " " << timeAmount << "\n";

        // We flush to ensure the timings is printed out.
        std::cout << std::flush;
    }
    return 0;
}

