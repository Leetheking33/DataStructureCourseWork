#include <stdlib.h>
#include <iostream>
#include "queue.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
    Queue<int> queue;
    queue.push(10);
    queue.push(30);
    queue.push(2);
    cout << "Queue: ";
    queue.print();
    Queue<int> copyQueue(queue);
    copyQueue.pop();
    cout << "Copy queue: ";
    copyQueue.print();
    queue.pop();
    queue.pop();
    queue.pop();
    cout << "Queue: ";
    queue.print();
}

