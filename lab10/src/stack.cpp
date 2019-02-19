#ifdef STACK_H
#include <stdlib.h>
#include <iostream>
#include "stack.hpp"

template <class T>
Stack<T>::Stack() {
	mHead = NULL;
}

template <class T>
Stack<T>::Stack(const Stack<T> &sll) {
	sNode<T> *rover = sll.mHead;
	sNode<T> *newRov = NULL;
	
	if(sll.mHead == NULL){
		mHead = NULL;
	}
	else{
		for(int i=0; i < sll.mSize; i++){
			if(i == 0){
				sNode<T> *node = new sNode<T>();
				node->mData = rover->mData;
				node->mNext = NULL;
				mHead = node;
				rover = rover->mNext;
				newRov = mHead;
				mSize +=1;
			}
			else{
				sNode<T> *node = new sNode<T>();
				node->mData = rover->mData;
				node->mNext = NULL;
				newRov->mNext = node;
				rover = rover->mNext;
				newRov = newRov->mNext;
				mSize +=1;
			}
		}
	}	
}

template <class T>
Stack<T>::~Stack() {
}

template <class T>
int Stack<T>::getLength() const {
	return mSize;
}

template <class T>
bool Stack<T>::push(const T &val) {
}

template <class T>
T& Stack<T>::top() {
}

template <class T>
void Stack<T>::pop() {
}

template <class T>
void Stack<T>::print() const {
}

template <class T>
bool Stack<T>::isEmpty() const {
}

#endif
