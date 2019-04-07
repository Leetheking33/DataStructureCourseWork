#include "priorityqueue.hpp"

int main(int argc, char *argv[]) {
    PriorityQueue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(56);
    pq.push(-432);
    pq.push(93);
    pq.push(88);
    pq.push(-6);
    pq.push(5);
    pq.print();
    cout << pq.pop() << endl;
    cout << pq.pop() << endl;
    cout << pq.pop() << endl;
    cout << pq.pop() << endl;
    cout << pq.pop() << endl;
    cout << pq.pop() << endl;
    pq.print();
}	
