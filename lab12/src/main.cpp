#include <stdlib.h>
#include <iostream>
#include "array.hpp"
#include "sllist.hpp"
#include <time.h>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
    srand(100);	

    clock_t start, diff;

    // timeAmount is used to print out the time in seconds.
    double timeAmount;

    // We want to run our algorithm over varying sizes.
    for (int i = 100; i < 15000; i += 1000) {
	
	int *bigArray = new int[i];
	for(int j=0; j < i; j++){
		bigArray[j] = rand();
	}

	Array<int> test = Array<int>(bigArray, i);
	delete[] bigArray;

        // Capture the start clock
        start = clock();

        // This is were your algorithm should be called.
        // Keep in mind that i is the SIZE of the input -- you may have to change it!
        test.bubbleSort();

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

