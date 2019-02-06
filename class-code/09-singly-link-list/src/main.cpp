#include <iostream>
#include "sllist.hpp"

int main(int argc, char *argv[]) {
    SLList<int> list;

    list.append(13);
    list.append(72);
    list.append(7);
    list.append(95);
    list.append(26);

    list.remove(26);

    list.print();
}
