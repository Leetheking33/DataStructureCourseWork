#ifdef HASH_TABLE_H
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;
template<class K, class V>
HashTable<K, V>::HashTable(const int size) {
   // std::vector<std::list<hashNode<K, V> > > mTable;
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
	//might //cause error if mTable is pointer
	//std::list<hashNode<K, V> >::iterator it;	 
	cout << "(" << mTable[0].getKey() << "," << mTable[0].getVal() << ")";
	if(mTable.empty()){
		return;
	}
	for(unsigned int i = 0; i < mTable.capacity(); i++){
		if(mTable[i].empty()){
			break;
		} else {
			for(auto it = mTable[i].begin(); it != mTable[i].end(); it++) {
				cout << "(" <<  it->getKey() << "," << it->getVal() << ") "; 
			}

		}
	 
	}
	cout << endl;
	return;
}

int hashcode(int key) {
    return key;
}

int hashcode(const std::string &key) {
    // You need to do something else.
    return 0;
}

#endif
