#ifdef QUEUE_H
#include "queue.hpp"

/* Empty constructor shall create an empty Queue! */
template<class T>
Queue<T>::Queue() {
}
/* Do a deep copy of queue into the this.
 * Note: This one uses a reference to a Queue!
 */
template<class T>
Queue<T>::Queue(const Queue<T> &queue) {
}
/* Deconstructor shall free up memory */
template<class T>
Queue<T>::~Queue() {
}
/* Return the current length (number of items) in the queue */
template<class T>
int Queue<T>::getLength() const {
}
/* Returns true if the queue is empty. */
template<class T>
bool Queue<T>::isEmpty() const {
}
/* Print out the Queue */
template<class T>
void Queue<T>::print() const {
}
/* Pushes the val to the end of the queue. */
template<class T>
bool Queue<T>::push(const T &val) {
}
/* returns the first element from the queue. */
template<class T>
T& Queue<T>::first() {
}
/* Removes the first element from the queue. */
template<class T>
void Queue<T>::pop() {
}
/* Returns if the two queues contain the same elements in the
 * same order.
 */
template<class T>
bool Queue<T>::operator==(const Queue<T> &queue) const {
}
/* Add a value to the queue with respect to priority.
 * For this function a lower number is a higher priority.
 * EX: If the Queue is of integers and is { 5, 10, 15} and I add 7, 
 * the new queue is { 5, 7, 10, 15}.
 */
template<class T>
void Queue<T>::addWithPriority(const T& val) {
}
/* Return the length of the shortest path, but with warps.  The map is
 * a 2D array with each cell having the following property
 *   0: Cell is open (passable)
 *  -1: Cell is a wall (unpassable)
 * > 0: Cell is a warp.
 * A warp is a value > 999999 and warps to the position 
 *    (<first three digits, second three digits).
 * Hence 1000 warps to (1, 0), and 203109 warps to (203, 109)
 * To get the x value: <cell>/1000
 * To get the y value: <cell>%1000
 */
template<class T>
int Queue<T>::getShortestPathWithWarps(int **map, int width, int length, int sx, int sy, int ex, int ey) {
}

#endif
