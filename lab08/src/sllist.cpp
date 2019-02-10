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
SLList<T>::~SLList() {
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

//This is  DLL fucnctions
template<class T>
DLList<T>::DLList() {
        mHead = NULL;
}

/* Do a deep copy of sll into the this.
 * Note: This one uses a reference to a Singly Linked List!
 */
template<class T>
DLList<T>::DLList(const DLList<T> &dll) {
        dNode<T> *rover = dll.mHead;
        dNode<T> *newRov = NULL;

        if(dll.mHead == NULL){
                mHead = NULL;
        }
        else{

                for(int i=0; i < dll.mSize; i++){
                        if(i == 0){
                                dNode<T> *node = new dNode<T>();
                                node->mData = rover->mData;
                                node->mNext = NULL;
				node->mPrev = NULL;
				mHead = node;
                                rover = rover->mNext;
                                newRov = mHead;
                                mSize +=1;
                        }
                        else{
                        dNode<T> *node = new dNode<T>();
                        node->mData = rover->mData;
                        node->mNext = NULL;
			node->mPrev = newRov;
                        newRov->mNext = node;
                        rover = rover->mNext;
                        newRov = newRov->mNext;
                        mSize +=1;
                        }
                }
        }
}

template<class T>
DLList<T>::~DLList() {
}

template<class T>
bool DLList<T>::append(const T &val) {
        dNode<T> *rover = mHead;
	dNode<T> *node = new dNode<T>();
        if(mHead == NULL){
                node->mData = val;
                node->mNext = NULL;
		node->mPrev = NULL;
                mHead = node;
                mSize = 1;
                return true;
        }
        while(rover->mNext != NULL){
                rover = rover->mNext;
        }
        mSize += 1;
        node->mData = val;
        node->mNext = NULL;
	node->mPrev = rover;
	rover->mNext =node;
}

template<class T>
void DLList<T>::print() const {
        dNode<T> *rover = mHead;
        while(rover != NULL){
                cout << rover->mData << ", ";
                rover = rover->mNext;
        }
	cout << endl;
}

/* Return the current length of the Singly Linked List */
template<class T>
int DLList<T>::getLength() const {
        return mSize;
}

/* Insert val at position pos.
 * Return true if successful (it can be placed.)
 * Otherwise return false.
 */
template<class T>
bool DLList<T>::insert(const int pos, const T &val) {
        dNode<T> *rover = mHead;
        dNode<T> *prev = NULL;


	
	if(pos == 0 && mSize == 0){
		dNode<T> *node = new dNode<T>();
		node->mData = val;
		node->mPrev = NULL;
		node->mNext = NULL;
		mHead = node;
		mSize += 1;
		return true;
	}

	if(pos == 0 && mSize == 1){
		dNode<T> *node = new dNode<T>();
		node->mData = val;
		node->mNext = rover;
		node->mPrev = NULL;
		rover->mPrev = node;
		mHead = node;
		mSize += 1;
		return true;
	}

	if(pos == 0){
		dNode<T> *node = new dNode<T>();
		node->mData = val;
		node->mNext = rover;
		node->mPrev = NULL;
                rover->mPrev = node;
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
	dNode<T> *node = new dNode<T>();
	node->mData = val;
        node->mNext = rover;
        prev->mNext = node;
	node->mPrev = prev;
        mSize += 1;
        return true;
}

/* Remove the first instance of val
 * Return true if found and removed.
 * Otherwise return false.
 */
template<class T>
bool DLList<T>::remove(const T &val) {
        dNode<T> *rover = mHead;
        dNode<T> *prev = NULL;
	dNode<T> *inFront = NULL;

	if(mHead == NULL){
                return false;
        }

        if(rover->mData == val){
                        mHead = rover->mNext;
			inFront = rover->mNext;
			inFront->mPrev = NULL;
                        delete rover;
                        mSize -=1;
                        return true;
        }

        while(rover != NULL){
                if(rover->mData == val){
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

template<class T>
T& DLList<T>::operator[](const int pos) {
        dNode<T> *rover = mHead;
        for(int i=0; i < mSize; i++){
                if(i == pos){
                        return rover->mData;
                }
                rover = rover->mNext;
        }
        return rover->mData;
}

template<class T>
bool DLList<T>::operator==(const DLList<T> &list) const {
        dNode<T> *rover = mHead;
        dNode<T> *lover = list.mHead;

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

#endif
