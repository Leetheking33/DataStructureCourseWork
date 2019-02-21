/* Array is templated, therefore only include the code if it is included from
 * the header file! 
 */
#ifdef ARRAY_H
#include <stdio.h>

/* Do a deep copy of the array into the list.
 * Note: This one uses a pointer!
 */
template <class T>
Array<T>::Array(const T *array, const int size){
    mArray = new T[size];
    mLen = size;
    for (int i = 0; i < mLen; i++) {
        mArray[i] = array[i];
    }
}

/* Do a deep copy of the array into the list
 * Note: This one uses a reference to a List!
 */
template <class T>
Array<T>::Array(const Array<T> &list){
}

/* Retrieves the element at position pos */
template <class T>
T& Array<T>::operator[](const int pos){
    return mArray[pos];
}

template <class T>
void Array<T>::msort(T *list, const int len) {
}

template <class T>
void Array<T>::msort() {
}

template <class T>
Array<T>::~Array() {
}

#endif
