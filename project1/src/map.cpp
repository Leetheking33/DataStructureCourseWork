#include <map.hpp>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <iostream>
#include <cstring>
using namespace std;

Map::Map() {
	mHead = NULL;
}

bool Map::add(const char *key, int val) {
	mNode *rover = mHead;
	mNode *node = new mNode();

	if(mHead == NULL){
		mHead = node;
		node->val = val;	
		node->key = key;
		node->mNext = NULL;
		node->mPrev = NULL;
		mSize = 1;	
    		return true;
	}
	while(rover->mNext != NULL){
		rover = rover->mNext;
	}
	mSize += 1;
	node->val = val;
	node->key =key;
	node->mNext = NULL;
	node->mPrev = rover;
	rover->mNext = node;
	return true;
}

bool Map::get(const char *key, int &ret) {
	mNode *rover = mHead;
	
	if(mHead == NULL){
		return false;
	}

	while(rover != NULL){
		if(rover->key == key){
			ret = rover->val;
			return true;
		}
	}
    return false;
}

int Map::size() {
	return mSize;
}

bool Map::remove(const char *key) {
	mNode *rover = mHead;
	mNode *prev = NULL;
	mNode *inFront = NULL;

	if(mHead == NULL){
		return false;
	}

	if(rover->key == key){
		mHead = rover->mNext;
		inFront = rover->mNext;
		inFront->mPrev = NULL;
		delete rover;
		mSize -= 1;
		return true;
	}

	while(rover != NULL){
		if(rover->key == key){
			if(rover->mNext == NULL){
				prev->mNext = NULL;
				delete rover;
				mSize -= 1;
				return true;
			}
			else{
				inFront = rover->mNext;
				inFront->mPrev = prev;
				prev->mNext = rover->mNext;
				delete rover;
				mSize -= 1;
				return true;
			}	
		}

		prev = rover;
		rover = rover->mNext;
	}
    return false;
}

void Map::print() const {
	mNode *rover = mHead;
	while(rover != NULL){
		cout << "(" << rover->key << ", " << rover->val << ") ";
		rover = rover->mNext;
	}
	cout << endl;
		
}

int Map::howMany(const char *prefix) {
	mNode *rover = mHead;
	int confirmer = 0;
	int count = 0;
	int j = 0;
	size_t length;
	size_t preLen = strlen(prefix);
	
		while(rover != NULL){
		        length = strlen(rover->key);
			for(size_t i = 0; i < length; i++){
				while(rover->key[j] == prefix[j]){
					confirmer += 1;
					j += 1;
				}
				if(confirmer == preLen){
					count += 1;
					break;
				}
				else{
					break;
				}
			}
			j = 0;
			confirmer = 0;
			rover = rover->mNext;
		}
    return count;
    
}

void Map::destroyMap(){
	mNode *rover = mHead;
	mNode *prev = mHead;

	while(rover != NULL){
		prev = rover;
		rover = rover->mNext;
		delete prev;
	}
	mHead = NULL;
	delete rover;
	mSize = 0;

}

Map::~Map() {
	destroyMap();
}

