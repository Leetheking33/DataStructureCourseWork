#ifdef SLLIST_HPP
using namespace std;

template<class T>
SLList<T>::SLList() {
	mHead = NULL;
}

/* Do a deep copy of sll into the this.
 * Note: This one uses a reference to a Singly Linked List!
 */
template<class T>
SLList<T>::SLList(const SLList<T> &sll) {
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

template<class T>
void SLList<T>::destroyList(){
        sNode<T> *rover = mHead;
        sNode<T> *prev = mHead;

        while(rover != NULL){
                prev = rover;
                rover = rover->mNext;
                delete prev;
        }
        mHead = NULL;
        delete rover;
	mSize = 0;
}


template<class T>
SLList<T>::~SLList() {
	destroyList();
}

template<class T>
bool SLList<T>::append(const T &val) {
	sNode<T> *rover = mHead;
	sNode<T> *trailer;
	sNode<T> *node = new sNode<T>();
	if(mHead == NULL){
		node->mData = val;
		node->mNext = mHead;
		mHead = node;
		mSize = 1;	
		return false;
	}
	while(rover != NULL){
		trailer = rover;
		rover = rover->mNext;
	}
	mSize += 1;
	node->mData = val;
	node->mNext = NULL;
	trailer->mNext = node;

}

template<class T>
void SLList<T>::print() const {
	sNode<T> *rover = mHead;
	while(rover != NULL){
		cout << rover->mData << ", ";
		rover = rover->mNext;		
	}
	cout << endl;
}

/* Return the current length of the Singly Linked List */
template<class T>
int SLList<T>::getLength() const {
	return mSize;
}

/* Insert val at position pos.
 * Return true if successful (it can be placed.)
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::insert(const int pos, const T &val) {
	sNode<T> *rover = mHead;
        sNode<T> *prev = NULL;



        if(pos == 0 && mSize == 0){
                sNode<T> *node = new sNode<T>();
                node->mData = val;
                node->mNext = NULL;
                mHead = node;
                mSize += 1;
                return true;
        }

        if(pos == 0 && mSize == 1){
                sNode<T> *node = new sNode<T>();
                node->mData = val;
                node->mNext = rover;
                mHead = node;
                mSize += 1;
                return true;
        }

        if(pos == 0){
                sNode<T> *node = new sNode<T>();
                node->mData = val;
                node->mNext = rover;
                mHead = node;
                mSize += 1;
                return true;
        }

        for(int i=0; i < pos; i++){
                if(rover->mNext == NULL){
                        return false;
                }

                prev = rover;
                rover = rover->mNext;
        }
        sNode<T> *node = new sNode<T>();
        node->mData = val;
        node->mNext = rover;
        prev->mNext = node;
        mSize += 1;
        return true;
}

/* Remove the first instance of val
 * Return true if found and removed.
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::remove(const T &val) {
	sNode<T> *rover = mHead;
	sNode<T> *prev = NULL;

	if(mHead == NULL){
		return false;
	}

	if(rover->mData == val){
			mHead = rover->mNext;
                        delete rover;
			mSize -=1;
                        return true;
	}

	while(rover != NULL){
		if(rover->mData == val){
			prev->mNext = rover->mNext;
			delete rover;
			mSize -= 1;
			return true;
		}
		prev = rover;
		rover = rover->mNext;
	}
	return false;
}

template<class T>
T& SLList<T>::operator[](const int pos) {
	sNode<T> *rover = mHead;
	for(int i=0; i < mSize; i++){
		if(i == pos){
			return rover->mData;
		}
		rover = rover->mNext;
	}
	return rover->mData;
}

template<class T>
bool SLList<T>::operator==(const SLList<T> &list) const {
	sNode<T> *rover = mHead;
	sNode<T> *lover = list.mHead;
	
	if(mSize != list.mSize){
		return false;
	}
	
	if(mHead == NULL && list.mHead == NULL){
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
void SLList<T>::sort(){
	sNode<T> *rover = mHead;

	 for(int iter=1; iter < mSize; iter++){
			for(int i=0; i < mSize - iter; i++){
				if(rover == NULL){
					break;
				}	
				if(rover->mData > rover->mNext->mData){
					T tmp = rover->mData;
					rover->mData = rover->mNext->mData;
					rover->mNext->mData = tmp;
					rover = rover->mNext;
				}
			}
	 }
}

#endif
