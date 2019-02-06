#include <iostream>

int main(int argc, char *argv[]) {
    srand(100);

    int *bigarray = new int[10000000];
    for (int i = 0; i < 10000000; i++) {
        bigarray[i] = rand();
    }

    // The way to test
    // 1) copy over the numbers you want:
    //    NOTE that 100 would be i
    for (int j = 0; j < 100; j++) {
        /*
        Array<int> DUT = new Array(biarray, 100);
        clock();
        DUT.sequentialSearch(val);
        clock();
        */
    }


    delete [] bigarray;
}
