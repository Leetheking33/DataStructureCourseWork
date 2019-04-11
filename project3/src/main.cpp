#include <stdio.h>
#include "SGtree.hpp"
#include "AVLtree.hpp"
#include <time.h>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
    /*
    AVLtree<int> t;
 
    std::cout << "Inserting integer values 1 to 10" << std::endl;
    for (int i = 1; i <= 10; ++i)
        t.insert(i);
 
    std::cout << "Printing balance: ";
    t.printBalance();
    */
    srand(100);

    clock_t start, diff;

    // timeAmount is used to print out the time in seconds.
    double timeAmount;

    // We want to run our algorithm over varying sizes.
    for (int i = 100; i < 90000; i += 1000) {

	SGTree t;
	for(int j=0; j < 100; j++){
		t.insert(rand());
	}
        // Capture the start clock
        start = clock();

        // This is were your algorithm should be called.
        // Keep in mind that i is the SIZE of the input -- you may have to change it!
        t.deleteNode(rand());

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
