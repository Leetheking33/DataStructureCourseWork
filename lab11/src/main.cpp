#include <stdlib.h>
#include <iostream>
#include "queue.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    Queue<int> que;
    std::cout << que.first() << "\n";
    que.push(4);
    std::cout << que.first() << "\n";
    que.push(3);
    std::cout << que.first() << "\n";
    que.pop();
    std::cout << que.first() << "\n";
    /* You may write manual tests here. */
}

