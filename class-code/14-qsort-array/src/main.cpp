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

void qsort(int *ary, const int size) {
    int pivot, startLargestIndex;
    // WHEN USING RECURSION WRITE YOU BASE CASE FIRST.
    if (size <= 1) { return; }

    pivot = ary[0];
    startLargestIndex = 1;

    for (int i = 1; i < size; i++) {
        if (pivot > ary[i]) {
            int temp = ary[i];
            ary[i] = ary[startLargestIndex];
            ary[startLargestIndex] = temp;

            startLargestIndex++;
                       
        } 
    }

    ary[0] = ary[startLargestIndex - 1];
    ary[startLargestIndex - 1] = pivot;

    qsort(ary, startLargestIndex - 1);
    qsort(ary + startLargestIndex, size - startLargestIndex);
}

int main(int argc, char *argv[]) {
    print(toSort, 10);
    qsort(toSort, 10);
    print(toSort, 10);
}
