#ifdef GRAPHAL_H
#include <iostream>

template<class W>
GraphAL<W>::GraphAL() {
}

template<class W>
GraphAL<W>::GraphAL(const int vertices) {
}

/* Adds an edge with weight W to the graph. */
template<class W>
bool GraphAL<W>::addEdge(const int start, const int end, const W &weight) {
    return true;
}

template<class W>
bool GraphAL<W>::removeEdge(const int start, const int end) {
    return false;
}

/* Adds amt vertices to the graph. */
template<class W>
void GraphAL<W>::addVertices(int amt) {
}

template<class W>
W GraphAL<W>::adjacent(const int start, const int end) {
    return -1;
}

/* Removes a vertex. 
 * return wheter sucessful or not
 */
template<class W>
bool GraphAL<W>::removeVertex(int idx) {
    // First iterate through entire graph removing ALL edges that end with idx.
    // Next, update all edges that end with somehting grater than idx by subtracting one from end.
    //  in other words, subtract 1 from all edges that end with a vertex > idx.
}

template <class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node), int node, bool *visited) {
}

template <class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node)) {
}

template <class W>
void GraphAL<W>::print() {
}

template<class W>
GraphAL<W>::~GraphAL() {
}

#endif
