#include <iostream>
#include <list>
#include <queue>
#include <utility>

int toSort[] { 3,13,5,89,-53,4,27,44,1,-3 };

void print(int *ary, const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << ary[i] << " ";
    }
    std::cout << "\n";
}

void insertionSort(int *ary, const int size) {
    int newIndex = 0;
    int temp = 0;
    // We build a sorted list by adding the element @ ary[i].
    for (int i = 1; i < size; i++) {
       // 1. find the location to place the new number.
       newIndex = 0;
       for (int j = 0; j < i; j++) {
           if (ary[j] < ary[i]) {
               newIndex = j + 1;
           }
       } 

       temp = ary[i];

       for (int j = i; j > newIndex; j--) {
           ary[j] = ary[j-1];
       }

       ary[newIndex] = temp;
    }
}

int main(int argc, char *argv[]) {
    print(toSort, 10);
    insertionSort(toSort, 10);
    print(toSort, 10);
}
