#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "heap.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            int array[] = {4, 7, 3, 19, 34, 2, 8, 13, 15, 20};
            Heap<int> heap(10);
            for (int i = 0; i < 10; i++) {
                heap.insert(array[i]);
            }
            printf("\n");
            for (int i = 0; i < 10; i++) {
                printf("%d ", heap[i]);
            }
            printf("\n");
            TS_ASSERT(heap[0] == 34);
        }
};
