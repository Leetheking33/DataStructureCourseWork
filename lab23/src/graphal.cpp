#ifdef GRAPHAL_H
#include <iostream>
#include <vector>
template<class W>
GraphAL<W>::GraphAL() {
}

template<class W>
GraphAL<W>::GraphAL(const int vertices) {
    mGraph.resize(vertices);
}

/* Adds an edge with weight W to the graph. */
template<class W>
bool GraphAL<W>::addEdge(const int start, const int end, const W &weight) {
    mGraph[start].push_back(Edge<W>(end, weight));
    return true;
}

template<class W>
bool GraphAL<W>::removeEdge(const int start, const int end) {
    //for(int i = 0; i < mGraph[start].size(); i++) {
    for (auto i = mGraph[start].begin(); i != mGraph[start].end(); i++){
        if (i->getDestination() == end) {
            mGraph[start].erase(i);
            return true;
        }
    }

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
    /*if(mGraph.size() > idx){
		
		mGraph.erase(mGraph.begin() + idx);			

		for(int j = 0; j < mGraph.size(); j++){
		 	if(mGraph[j].empty()){
				continue;
			}
			for(auto it = mGraph[j].begin(); it != mGraph[j].end(); it++){
				if(it->getDestination() == idx){
					it = mGraph[j].erase(it);	
				}
			       	if(it->getDestination() > idx){
					it->updateEdge();
					//std::cout << "error" << std::endl;
				}	
			}	
		}
		return true;
    }
    return false; */
	for (int i = 0; i < mGraph.size(); i++)
    {
        for (auto it = mGraph[i].begin(); it != mGraph[i].end(); ++it)
            if (it->getDestination() == idx)
            {
                mGraph[i].erase(it);
                break;
            }
            else if (it->getDestination() > idx)
            {
                it->setDestination((it->getDestination() - 1));
            }
    }
    mGraph.erase(mGraph.begin() + --idx);
}

template <class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node), int node, bool *visited) {
}

template <class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node)) {
}

template <class W>
void GraphAL<W>::breadthFirstTraversal(void (*visit)(const int node), int node, std::set<int> &visited) {
    std::queue<int> tovisit;
    // Only add node if it isn't in the visited set
    if (visited.find(node) == visited.end()) {
        tovisit.push(node);
    }

    while (!tovisit.empty()) {
        int vertex = tovisit.front();
        tovisit.pop();

        visit(vertex);

        visited.insert(vertex);

        for (auto i = mGraph[vertex].begin(); i != mGraph[vertex].end(); i++) {
            int toadd = i->getDestination();
            if (visited.find(toadd) == visited.end()) {
                tovisit.push(toadd);
            }
        }
    }
}

template <class W>
void GraphAL<W>::breadthFirstTraversal(void (*visit)(const int node)) {
    std::set<int> visited;
    for (int i = 0; i < mGraph.size(); i++) {
        breadthFirstTraversal(visit, i, visited);
    }
}

template <class W>
void GraphAL<W>::print() {
    for (int i = 0; i < mGraph.size(); i++) {
        std::cout << "[" << i << "]:";
        for (auto j = mGraph[i].begin(); j != mGraph[i].end(); j++) {
            std::cout << "(" << j->getDestination() << ", " <<
                j->getWeight() << "),";
        }
        std::cout << "\n";
    }
}

template<class W>
GraphAL<W>::~GraphAL() {
}

#endif
