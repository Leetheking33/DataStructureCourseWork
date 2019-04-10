#include "graphal.hpp"

void print(const int node) {
    std::cout << node << "->";
}

int main(int argc, char *argv[]) {
    GraphAL<int> gal(10);

    gal.addEdge(1, 9, 50);
    gal.addEdge(0, 3, 75);
    gal.addEdge(9, 1, 35);
    gal.addEdge(3, 0, 57);
    gal.addEdge(2, 4, 9001);
    gal.addEdge(3, 6, 1098);
    gal.addEdge(7, 6, 67);
    gal.addEdge(8, 2, 88);

    gal.print();

    gal.removeEdge(2, 4);

    gal.print();

    gal.depthFirstTraversal(print);
}
