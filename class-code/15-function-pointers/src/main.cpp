#include <iostream>
#include <list>
#include <queue>
#include <utility>

void print(int &val) {
    std::cout << "I got: " << val << "!\n";
}

int sum = 1;

void getSum(int &val) {
    sum += val;
}

void getProduct(int &val) {
    sum *= val;
}

void getProductChar(char &val) {
    sum *= val;
}

void callFunction(void (*visit) (int &val)) {
    for (int i = 1; i < 15; i++) {
        visit(i);
    }
}

int main(int argc, char *argv[]) {
    //callFunction(&print);
    //callFunction(&getSum);
    //std::cout << "The sum is: " << sum << "\n";
    callFunction(&getProduct);
    std::cout << "The Product is: " << sum << "\n";
    //callFunction(&getProductChar);
}
