#include <cxxtest/TestSuite.h>
#include <iostream>
#include <limits.h>
#include <stdio.h>

#include "add.hpp"

class MyTestSuite1 : public CxxTest :: TestSuite {
    public:
    void test1 ( void ) {
	/* Fill in test case */
        TS_ASSERT_EQUALS(add( 1 , 2 ), 3 ) ;
        TS_ASSERT_EQUALS(add( 1 , 3 ), 4 ) ;
        TS_ASSERT_EQUALS(add( 1 , 4 ), 5 ) ;
        TS_ASSERT_EQUALS(add( 1 , 5 ), 6 ) ;
        TS_ASSERT_EQUALS(add( 1 , 6 ), 7 ) ;
    }
};
