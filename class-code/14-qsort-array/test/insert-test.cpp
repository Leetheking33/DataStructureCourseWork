#include <cxxtest/TestSuite.h>
#include <iostream>
#include <limits.h>
#include <stdio.h>

#include "sllist.hpp"

class MyTestSuite1 : public CxxTest :: TestSuite {
    public:
    void test1 ( void ) {
	/* Fill in test case */
    SLList<int> list;

    list.append(13);
    list.append(72);
    list.append(7);
    list.append(95);
    list.append(26);
    list.insert(2, 9000);

        TS_ASSERT_EQUALS(list[0], 26 ) ;
        TS_ASSERT_EQUALS(list[1], 95 ) ;
        TS_ASSERT_EQUALS(list[2], 9000 ) ;
        TS_ASSERT_EQUALS(list[3], 7 ) ;
        TS_ASSERT_EQUALS(list[4], 72 ) ;
        TS_ASSERT_EQUALS(list[5], 13 ) ;
    }
    void test2 ( void ) {
	/* Fill in test case */
    SLList<int> list;

    list.append(13);
    list.append(72);
    list.append(7);
    list.append(95);
    list.append(26);
    list.insert(0, 9000);

        TS_ASSERT_EQUALS(list[0], 9000 ) ;
        TS_ASSERT_EQUALS(list[1], 26 ) ;
        TS_ASSERT_EQUALS(list[2], 95 ) ;
        TS_ASSERT_EQUALS(list[3], 7 ) ;
        TS_ASSERT_EQUALS(list[4], 72 ) ;
        TS_ASSERT_EQUALS(list[5], 13 ) ;
    }
};
