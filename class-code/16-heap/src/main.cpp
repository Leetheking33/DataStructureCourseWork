#include <iostream>
#include <list>
#include <queue>
#include <utility>



#define SIZE (8)
static int size = SIZE;
int ary[] = {12, 34, 6, -8, 99, 134, 566, -89};

void print() {
    for (int i = 0; i < SIZE; i++) {
        std::cout << ary[i] << " ";
    }
    std::cout << "\n";
}

void heapify() {
    int parentIndex = 0, currentIndex;
    for (int i = 1; i < SIZE; i++) {
        parentIndex = (i-1)/2;
        currentIndex = i;
        while (ary[parentIndex] < ary[currentIndex]) {
            int temp = ary[currentIndex];
            ary[currentIndex] = ary[parentIndex];
            ary[parentIndex] = temp;

            currentIndex = parentIndex; 
            parentIndex = (parentIndex - 1) / 2;
        }
    }
}

void remove() {
    int leftChildIndex = 1;
    int rightChildIndex = 2;
    int current = 0;

    // swap
    int temp = ary[0];
    ary[0] = ary[size - 1];
    ary[size - 1] = temp;
    size--;

    // Come up with a way to check if leftChildIndex or rightChildIndex is out of bounds.
    while(ary[leftChildIndex] > ary[current] || ary[rightChildIndex] > ary[current]) {
        temp = ary[current];
        if(ary[leftChildIndex] > ary[current]) {
            ary[current] = ary[leftChildIndex];
            ary[leftChildIndex] = temp;
            current = leftChildIndex;
        }
        else {
            ary[current] = ary[rightChildIndex];
            ary[rightChildIndex] = temp;
            current = rightChildIndex;
        }

        leftChildIndex = (2*current) + 1;
        rightChildIndex = (2*current) + 2;
    }
}

int main(int argc, char *argv[]) {
    heapify();
    print();
    remove();
    print();
}
