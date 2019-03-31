#include <stdio.h>
#include <iostream>
#include "hashtable.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    HashTable<int, int> table(100, .75);
    

    // Happy path
    table.insert(75, 75);

    // Sad path
    table.insert(175, 175);

    std::cout << table.percentFull() << "\n";
    return 0;
}
