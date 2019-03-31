#ifdef HASH_TABLE_H

#include <cstdlib>

template<class K, class V>
HashTable<K, V>::HashTable(const int size, const float loadFactor) {
    mLoadFactor = loadFactor;
    mNumElements = 0;
    mTable.resize(size);
}

template<class K, class V>
bool HashTable<K, V>::insert(const K &key, const V &val) {
    int index = hashcode(key) % mTable.capacity();
    int startIndex = index;

    if (mTable[index].mDeleted || mTable[index].mIsEmpty) {
        mTable[index].mKey = key;
        mTable[index].mValue = val;
        mTable[index].mDeleted = false;
        mTable[index].mIsEmpty = false;
        mNumElements++;
        return true;

    }

    index++;
    while (index != startIndex) {
        // Need to check if we have found
	if(mTable[index].mDeleted || mTable[index].mIsEmpty){
        // Then add!
	mTable[index].mKey = key;
        mTable[index].mValue = val;
        mTable[index].mDeleted = false;
        mTable[index].mIsEmpty = false;
        mNumElements++;
	}

        index = (index + 1) % mTable.capacity();
	
    }
    return false;
}

template<class K, class V>
float HashTable<K, V>::percentFull() {
    return (float)mNumElements/(float)mTable.capacity();
}

template<class K, class V>
HashTable<K, V>::~HashTable() {
}

int hashcode(int key) {
    int num = (key * 74) / 2;	
    return num;
}

int hashcode(const std::string &key) {
    // You need to do something else.
    return 0;
}

#endif
