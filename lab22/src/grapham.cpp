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
int GraphAM<W>::minWeight(vector<gNode<W> > shortestPath, W &minPath, int &minIndex){

	for(int i = 0; i < shortestPath.size(); i++){
		if(shortestPath[i].Source){
			continue;
		}
		if(shortestPath[i].isEmpty() ){
			continue;
		}
		if(shortestPath[i].weight() < minPath){
			minPath = shortestPath[i].weight();
			minIndex = i;
		}	
	}
	return minIndex;
}

template<class W>
void GraphAM<W>::dijkstraShortestPath(vector<gNode<W> > &shortestPath, vector<bool> &visited, int &minIndex, W &minPath){
	int allVisited = 0;
	visited[minIndex] = true;

        //for(int i = 0; i < mVerts; i++){
        //initilize shortestPath vector
                for(int i = 0; i < mVerts; i++){
			if(visited[i]){
				continue;
			}

                        if(mGraph[minIndex][i].sameVert() ){
                                continue;
                        }
                        if(mGraph[minIndex][i].isEmpty() ){
                                continue;
                        }
			if(minPath + mGraph[minIndex][i].weight() < shortestPath[i].weight() )
                        //minIndex = i;
                        shortestPath[i].setWeight(mGraph[minIndex][i].weight() + minPath);
                }
		for(int i = 0; i < mVerts; i++){
			if(visited[i]){
				allVisited++;
			}
			if(allVisited == mVerts){
				return;
			}
			break;

		}
                minWeight(shortestPath, minPath, minIndex);
		dijkstraShortestPath(shortestPath, visited, minIndex, minPath);	
}
template<class W>
W GraphAM<W>::dijkstraShortestPath(const int start, const int end){
	vector<gNode<W> > shortestPath(mVerts);
	vector<bool> visited(mVerts, false);
	int minIndex = start;
        W minPath;	
	shortestPath[start].Source = true;
	visited[start] = true;
	for(int i = 0; i < mVerts; i++){
                        if(visited[i]){
                                continue;
                        }

                        if(mGraph[minIndex][i].sameVert() ){
                                continue;
                        }
                        else if(mGraph[minIndex][i].isEmpty() ){
                                continue;
                        }
                        //minIndex = i;
                        minPath = mGraph[minIndex][i].weight();
                        shortestPath[i].setWeight(mGraph[minIndex][i].weight());
	}
	minWeight(shortestPath, minPath, minIndex);


	dijkstraShortestPath(shortestPath, visited, minIndex, minPath);

	return shortestPath[end].weight();

			
		
}

template<class W>
GraphAM<W>::~GraphAM() {
}

#endif
