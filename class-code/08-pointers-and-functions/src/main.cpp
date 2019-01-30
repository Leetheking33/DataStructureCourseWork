#include <iostream>
#include "second.hpp"

void dont_change_my_value(int val) {
    val *= 2;
}

void change_my_value(int *val) {
    *val *= 2;
}

void change_my_value2(int &val) {
    val *= 2;
}

int* give_me_an_int() {
    int *ret = new int;

    *ret = 0;

    return ret;
}

int main(int argc, char *argv[]) {
    int a = 4;

    std::cout << "a = " << a << "\n";

    dont_change_my_value(a);

    std::cout << "a = " << a << "\n";

    change_my_value(&a);

    std::cout << "a = " << a << "\n";

    change_my_value2(a);

    std::cout << "a = " << a << "\n";

    std::cout << "give_me_an_int() = " << give_me_an_int() << "\n";
    //print();
}
