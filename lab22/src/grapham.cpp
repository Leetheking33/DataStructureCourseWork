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
int GraphAM<W>::minWeight(vector<gNode<W> > shortestPath, W lastPath, int &minIndex){
	W min = lastPath;

	for(int i = 0; i < shortestPath.size(); i++){
		if(shortestPath[i].Source){
			continue;
		}
		if(shortestPath[i].isEmpty() ){
			continue;
		}
		if(shortestPath[i].weight() < min){
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
	int minIndex;
        W lastPath;	
		shortestPath[start].Source = true;
		visited[start] = true;
	//for(int i = 0; i < mVerts; i++){
	//initilize shortestPath vector
		for(int i = 0; i < mVerts; i++){

			if(mGraph[start][i].sameVert() ){
				continue;
			}
		       	else if(mGraph[start][i].isEmpty() ){	
				continue;
			}
			minIndex = i;
			lastPath = mGraph[start][i].weight();
			shortestPath[i].setWeight(mGraph[start][i].weight()); 
		}
	       	cout << minWeight(shortestPath, lastPath, minIndex);	
		
}

template<class W>
GraphAM<W>::~GraphAM() {
}

#endif
