#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "stack.hpp"
#include "queue.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            Stack<int> st;
            st.push(15);
            TS_ASSERT(st.top() == 15);
        }
        void test2(void) {
            Stack<int> st;
            st.push(15);
            TS_ASSERT(st.top() == 15);
            st.pop();
            st.push(25);
            TS_ASSERT(st.top() == 25);
        }
        void test3(void) {
            Stack<int> st;
            st.push(15);
            TS_ASSERT(st.top() == 15);
            st.pop();
            st.push(25);
            st.print();
            TS_ASSERT(st.top() == 25);
            st.push(35);
            st.print();
            TS_ASSERT(st.top() == 35);
            st.pop();
            TS_ASSERT(st.top() == 25);
        }
        void test4(void) {
            Stack<int> st;
            TS_ASSERT(st.isEmpty());
            st.push(15);
            TS_ASSERT(!st.isEmpty());
            st.pop();
            TS_ASSERT(st.isEmpty());
            st.push(25);
            TS_ASSERT(!st.isEmpty());
            st.push(35);
            TS_ASSERT(!st.isEmpty());
            st.pop();
            TS_ASSERT(!st.isEmpty());
        }
};

