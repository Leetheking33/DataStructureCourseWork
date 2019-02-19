#include <stdlib.h>
#include <iostream>
#include "stack.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
    Stack<int> stack;
    stack.push(10);
    stack.push(30);
    stack.push(2);
    stack.print();
    Stack<int> copyStack(stack);
    copyStack.print();
}

