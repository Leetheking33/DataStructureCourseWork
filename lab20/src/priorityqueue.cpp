#ifdef PRIORITY_QUEUE_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
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
bool PriorityQueue<T>::isEmpty() const{
	return mArr.empty(); 
}

template<class T>
T PriorityQueue<T>::pop(){
	T temp = mArr[0];
	mIt = mArr.begin();
	mArr.erase(mIt);
	return temp;
}

template<class T>
bool PriorityQueue<T>::operator==(const PriorityQueue<T> &pq) const{
	if(mArr.size() != pq.mArr.size()){
		return false;
	}
	
	for(int i = 0; i < mArr.size(); i++){
		if(mArr[i] != pq.mArr[i]){
			return false;
		}
	}
	return true;
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {
}

#endif
