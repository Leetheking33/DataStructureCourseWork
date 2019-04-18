#include "graphal.hpp"
using namespace std;

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
    gal.addEdge(6, 3, 88);
    gal.addEdge(8, 2, 88);
    
    
    
    gal.print();
    cout << "gal after remove vert 6: " << endl;
    gal.removeVertex(6);
    
    gal.print(); 
    cout << "gal after remove vert 6: " << endl;
    gal.removeVertex(1); 
    gal.print();

    //gal.breadthFirstTraversal(print);
}
