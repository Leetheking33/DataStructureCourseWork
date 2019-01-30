#ifdef ARRAY_H__

#include <stdlib.h>
#include "array.hpp"

template <class T>
Array<T>::Array() {
    mSize = 0;
    mArray = NULL;
}

template <class T>
Array<T>::Array(int size) {
    mSize = size;
    mArray = new int[mSize];
}

#endif
