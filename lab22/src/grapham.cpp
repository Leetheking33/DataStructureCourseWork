#ifdef GRAPHAM_H

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;

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
		
        	mGraph[i][i].makeFull(0);
    	}
}

template<class W>
int GraphAM<W>::addVertices(const int amt) {
	mGraph.resize(amt);
	
	 mVerts += amt;
	for (int i = 0; i < mVerts; i++) {
        	mGraph[i].resize(amt);
		
		mGraph[i][i].makeFull(0);			
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
	mGraph[start][end].makeFull(1);
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
int GraphAM<W>::minWeight(vector<gNode<W> > shortestPath, W firstPath, int minIndex){
	W min = firstPath;

	for(int i = 0; i < shortestPath.size(); i++){
		if(shortestPath[i].source){
			continue;
		}
		if(!shortestPath[i].hasPath){
			continue;
		}
		if(shortestPath[i].getWeight() < min){
			min = shortestPath[i].weight();
			minIndex = i;
		}	
	}
	return minIndex;
}

template<class W>
W GraphAM<W>::dijkstraShortestPath(const int start, const int end){
	vector<gNode<W> > shortestPath(mVerts);
	vector<bool> visited(mVerts, false);
	int current;
        W firstPath;	
		shortestPath[0].Source = true;
		visited[0] = true;
	//for(int i = 0; i < mVerts; i++){
		for(int i = 0; i < mVerts; i++){

			if(i == 0){
				continue;
			}
		       	else if(!mGraph[0][i].hasPath() ){	
				continue;
			}
			current = i;
			firstPath = mGraph[0][i].weight();
			shortestPath[i].setWeight(mGraph[0][i].weight()); 
		} 
		
}

template<class W>
GraphAM<W>::~GraphAM() {
}

#endif
