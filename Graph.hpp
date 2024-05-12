//ID - 211821137
//GMAIL - shira1d2631@gmail.com

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stdexcept>

namespace ariel {
    class Graph {
    private:
        std::vector<std::vector<int>> adjacencyMatrix; // Adjacency matrix representation of the graph
        int numVertices; // Number of vertices in the graph
        int edgeCount; // Number of edges in the graph
        bool isWeighted; // Weighted or unweighted graph

    public:
        Graph(); // Default constructor
        Graph(const std::vector<std::vector<int>>& matrix); // New constructor to accept adjacency matrix
          
        //delicaration of the functions 
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;
        int getnumvertices() const;
        int getedgecount() const;
        int getadjacencymatrix(std::size_t i, std::size_t j) const;
      
    };
}

#endif // GRAPH_H
