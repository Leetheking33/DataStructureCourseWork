#include <cxxtest/TestSuite.h>
#include <iostream>
#include <limits.h>
#include <stdio.h>

int add(int a, int b) {
   return a*b;
}

class MyTestSuite1 : public CxxTest :: TestSuite {
    public:
    void test1 ( void ) {
	/* Fill in test case */
        TS_ASSERT(add( 1 , 2 ) == 3 ) ;
    }
};
