#ifdef GRAPHAL_H
#include <iostream>
#include <limits>
template <class W>
GraphAL<W>::GraphAL(){
}

template <class W>
GraphAL<W>::GraphAL(const int vertices){
    	mGraph.resize(vertices);
}


template <class W>
bool GraphAL<W>::addEdge(const int start, const int end, const W &weight){
    	mGraph[start].push_back(Edge<W>(end, weight));
    	return true;
}

template <class W>
bool GraphAL<W>::removeEdge(const int start, const int end){
    	for (auto i = mGraph[start].begin(); i != mGraph[start].end(); i++){
        	if (i->getDestination() == end){
            		mGraph[start].erase(i);
            		return true;
        	}
    	}

    	return false;
}

template <class W>
void GraphAL<W>::addVertices(int amt){
}

template <class W>
W GraphAL<W>::adjacent(const int start, const int end){
    return -1;
}

template <class W>
bool GraphAL<W>::removeVertex(int idx){
	// First iterate through entire graph removing ALL edges that end with idx.
    	// Next, update all edges that end with somehting grater than idx by subtracting one from end.
    	//  in other words, subtract 1 from all edges that end with a vertex > idx.
    	for (int i = 0; i < mGraph.size(); i++){
        	for (auto it = mGraph[i].begin(); it != mGraph[i].end(); ++it)
            	if (it->getDestination() == idx){
                	mGraph[i].erase(it);
                	break;
            	}
            	else if (it->getDestination() > idx){
                	it->setDestination((it->getDestination() - 1));
            	}
    	}
    	mGraph.erase(mGraph.begin() + --idx);
}

template <class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node), int node, bool *visited){
    if (visited[node]){
        return;
    }

    visited[node] = true;
    visit(node);

    for (typename std::list<Edge<W>>::iterator it = mGraph[node].begin(); it != mGraph[node].end(); ++it){
        depthFirstTraversal(visit, it->getDestination(), visited);
    }
}

template <class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node) ){
    bool visited[mGraph.size()];
    for (int i = 0; i < mGraph.size(); i++){
        visited[i] = false;
    }
    for (int i = 0; i < mGraph.size(); i++){
        depthFirstTraversal(visit, i, visited);
    }
}

template <class W>
void GraphAL<W>::breadthFirstTraversal(void (*visit)(const int node), int node, std::set<int> &visited){
	std::queue<int> tovisit;
	if (visited.find(node) == visited.end() ){
		tovisit.push(node);
	}

	while (!tovisit.empty()){
		int vertex = tovisit.front();
		tovisit.pop();

        	visit(vertex);

        	visited.insert(vertex);

        	for (auto i = mGraph[vertex].begin(); i != mGraph[vertex].end(); i++){
            		int toadd = i->getDestination();
            		if (visited.find(toadd) == visited.end() ){
                		tovisit.push(toadd);
                		visited.insert(toadd);
                	}
               	} 
    	}
}

template <class W>
void GraphAL<W>::breadthFirstTraversal(void (*visit)(const int node) ){
	std::set<int> visited;
	for (int i = 0; i < mGraph.size(); i++){
		breadthFirstTraversal(visit, i, visited);
    	}
}

template <class W>
void GraphAL<W>::print(){
	for (int i = 0; i < mGraph.size(); i++){
        	std::cout << "[" << i << "]:";
        	for (auto j = mGraph[i].begin(); j != mGraph[i].end(); j++){
            		std::cout << "(" << j->getDestination() << ", " << j->getWeight() << "),";
		}
		std::cout << "\n";
	}
}

template <class W>
W GraphAL<W>::prims(const int start){
       	return 6;
    	
}

template <class W>
GraphAL<W>::~GraphAL(){
}

#endif

