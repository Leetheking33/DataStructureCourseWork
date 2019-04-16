#ifdef GRAPHAM_H

#include <iostream>
#include <queue>
#include <algorithm>

template<class W>
GraphAM<W>::GraphAM() {
	mVerts = 0;
}

template<class W>
GraphAM<W>::GraphAM(const int vertices) {
	mGraph.resize(vertices);
	mVerts = vertices;
    	for (int i = 0; i < vertices; i++) {
        	mGraph[i].resize(vertices);
		
        	mGraph[i][i].setSameVert(0);
    	}
}

template<class W>
int GraphAM<W>::addVertices(const int amt) {
	mGraph.resize(amt);
	
	 mVerts += amt;
	for (int i = 0; i < mVerts; i++) {
        	mGraph[i].resize(amt);
		
		mGraph[i][i].setSameVert(0);			
	}
}

template<class W>
bool GraphAM<W>::removeVertex(int idx) {
}

template<class W>
bool GraphAM<W>::addEdge(const int start, const int end, const W &weight) {
	if(start > mVerts || start > mVerts){
		return false;
	}

	mGraph[start][end].setWeight(weight);
	return true;
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
