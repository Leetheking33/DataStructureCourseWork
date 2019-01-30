#ifndef ARRAY_H__
#define ARRAY_H__

template <class T>
class Array {
    public:
        Array();
        Array(int size);
    private:
        T *mArray;
        int mSize;
};

#include "array.cpp"

#endif
