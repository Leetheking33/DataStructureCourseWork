#ifdef QUEUE_H
#include <stdlib.h>
#include <iostream>
#include "queue.hpp"
#include <queue>
#include <utility>
#include <list>

using namespace std;

template <class T>
Queue<T>::Queue() {
        mFirst = NULL;
}

template <class T>
Queue<T>::Queue(const Queue<T> &queue) {
        qNode<T> *rover = queue.mFirst;
        qNode<T> *newRov = NULL;

        if(queue.mFirst == NULL){
                mFirst = NULL;
        }
        else{
                for(int i=0; i < queue.mSize; i++){
                        if(i == 0){
                                qNode<T> *node = new qNode<T>();
                                node->mData = rover->mData;
                                node->mNext = NULL;
                                mFirst = node;
                                rover = rover->mNext;
                                newRov = mFirst;
                                mSize +=1;
                        }
                        else{
                                qNode<T> *node = new qNode<T>();
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
void Queue<T>::destroyQueue(){
        qNode<T> *rover = mFirst;
        qNode<T> *prev = mFirst;

        while(rover != NULL){
                prev = rover;
                rover = rover->mNext;
                delete prev;
        }
        mFirst = NULL;
        delete rover;
        mSize = 0;
}

template <class T>
Queue<T>::~Queue() {
        destroyQueue();
}

template <class T>
int Queue<T>::getLength() const {
        return mSize;
}

template <class T>
bool Queue<T>::push(const T &val) {
	qNode<T> *rover = mFirst;
	qNode<T> *trailer;
	qNode<T> *node = new qNode<T>();
	if(mFirst == NULL){
		node->mData = val;
		node->mNext = mFirst;
		mFirst = node;
		mSize = 1;
		return true;
	}
	while(rover != NULL){
		trailer = rover;
		rover = rover->mNext;
	}
	mSize +=1;
	node->mData = val;
	node->mNext = NULL;
	trailer->mNext =node;
}

template <class T>
T& Queue<T>::first() {
        return mFirst->mData;
}

template <class T>
void Queue<T>::pop() {
        qNode<T> *rover = mFirst;

        if(mFirst->mNext == NULL){
                delete rover;
                mFirst = NULL;
                mSize = 0;
        }
        else{
                delete rover;
                mFirst = mFirst->mNext;
                mSize -= 1;
        }
}

template <class T>
void Queue<T>::print() const {
        qNode<T> *rover = mFirst;
        while(rover != NULL){
                cout << rover->mData << ", ";
                rover = rover->mNext;
        }
        cout << endl;
}

template <class T>
bool Queue<T>::isEmpty() const {
        if(mFirst == NULL){
                return true;
        }
        return false;
}

template <class T>
bool Queue<T>::operator==(const Queue<T> &queue) const{
        qNode<T> *rover = mFirst;
        qNode<T> *lover = queue.mFirst;

        if(mSize != queue.mSize){
                return false;
        }

        if(mFirst == NULL && queue.mFirst == NULL){
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

template<class T>
int Queue<T>::getShortestPathWithWarps(int **map, int width, int length, int sx, int sy, int ex, int ey){

	std::queue<Point> toVisit;

	toVisit.push(Point(sx, sy, 0));

	while(!toVisit.empty()) {
		Point point = toVisit.front();
		toVisit.pop();


		if (point.x < 0 || point.y < 0 || point.x > width || point.y > length) {
			continue;
		}	

		if(point.x == ex && point.y == ey) {
			return point.numMoves;
		}

		if (map[point.x][point.y] == -1 || map[point.x][point.y] == -2){
			continue;
		}

		map[point.x][point.y] = -2;

		toVisit.push(Point(point.x, point.y + 1, point.numMoves + 1));

		toVisit.push(Point(point.x, point.y - 1, point.numMoves + 1));

		toVisit.push(Point(point.x - 1, point.y, point.numMoves + 1));

		toVisit.push(Point(point.x + 1, point.y, point.numMoves + 1));

	}

	return -1;
}
#endif
