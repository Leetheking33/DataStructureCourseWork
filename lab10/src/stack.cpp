#ifdef STACK_H
#include <stdlib.h>
#include <iostream>
#include "stack.hpp"
using namespace std;

template <class T>
Stack<T>::Stack() {
	mTop = NULL;
}

template <class T>
Stack<T>::Stack(const Stack<T> &stack) {
	sNode<T> *rover = stack.mTop;
	sNode<T> *newRov = NULL;
	
	if(stack.mTop == NULL){
		mTop = NULL;
	}
	else{
		for(int i=0; i < stack.mSize; i++){
			if(i == 0){
				sNode<T> *node = new sNode<T>();
				node->mData = rover->mData;
				node->mNext = NULL;
				mTop = node;
				rover = rover->mNext;
				newRov = mTop;
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
void Stack<T>::destroyStack(){
	sNode<T> *rover = mTop;
	sNode<T> *prev = mTop;

	while(rover != NULL){
		prev = rover;
		rover = rover->mNext;
		delete prev;
	}
	mTop = NULL;
	delete rover;
	mSize = 0;
}

template <class T>
Stack<T>::~Stack() {
	destroyStack();
}

template <class T>
int Stack<T>::getLength() const {
	return mSize;
}

template <class T>
bool Stack<T>::push(const T &val) {
	if(mTop == NULL){
		sNode<T> *node = new sNode<T>();
		node->mData = val;
		node->mNext = NULL;
		mTop = node;
		mSize = 1;
		return true;
	}
	
	sNode<T> *node = new sNode<T>();
	node->mData = val;
	node->mNext = mTop;
	mTop = node;
	mSize += 1;
}

template <class T>
T& Stack<T>::top() {
	return mTop->mData;
}

template <class T>
void Stack<T>::pop() {
	sNode<T> *rover = mTop;

	if(mTop->mNext == NULL){
		delete rover;
		mTop = NULL;
		mSize = 0;
	}
	else{
		delete rover;
		mTop = mTop->mNext;
		mSize -= 1;
	}
}

template <class T>
void Stack<T>::print() const {
	sNode<T> *rover = mTop;
	while(rover != NULL){
		cout << rover->mData << ", ";
		rover = rover->mNext;
	}
	cout << endl;
}

template <class T>
bool Stack<T>::isEmpty() const {
	if(mTop == NULL){
		return true;
	}
	return false;
}

template <class T>
bool Stack<T>::operator==(const Stack<T> &stack) const{
	sNode<T> *rover = mTop;
	sNode<T> *lover = stack.mTop;

	if(mSize != stack.mSize){
		return false;
	}

	if(mTop == NULL && stack.mTop == NULL){
		return true;
	}

	while(rover != NULL){
		if(rover->mData == lover->mData){
			rover = rover->mNext;
			lover = lover->mNext;
			continue;
		}
		return false;
	}
	return true;
}

#endif
