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
        // expand capcity
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
        } else {
            break;
        }

        //Update current and parent
        current = parent;
        parent = (current - 1) / 2;
    }
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
}
#endif
