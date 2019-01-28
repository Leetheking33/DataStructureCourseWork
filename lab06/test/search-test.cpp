#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "arrays.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test3(void) {
            int array[] = { 7,34,342,-12,518,-3,12,14};
            TS_ASSERT_EQUALS(search(array, 8, 999), -1);
        }
        void test1(void) {
            int array[] = { 7,34,342,-12,518,-3,12,14};
            TS_ASSERT_EQUALS(search(array, 8, 34), 1);
            TS_ASSERT_EQUALS(search(array, 8, -3), 5);
            TS_ASSERT_EQUALS(search(array, 8, 12), 6);
        }
        void test2(void) {
            int array[] = {83,99,618,6,49,-40,7,559,-253};
            TS_ASSERT_EQUALS(search(array, 9, -253), 8);
            TS_ASSERT_EQUALS(search(array, 9, 7), 6);
            TS_ASSERT_EQUALS(search(array, 9, 6), 3);
            TS_ASSERT_EQUALS(search(array, 9, 83), 0);
        }
};

