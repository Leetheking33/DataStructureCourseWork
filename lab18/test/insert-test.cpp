#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "hashtable.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            HashTable<int, int> ht(100);
            ht.insert(99, 9001);
            TS_ASSERT_EQUALS(ht[99], 9001);
        }
};
