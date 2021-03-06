#ifndef MAP_H
#define MAP_H
#include <list>
using namespace std;

/*
class pair{
	public:
	const char *key;
	int val;

};
*/

class mNode{
	public:
	mNode *mNext;
	mNode *mPrev;
	const char *key;
        int val;	

};


class Map{
    private:
	mNode *mHead;	    
	int mSize = 0;


    public:
        Map();
        /* Adds (inserts) val with the associated key.
         * Returns if successful or not.  (It is not successful if we are out of
         * memory, or if the key already exists.)
         */
        bool add(const char *key, int val);
    
        /* Searches for the key.  If found it sets ret to the correct val and
         * returns true.  Otherwise this function returns false.
         */
        bool get(const char *key, int &ret);
    
        /* Returns the size (memory consumed) by this data structure. */
        int size();
    
        /* Removes the current value from the Map AND frees up any memory that
         * it can.
         * Returns true if there was something to remove, false otherwise.
         */
        bool remove(const char *key);

	void print() const;
    
        int howMany(const char *prefix);
   	
       	void destroyMap();

        /* Frees all memory */
        ~Map();
	//private:
        /* Store you data here.  I highly recommend talking to me about your
         * data structure before implementing. */
};

#endif
