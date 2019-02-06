#include <iostream>

void print(const int *ary, const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << ary[i] << ",";
    }
    std::cout << "\n";
}

void bubbleSort(int *ary, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (ary[j-1] > ary[j]) {
                int tmp = ary[j-1];
                ary[j-1] = ary[j];
                ary[j] = tmp;
            }
        }
    }
}

/* Return the index where val is in ary. */
int sequentialSearch(const int *ary, const int size, const int val) {
    for (int i = 0; i < size; i++) {
        if (ary[i] == val) {
            return i;
        }
    }

    return -1;
}

int binarySearchRec(const int *ary, const int size, const int val, const int offset) {
    // CHECK THE BASE CASE !!!!111$$$$ do it now!
    if (size <= 0) {
        return -1;
    }
    if (size == 1) {
        if (ary[0] == val) return offset;
        return -1;
    }

    int middle = size / 2;
    if (val == ary[middle]) {
        return middle + offset;
    } else if (val < ary[middle]) {
        return binarySearchRec(ary, (size + 1)/2, val, offset);
    } else {
        return binarySearchRec(ary + middle, (size + 1)/2, val, middle + offset);
    }
}

/* Return the index where val is in ary. */
int binarySearch(const int *ary, const int size, const int val) {
    int start = 0, end = size;
    int middle = (start + end)/2;
 
    while(start < end){
        if(val == ary[middle]){
           return middle;
        }
        else if (val < ary[middle]){
            end = middle;
            middle = (start + end)/2;
        }
        else if (val > ary[middle]){
            start = (middle+1);
            middle = (start + end)/2;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    int ary[] = {8, 5, 6, 7, 7, 7, 4, 3, 10, -110, -66, 0, 44, 42, 9644, 900002, -800};
    print(ary, 17);
    bubbleSort(ary, 17);
    print(ary, 17);
    //std::cout << "location of 6:" << sequentialSearch(ary, 17, 6) << "\n";
    //std::cout << "location of 6:" << binarySearch(ary, 17, 6) << "\n";
    //std::cout << "location of 5:" << binarySearch(ary, 17, 5) << "\n";
    //std::cout << "location of 9000:" << binarySearch(ary, 17, 9000) << "\n";
    std::cout << "location of 6:" << binarySearchRec(ary, 17, 6, 0) << "\n";
    std::cout << "location of 5:" << binarySearchRec(ary, 17, 5, 0) << "\n";
    std::cout << "location of 9000:" << binarySearchRec(ary, 17, 9000, 0) << "\n";
}
