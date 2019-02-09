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

	for(int i=0; i < sll.mSize; i++){
		if(i == 0){
			sNode<T> *node = new sNode<T>();
                	node->mData = rover->mData;
			node->mNext = NULL;
			mHead = node;
			rover = rover->mNext;
			newRov = mHead;
		}
		else{
		sNode<T> *node = new sNode<T>();
		node->mData = rover->mData;
		node->mNext = NULL;
		newRov->mNext = node;
		rover = rover->mNext;
		newRov = newRov->mNext;	
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
}

/* Remove the first instance of val
 * Return true if found and removed.
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::remove(const T &val) {
}

template<class T>
T& SLList<T>::operator[](const int pos) {
	sNode<T> *rover = mHead;
	for(int i=0; i < mSize; i++){
		if(i == pos){
			return rover->mData;
		}
		rover->mNext;
	}
	return mHead->mData;
}

template<class T>
bool SLList<T>::operator==(const SLList<T> &list) const {
}

#endif