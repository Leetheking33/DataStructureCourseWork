#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <vector>
#include <list>
template<class K, class V>
class hashNode {
    private:
        K mKey;
        V mVal;
    public:
        hashNode(K key, V val) { mKey = key; mVal = val; }
        K& getKey () { return mKey; }
        V& getVal() { return mVal; }
};

/* HashTable via chaining */
template<class K, class V>
class HashTable {
    private:
        std::vector<std::list<hashNode<K, V> > > mTable;
    public:
        /* Initialize the Hash Table with size size. */
        HashTable(const int size);

        /* Deconstructor shall free up memory */
        ~HashTable();

        /* Map key -> val.
         * Return true if sucessful (it is unique.)
         * Otheriwise return false.
         */
        bool insert(const K &key, const V &val);

        /* Print out the HashTable */
        void print();

        /* Remove the val associated with key.
         * Return true if found and removed.
         * Otherwise return false.
         */
        bool remove(const K &key);

        /* Retrieves the V val that key maps to. */
        V& operator[](const K &key);

};

int hashcode(int key);
int hashcode(const std::string &key);

#include "hashtable.cpp"

#endif
