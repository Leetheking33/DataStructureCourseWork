#include "grapham.hpp"

void print(const int node) {
    std::cout << "Visiting: " << node << "\n";
}

int main(int argc, char *argv[]) {
    GraphAM<int> gam(10);

    gam.addEdge(0, 2, 450);
    gam.addEdge(0, 5, 1);
    gam.addEdge(0, 3, 9001);
    gam.removeEdge(0, 3);

    gam.print();


    std::cout << gam.adjacent(0, 2) << "\n";
    std::cout << gam.adjacent(2, 0) << "\n";
    gam.addEdge(2, 0, 350);
    std::cout << gam.adjacent(2, 0) << "\n";

    gam.breadthFirstTraversal(print);
}
