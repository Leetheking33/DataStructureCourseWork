#ifdef HASH_TABLE_H
#include <iostream>

template<class K, class V>
HashTable<K, V>::HashTable(const int size) {
}

template<class K, class V>
HashTable<K, V>::~HashTable() {
}

template<class K, class V>
bool HashTable<K, V>::insert(const K &key, const V &val) {
}

template<class K, class V>
V& HashTable<K, V>::operator[](const K &key) {
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
