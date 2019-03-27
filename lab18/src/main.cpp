#include <stdio.h>
#include "hashtable.hpp"

int main(int argc, char *argv[]) {
    HashTable<int, int> table(100);
    
    table.insert(58, 85);
   
    table.insert(38, 83);
    table.insert(34, 43);
   // table.insert(134, 431);
    table.insert(34, 44);
    	    
    table.print();
    
    table.remove(58);

    table.print();
    return 0;
}
