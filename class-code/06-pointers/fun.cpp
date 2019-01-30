#include <iostream>

int main(int argc, char *argv[]) {
    int ary[100];
    int *ary2 = new int[100];
    int **a = &ary2;

    int b = 300;
    int *b_ptr = &b;
    std::cout << "b_ptr (before cast)   = " << b_ptr << "\n";
    double *d = (double*)b_ptr;
    std::cout << "b (before setting d)  = " << b << "\n";
    *d = 3.14159;
    std::cout << "b_ptr(after settingd) = " << b_ptr << "\n";
    std::cout << "*b_ptr(after settingd)= " << *b_ptr << "\n";
    std::cout << "d (after setting d)   = " << d << "\n";
    std::cout << "b (after setting d)   = " << b << "\n";
    std::cout << "*d (after setting d)  = " << *d << "\n";
    return 0;
}
