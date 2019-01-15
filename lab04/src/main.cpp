#include <iostream>
#include <time.h>
#include "sums.h"

long problem1(int n);
long problem2(int n);
long problem3(int n);
long problem4(int n);
long problem5(int n);

int main(int argc, char *argv[]) {
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
