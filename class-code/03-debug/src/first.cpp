#include <iostream>
#include "second.hpp"

int add(int a, int b) {
    int sum = a + b;

    return sum;
}

int mult(int a, int b) {
    int sum = a * b;

    return sum;
}

int main(int argc, char *argv[]) {
    int i;
    int b = 0;
    int sum = 0;

    int *ary = new int[100];
    int *ary2 = new int[100];

    for (i = 0; i < 100; i++) {
        ary[i] = i;
        sum += ary[i];
    }

    std::cout << "sum = " << sum << "\n";
    std::cout << "sum(123, 456) =  " << add(123, 456) << "\n";
    std::cout << "sum(123, 456) =  " << mult(123, 456) << "\n";

    delete [] ary;
    delete [] ary2;
}
