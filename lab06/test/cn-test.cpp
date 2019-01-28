#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "arrays.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            int array[] = { 7,34,342,-12,518,-3,12,14};
            TS_ASSERT_EQUALS(countNegatives(array, 8), 2);
            TS_ASSERT_EQUALS(countNegatives(array, 5), 1);
            TS_ASSERT_EQUALS(countNegatives(array, 3), 0);
        }
        void test2(void) {
            int array[] = {83,99,618,6,49,-40,7,559,-253};
            TS_ASSERT_EQUALS(countNegatives(array, 9), 2);
            TS_ASSERT_EQUALS(countNegatives(array, 8), 1);
            TS_ASSERT_EQUALS(countNegatives(array, 6), 1);
            TS_ASSERT_EQUALS(countNegatives(array, 5), 0);
        }
};

