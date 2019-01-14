#include <iostream>

int add(int a, int b) {
    int sum = a + b;

    return sum;
}

int mult(int a, int b) {
    int product = 0;

    for (int i = 0; i < a; i++) {
        product = add(product, b);
    }

    return product;
}

int getsum(int *ary, const int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += ary[i];
    }

    return sum;
}

void doAdd(int *sum, int a, int b) {
    *sum = a + b;
}

int main(int argc, char *argv[]) {
    int a = 5;
    int b = 10;
    int thesum = 0;
    int stackary[10];
    char *buff = new char[1024];

    int *ary = new int[100];

    std::cout << add(a, b) << "\n";
    std::cout << mult(a, b) << "\n";
    std::cout << "stackary = " << stackary << "\n";
    std::cout << "ary = " << ary << "\n";

    for (int i = 0; i < 100; i++) {
        ary[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        stackary[i] = i;
    }

    std::cout << "getsum(ary) = " << getsum(ary, 100) << "\n";
    std::cout << "getsum(stackary) = " << getsum(stackary, 10) << "\n";

    for (int i = 0; i < 10; i++) {
        std::cout << "(ary + " << i << ") = " << (ary+i) << "\n";
    }
    for (int i = 0; i < 10; i++) {
        std::cout << "(buff + " << i << ") = " << (void*)(buff+i) << "\n";
    }

    doAdd(&thesum, a, b);

    delete []ary;

    return 0;
}
