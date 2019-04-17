#include "grapham.hpp"


void print(const int node) {
    std::cout << "Visiting: " << node << "\n";
}

int main(int argc, char *argv[]) {
    GraphAM<int> gam(4);

    gam.addEdge(0, 1, 10);
    gam.addEdge(0, 2, 17);
    gam.addEdge(1, 2, 25);
    gam.addEdge(2, 1, 57);
    gam.addEdge(2, 3, 30);
    gam.addEdge(3, 1, 85);
    gam.addEdge(3, 0, 15);
    //gam.removeEdge(0, 3);
    //gam.removeEdge(0, 3);
    //gam.removeEdge(0, 3);

    //gam.print();
	
    gam.dijkstraShortestPath(0, 2); 		
    //std::cout << gam.adjacent(0, 2) << "\n";
    //std::cout << gam.adjacent(2, 0) << "\n";
    gam.addEdge(2, 0, 350);
    //std::cout << gam.adjacent(2, 0) << "\n";

    //gam.breadthFirstTraversal(print);
}
