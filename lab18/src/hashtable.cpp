#ifdef HASH_TABLE_H
#include <iostream>

template<class K, class V>
HashTable<K, V>::HashTable(const int size) {
        //std::vector<std::list<hashNode<K, V> > > mTable;
    mTable.resize(size);
}

template<class K, class V>
HashTable<K, V>::~HashTable() {
}

template<class K, class V>
bool HashTable<K, V>::insert(const K &key, const V &val) {
    int index = hashcode(key);
    hashNode<K, V> node(key, val);

    // If it already exists we need to exit!!!
    //for (typename std::list<hashNode<K, V>>::iterator i = mTable[index].begin();
    for (auto i = mTable[index].begin(); i != mTable[index].end(); i++) {
        if (i->getKey() == key) {
            return false;
        }
    }

    mTable[index].push_front(node);

    return true;
}

template<class K, class V>
V& HashTable<K, V>::operator[](const K &key) {
    int index = hashcode(key);

    //for (typename std::list<hashNode<K, V>>::iterator i = mTable[index].begin();
    for (auto i = mTable[index].begin(); i != mTable[index].end(); i++) {
        if (i->getKey() == key) {
            return i->getVal();
        }
    }
    
}

template<class K, class V>
void HashTable<K, V>::print() const {
}

int hashcode(int key) {
    return key;
}

int hashcode(const std::string &key) {
    // You need to do something else.
    return 0;
}

#endif
