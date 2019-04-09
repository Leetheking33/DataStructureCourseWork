#ifdef GRAPHAM_H

#include <iostream>
#include <queue>
#include <algorithm>

template<class W>
GraphAM<W>::GraphAM() {
}

template<class W>
GraphAM<W>::GraphAM(const int vertices) {
}

template<class W>
int GraphAM<W>::addVertices(const int vertices) {
}

template<class W>
bool GraphAM<W>::removeVertex(int idx) {
}

template<class W>
bool GraphAM<W>::addEdge(const int start, const int end, const W &weight) {
}

template<class W>
bool GraphAM<W>::removeEdge(const int start, const int end) {
}

template<class W>
W GraphAM<W>::adjacent(const int start, const int end) {
}

template<class W>
void GraphAM<W>::depthFirstTraversal(void (*visit)(const int node)) {
}

template<class W>
void GraphAM<W>::breadthFirstTraversal(void (*visit)(const int node)) {
}

template<class W>
void GraphAM<W>::print() const {
}

template<class W>
GraphAM<W>::~GraphAM() {
}

#endif
