// range heap example
#include <stdlib.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector
#include <set>          // std::set

std::vector<std::vector<int> > graph;

void depthFirstTraversal(std::vector<std::vector<int> > &graph, std::set<int> &visited, int currentPosition) {
    // Alays start with the base case:
    // If we have visited the currentPosition then return.
    if (visited.find(currentPosition) != visited.end()) {
        return;
    }

    std::cout << currentPosition;
    
    //Marks the current position as visited.
    visited.insert(currentPosition);

    for (unsigned int i = 0; i < graph[currentPosition].size(); i++) {
        // If an edge exists
        if (graph[currentPosition][i] > 0) {
            depthFirstTraversal(graph, visited, i);
        }
    }
}

int main () {
    // Initialize a graph with 10 nodes;
    graph.resize(10);
    for (int i = 0; i < 10; i++) {
        graph[i].resize(10);
        for (int j = 0; j < 10; j++) {
            graph[i][j] = -1;
        }
        graph[i][i] = 0;
    }

    //Add some edges
    graph[0][1] = 13;
    graph[0][2] = 12;
    graph[5][2] = 29;
    graph[0][8] = 12;
    graph[5][1] = 12;
    graph[7][2] = 12;
    graph[8][4] = 12;
    graph[9][2] = 12;
    graph[2][4] = 12;
    graph[2][1] = 12;
    graph[2][0] = 12;
    graph[2][3] = 12;
    graph[2][5] = 12;
    graph[2][6] = 12;
    graph[2][7] = 12;
    graph[2][8] = 12;
    graph[1][7] = 12;

    //Remove the edge from 2 to 7?
    graph[2][7] = -1;

    //What is the weight from 2 to 4?
    std::cout << "The weight from 2 to 4 is:" << graph[2][4] << "\n";

    std::set<int> visited;

    // Depth first traversal
    for (int i = 0; i < 10; i++) {
        depthFirstTraversal(graph, visited, i);
    }

  return 0;
}
