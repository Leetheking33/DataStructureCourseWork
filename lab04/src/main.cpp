#include <iostream>
#include <time.h>
#include "sums.h"

long problem1(int n);
long problem2(int n);
long problem3(int n);
long problem4(int n);
long problem5(int n);

int main(int argc, char *argv[]) {
     // Standard main heading.
    /* clock_t is the data type for storing timing information.
     * We must make two variables, one for the start and the other to capture
     * the difference.
     */
    clock_t start, diff;

    // timeAmount is used to print out the time in seconds.
    double timeAmount;

    // We want to run our algorithm over varying sizes.
    for (int i = 10000; i < 3000000; i += 100000) {
        // Capture the start clock
        start = clock();

        // This is were your algorithm should be called.
        // Keep in mind that i is the SIZE of the input -- you may have to change it!
	problem5(i);
	
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

long problem1(int n) {
    return sumOfOneToSquaredEnhanced(n);
}

long problem2(int n) {
    long ret = 0;
    
    for (int i = 0; i < 50; i++) {
        ret += sumOfOneTo(n);
    }

    return ret;
}

long problem3(int n) {
    long ret = 0;

    ret += sumOfOneToSquared(n);

    for (int i = 0; i < 10; i++) {
        ret += sumOfOneTo(n);
    }

    return ret;
}

long problem4(int n) {
    int ret = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < n; j *= 2) {
            ret += j;
        }
    }

    return ret;
}

long problem5(int n) {
    int ret = 0;

    for (int i = 1; i < n; i *= 2) {
        ret += sumOfOneTo(n);
    }

    return ret;
}





