#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "arrays.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            int array[] = { 7,34,342,-12,518,-3,12,14};
            TS_ASSERT_EQUALS(findMinOdd(array, 8), -3);
            TS_ASSERT_EQUALS(findMinOdd(array, 5), 7);
            TS_ASSERT_EQUALS(findMinOdd(array, 3), 7);
        }
        void test2(void) {
            int array[] = {83,99,618,6,49,-40,7,559,-253};
            TS_ASSERT_EQUALS(findMinOdd(array, 9), -253);
            TS_ASSERT_EQUALS(findMinOdd(array, 8), 7);
            TS_ASSERT_EQUALS(findMinOdd(array, 6), 49);
            TS_ASSERT_EQUALS(findMinOdd(array, 5), 49);
        }
};

