//ID - 211821137
//GMAIL - shira1d2631@gmail.com

#include "Graph.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>

namespace ariel {

    Graph::Graph() : numVertices(0), edgeCount(0),isWeighted(false) {}

    Graph::Graph(const std::vector<std::vector<int>>& matrix) {
        loadGraph(matrix); // Load the graph using the given adjacency matrix
    }

    void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
        // Same implementation as before
        int size = matrix.size();
        for (const auto& row : matrix) { // Check if the matrix is square
            if (row.size() != size) {
                throw std::invalid_argument("Invalid graph: The matrix is not square.");
            }
        }

        bool isWeightedCheck = false; // Check if the graph is weighted
        isWeighted = isWeightedCheck;

        adjacencyMatrix = matrix;
        numVertices = size;

        edgeCount = 0;
        for (std::size_t i = 0; i < matrix.size(); i++) { // Count the number of edges
        for (std::size_t j = 0; j < matrix[i].size(); j++) { // Count the number of edges
        if (matrix[i][j] != 0) { //if the matrix not zero so we have weight
    
                    edgeCount++;
                }
            }
        }
    }

    void Graph::printGraph() const {
        std::cout << "Graph with " << numVertices << " vertices and " << edgeCount << " edges." << std::endl;
    }

    int Graph::getnumvertices() const {
        return numVertices;
    }

    int Graph::getedgecount() const {
        return edgeCount;
    }

   int Graph::getadjacencymatrix(std::size_t i, std::size_t j) const {
    return adjacencyMatrix[i][j];
}

}
