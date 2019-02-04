#ifdef SLLIST_HPP

template<class T>
SLList<T>::SLList() {
    mHead = NULL;
}

/* Do a deep copy of sll into the this.
 * Note: This one uses a reference to a Singly Linked List!
 */
template<class T>
SLList<T>::SLList(const SLList<T> &sll) {
}

template<class T>
SLList<T>::~SLList() {
}

template<class T>
bool SLList<T>::append(const T &val) {
    SNode<T> *node = new SNode<T>();
    node->mData = val;

    node->mNext = mHead;
    mHead = node;
    
    return false;
}

template<class T>
void SLList<T>::print() const {
    SNode<T> *rover = mHead;

    while (rover != NULL) {
        std::cout << rover->mData << ", ";
        rover = rover->mNext;
    }

    std::cout << "\n";
}

/* Return the current length of the Singly Linked List */
template<class T>
int SLList<T>::getLength() const {
    return 0;
}

/* Insert val at position pos.
 * Return true if successful (it can be placed.)
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::insert(const int pos, const T &val) {
    SNode<T> *rover = mHead;
    SNode<T> *prev = NULL;

    SNode<T> *ToAdd = new SNode<T>();

    ToAdd->mData = val;

    for (int i = 0; i < pos; i++) {
        if(rover->mNext == NULL){
            return false;
        }
        prev = rover;
        rover = rover->mNext;
    }

    ToAdd->mNext = rover;
    if (pos == 0){
        mHead = ToAdd;
    }
    else
        prev->mNext = ToAdd;

    return false;
}

/* Remove the first instance of val
 * Return true if found and removed.
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::remove(const T &val) {
    SNode<T> *rover = mHead;
    
    SNode<T> *prev = NULL;

    while(rover != NULL){
        if(rover->mData == val){
            if (prev == NULL) {
                mHead = rover->mNext;
            } else {
                prev->mNext = rover-> mNext;
            }
            delete rover;
            return true;
        }

        prev = rover;
        rover = rover->mNext;
    }

    return false;
}

template<class T>
T& SLList<T>::operator[](const int pos) {
    SNode<T> *rover = mHead;

    for(int i = 0; i < pos; i++) {
        rover = rover->mNext;
    }

    return rover->mData;
}

template<class T>
bool SLList<T>::operator==(const SLList<T> &list) const {
    return false;
}

#endif
