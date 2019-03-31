#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cstdlib>
#include <string>
#include <vector>

template<class K, class V>
class Node {
    public:
        Node (K key, V value) {
            mKey = key;
            mValue = value;
            mDeleted = false;
            mIsEmpty = false;
        }
        Node () {
            mDeleted = false;
            mIsEmpty = true;
        }
        K mKey;
        V mValue;
        bool mDeleted, mIsEmpty;
};

/* HashTable via open addressing */
template<class K, class V>
class HashTable {
    private:
        /* Class to begin filling out...*/
        std::vector<Node<K, V> > mTable;
        float mLoadFactor;
        int mNumElements;
    public:
        /* Initialize the Hash Table with size size. */
        HashTable(const int size, const float loadFactor);

        /* Deconstructor shall free up memory */
        ~HashTable();

        /* Map key -> val.
         * Return true if sucessful (it is unique.)
         * Otheriwise return false.
         */
        bool insert(const K &key, const V &val);

        /* Print out the HashTable */
        void print() const;

        /* Remove the val associated with key.
         * Return true if found and removed.
         * Otherwise return false.
         */
        bool remove(const K &key);

        /* Retrieves the V val that key maps to. */
        V& operator[](const K &key);

	float loadFactor();
	
        float percentFull();
};

int hashcode(int key);
int hashcode(const std::string &key);

#include "hashtable.cpp"

#endif
