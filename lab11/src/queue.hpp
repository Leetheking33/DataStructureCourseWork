#ifndef QUEUE_H
#define QUEUE_H

class Point{
	public:
		Point(int a, int b, int moves){
			x=a;
			y=b;
			numMoves = moves;
		}
	int x;
	int y;
	int numMoves;
};

template<class T>
class qNode {
        public:
        T mData;
        qNode *mNext;
};


template<class T>
class Queue {
    private:
	qNode<T> *mFirst;
        int mSize =0;	
			
        /* Class to implement.*/
    public:
        /* Empty constructor shall create an empty Queue! */
        Queue();
        /* Do a deep copy of queue into the this.
         * Note: This one uses a reference to a Queue!
         */
        Queue(const Queue<T> &queue);
        /* Deconstructor shall free up memory */
	void destroyQueue();

        ~Queue();
        /* Return the current length (number of items) in the queue */
        int getLength() const;
        /* Returns true if the queue is empty. */
        bool isEmpty() const;
        /* Print out the Queue */
        void print() const;
        /* Pushes the val to the end of the queue. */
        bool push(const T &val);
        /* returns the first element from the queue. */
        T& first();
        /* Removes the first element from the queue. */
        void pop();
        /* Returns if the two queues contain the same elements in the
         * same order.
         */
        bool operator==(const Queue<T> &queue) const;
	
	void addWithPriority(const T &val);

	int getShortestPathWithWarps(int **map, int width, int length, int sx, int sy, int ex, int ey);
};

#include "queue.cpp"

#endif
