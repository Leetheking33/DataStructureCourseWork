#ifdef HEAP_H

template<class T>
Heap<T>::Heap(const int len) {
    mCapacity = len;
    mLength = 0;
    mArray = new T[mCapacity];
}

template<class T>
void Heap<T>::insert(const T& element) {
    // Make sure we have the space.
    if (mLength == mCapacity) {
        
    }

    // Add to the end of the heap
    mArray[mLength++] = element;

    //Now sift up
    /*
    if (((mLength-1) % 2) == 0) {
        parent = mLength - 1 - 2;
        parent /= 2;
    } else {
        parent = mLength - 1 - 1;
        parent /= 2;
    } Complicated method */
    int current = mLength -1;
    int parent = (current - 1) / 2;

    while (current > 0) {
        // First check if we need to swap.
        if (mArray[parent] < mArray[current]) {
            T temp = mArray[parent];
            mArray[parent] = mArray[current];
            mArray[current] = temp;
	    delete mArray[temp];
        } else {
            break;
        }

        //Update current and parent
        current = parent;
        parent = (current - 1) / 2;
    }
}

template<class T>
T& Heap<T>::removeFirst(){
    T firstIndex = mArray[0];
    int leftChildIndex = 1;
    int rightChildIndex = 2;
    int current = 0;

    // swap
    int temp = mArray[0];
    mArray[0] = mArray[mLength - 1];
    mArray[mLength - 1] = temp;
    mLength--;

    // Come up with a way to check if leftChildIndex or rightChildIndex is out of bounds.
    while(mArray[leftChildIndex] > mArray[current] || mArray[rightChildIndex] > mArray[current]) {
        temp = mArray[current];
        if(mArray[leftChildIndex] > mArray[current]) {
            mArray[current] = mArray[leftChildIndex];
            mArray[leftChildIndex] = temp;
            current = leftChildIndex;
        }
        else {
            mArray[current] = mArray[rightChildIndex];
            mArray[rightChildIndex] = temp;
            current = rightChildIndex;
        }

        leftChildIndex = (2*current) + 1;
    }
    return firstIndex;
}

template<class T>
T& Heap<T>::operator[](const int pos) {
    return mArray[pos];
}

template<class T>
T* Heap<T>::heapSort() {
}

template<class T>
Heap<T>::~Heap() {
	delete mArray;
}
#endif
