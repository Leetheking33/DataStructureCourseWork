#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "arrays.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            int array[] = { 7,34,342,-12,518,-3,12,14};
            TS_ASSERT_EQUALS(remove(array, 8, -100), false);
            TS_ASSERT_EQUALS(remove(array, 8, 100), false);
        }

        void test2(void) {
            int array[] = { 7,34,342,-12,518,-3,12,14};
            TS_ASSERT_EQUALS(remove(array, 8, 5), true);
            int ans1[]  = { 7,34,342,-12,518,12,14,14};
            for (int i = 0; i < 8; i++) {
                TS_ASSERT_EQUALS(array[i], ans1[i]);
            }
        }

        void test3(void) {
            int array[] = {83,99,618,6,49,-40,7,559,-253};
            TS_ASSERT_EQUALS(remove(array, 9, 3), true);
            int ans1[] =  {83,99,618,49,-40,7,559,-253,-253};
            for (int i = 0; i < 9; i++) {
                TS_ASSERT_EQUALS(array[i], ans1[i]);
            }
        }

        void test4(void) {
            int array[] = { 7,34,342,-12,518,-3,12,14};
            TS_ASSERT_EQUALS(remove(array, 8, 7), true);
            int ans1[] = { 7,34,342,-12,518,-3,12,14};
            for (int i = 0; i < 8; i++) {
                TS_ASSERT_EQUALS(array[i], ans1[i]);
            }
        }
};

