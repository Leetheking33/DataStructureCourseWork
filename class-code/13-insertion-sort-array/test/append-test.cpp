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

        TS_ASSERT_EQUALS(list[0], 7 ) ;
        TS_ASSERT_EQUALS(list[1], 72 ) ;
        TS_ASSERT_EQUALS(list[2], 13 ) ;
    }
};
