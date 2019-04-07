#ifdef PRIORITY_QUEUE_H
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template<class T>
PriorityQueue<T>::PriorityQueue() {
}

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &pq) {
	for(int i = 0; i < mArr.size(); i++){
		pq.mArr[i] = mArr[i]; 
	}
	
	make_heap(pq.mArr.begin(), pq.mArr.end());
}

template<class T>
bool PriorityQueue<T>::push(const T &val){
	mArr.push_back(val);
	make_heap(mArr.begin(), mArr.end());
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {
}

#endif
