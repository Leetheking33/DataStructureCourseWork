#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <numeric>

int max(std::vector<int>::iterator start, std::vector<int>::iterator end) {
    int max = *start;

    while (start != end) {
        if (*start > max) {
            max = *start;
        }
        start++;
    }

    return max;
}

static int sum = 0;

class cubed_sum {
    public:
        int operator()(int sum, int nextValue) {
            return sum + (nextValue * nextValue * nextValue);
        }
};

void addToSum(int val) {
    sum += val;
}

void vectorFun() {
    int nums[] = {12, 5, 67, 98, 100};

    std::vector<int> myVector(nums, nums + 5);

    std::cout << myVector.back() << "\n";
    myVector.pop_back();
    std::cout << myVector.back() << "\n";
    myVector.push_back(9001);
    std::cout << myVector.back() << "\n";
    std::cout << myVector.front() << "\n";
    std::cout << myVector[2] << "\n";

    for (unsigned int i = 0; i < myVector.size(); i++) {
        std::cout << myVector[i] << " ";
    }
    std::cout << "\n";

    for (std::vector<int>::iterator i = myVector.begin();
            i != myVector.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    for (auto i = myVector.begin(); i != myVector.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    std::cout << "Max: " << max(myVector.begin(), myVector.end()) << "\n";

    for_each(myVector.begin(), myVector.end(), addToSum);
    std::cout << "Sum: " << sum << "\n";

    //int nums[] = {12, 5, 67, 98, 100};
    std::vector<int>::iterator pos = find(myVector.begin(), myVector.end(), 5);

    std::cout << *(pos + 1) << "\n";
}

void listFun() {
    int nums[] = {12, 5, 67, 98, 100};

    std::list<int> myList(nums, nums + 5);

    std::cout << myList.back() << "\n";
    myList.pop_back();
    std::cout << myList.back() << "\n";
    myList.push_back(9001);
    std::cout << myList.back() << "\n";
    std::cout << myList.front() << "\n";
    //std::cout << myList[2] << "\n";

    //for (unsigned int i = 0; i < myList.size(); i++) {
        //std::cout << myList[i] << " ";
    //}
    //std::cout << "\n";

    for (std::list<int>::iterator i = myList.begin();
            i != myList.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    for (auto i = myList.begin(); i != myList.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    //std::cout << "Max: " << max(myList.begin(), myList.end()) << "\n";

    for_each(myList.begin(), myList.end(), addToSum);
    std::cout << "Sum: " << sum << "\n";

    //int nums[] = {12, 5, 67, 98, 100};
    std::list<int>::iterator pos = find(myList.begin(), myList.end(), 5);

    std::cout << *(++pos) << "\n";

    std::cout << 
        accumulate(myList.begin(), myList.end(), 0, cubed_sum())
        << "\n";
}


int main(int argc, char *argv[]) {
    //vectorFun();
    listFun();
}
