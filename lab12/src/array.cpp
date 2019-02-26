/* Array is templated, therefore only include the code if it is included from
 * the header file! 
 */
#ifdef ARRAY_H
#include <stdio.h>
#include <iostream>

/* Do a deep copy of the array into the list.
 * Note: This one uses a pointer!
 */
template <class T>
Array<T>::Array(const T *array, const int size){
	mArr = new T[size];
	mSize = size;
	for(int i=0; i < size; i++){
		mArr[i] = array[i];
	}

}

/* Do a deep copy of the array into the list
 * Note: This one uses a reference to a List!
 */
template <class T>
Array<T>::Array(const Array<T> &list){
	//Create a new array that has the length of list
	mArr = new T[list.mSize];
	//This changes our array object size to list's size
	mSize = list.mSize;
	
	for(int i=0; i < mSize; i++){
		mArr[i] = list.mArr[i];
	}

}

/* Retrieves the element at position pos */
template <class T>
T& Array<T>::operator[](const int pos){
	return mArr[pos];
}

template <class T>
int Array<T>::getLength() const {
	return mSize;	
}

template <class T>
Array<T>::~Array() {
	delete mArr;
}

template <class T>
int Array<T>::indexOf(const T &value){
	for(int i=0; i<mSize; i++){
		if(mArr[i] == value){
			return i;
		}	
	}
	return -1;
}

template <class T>
bool Array<T>::remove(const int index){
	if(index >= 0 && index < mSize){
		for(int i= index; i < mSize - 1; i++){
			mArr[i] = mArr[i + 1];
                }
		mSize -= 1;
                return true;
        }
return false;
}

template <class T>
bool Array<T>::operator==(Array<T> &list) const{
	if(list.mSize == mSize){
		for(int i=0; i< mSize; i++){
			if(mArr[i] != list.mArr[i]){
				return false;		
			}
		}
		return true;
	}
	return false;
}

template <class T>
void Array<T>::bubbleSort(){
        for(int iter=1; iter < mSize; iter++){
                for(int i=0; i < mSize - iter; i++) {
                        if(mArr[i] > mArr[i+1]){
                                T tmp = mArr[i];
                                mArr[i] = mArr[i+1];
                                mArr[i+1] = tmp;
                        }
                }
        }
}

template<class T>
int Array<T>::minLocation(int first, int last){
	int minIndex;

	minIndex = first;

	for(int i = first + 1; i <= last; i++){
		if(mArr[i] < mArr[minIndex])
			minIndex = i;
	}

	return minIndex;
}

template<class T>
void Array<T>::swap(int first, int second){
	T temp;

	temp = mArr[first];
	mArr[first] = mArr[second];
	mArr[second] = temp;
}

template<class T>
void Array<T>::selectionSort(){
	int minIndex;

	for(int i=0; i < mSize; i++){
		minIndex = minLocation(i, mSize - 1);
		swap(i, minIndex);
	}
}

template<class T>
void Array<T>::insertionSort(){
	for(int i = 1; i < mSize; i++){
		if(mArr[i] < mArr[i -1]){
			T temp = mArr[i];
			int index = i;

			do{
				mArr[index] = mArr[index - 1];
				index--;
			}
			while(index > 0 && mArr[index - 1] > temp);

			mArr[index] = temp;
		}
	}
}

template<class T>
void Array<T>::sort(){
		for(int i = 1; i < mSize; i++){
                if(mArr[i] < mArr[i -1]){
                        T temp = mArr[i];
                        int index = i;

                        do{
                                mArr[index] = mArr[index - 1];
                                index--;
                        }
                        while(index > 0 && mArr[index - 1] > temp);

                        mArr[index] = temp;
                }
        }
}

#endif
