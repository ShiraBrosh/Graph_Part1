# Graph Algorithms Implementation

This C++ implementation provides various algorithms for working with graphs, including depth-first search (DFS), Bellman-Ford algorithm, cycle detection, and bipartite graph checking.

## Assumptions

- All edges are considered directed because the provided adjacency matrix does not distinguish between undirected edges with weight -k and two directed edges with weights -k in opposite directions. Undirected edges can be treated as a special case of directed edges.
- The weight of 0 represents the absence of an edge between two vertices (typically represented by infinity in other implementations).

## Installation

1. Clone the repository or download the source code.
2. Ensure you have a C++ compiler installed (e.g., GCC or Clang).
3. Compile the source files using your preferred compiler and linker.

## Usage

1. Create an instance of the `Graph` class, either with an empty constructor or by providing an adjacency matrix.
2. Use the various methods provided by the `Algorithms` class to perform graph operations, such as checking connectivity, finding shortest paths, detecting cycles, and checking for bipartite graphs.

Example usage:

cpp
#include "Graph.hpp"
#include "Algorithms.hpp"

int main() {
    // Create a graph from an adjacency matrix
    std::vector<std::vector<int>> matrix = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    ariel::Graph graph(matrix);
    // Check if the graph is connected  
    bool isConnected = ariel::Algorithms::isConnected(graph);
    std::cout << "Is the graph connected? " << std::boolalpha << isConnected << std::endl;

   // Find the shortest path between two vertices 
    std::size_t start = 0, end = 3;
    std::string shortestPath = ariel::Algorithms::shortestPath(graph, start, end);
    std::cout << "Shortest path from " << start << " to " << end << ": " << shortestPath << std::endl;

  return 0;
}


## Method Implementations

1. **Bellman-Ford Algorithm:** This method serves three purposes:
   - Updating a list containing the shortest distance from the source vertex to each other vertex.
   - Maintaining a list that stores the previous vertex on the shortest path from a given vertex to the source vertex.
   - Detecting the presence of negative cycles in the graph, which is essential for the `shortestPath` and `hasNegativeCycle` methods.

2. **isConnected:** To determine if a graph is strongly connected, the implementation follows Kosaraju's algorithm. It performs a depth-first search (DFS) from a vertex, transposes the adjacency matrix, and then performs another DFS from the same vertex. If all vertices are visited in both iterations, the graph is strongly connected.

3. **shortestPath:** This method utilizes the Bellman-Ford algorithm to find the shortest path between two vertices. It first checks for the presence of negative cycles along the path. If no negative cycles exist, it traces back the route from the destination vertex to the source vertex using the previous vertex list. If no such path exists or negative cycles are encountered, it returns "-1"; otherwise, it returns the path as a string.

4. **isContainsCycle:** To detect if the graph contains a cycle, the algorithm assigns three colors (white, gray, and black) represented by 0, 1, and 2, respectively. It performs a DFS traversal on the graph and checks for back edges (when a vertex encounters a gray vertex during the iteration). If a back edge is found, it indicates the presence of a cycle, and the method returns the cycle path by retrieving the nodes from a stack.

5. **isBipartite:** The algorithm converts the graph to an undirected graph for easier handling (this does not affect the final result). It then performs a DFS traversal and colors each node with one of two colors. The current node is assigned one color, and all its neighbors are colored with the opposite color. If a neighbor is encountered with the same color as the current node, the graph cannot be bipartite. Otherwise, the two groups of colors represent the bipartite sets.

6. **hasNegativeCycle:** This method uses the Bellman-Ford algorithm to detect the presence of negative cycles. It adds an extra vertex at the beginning with edges of weight 1 pointing to all other vertices (by modifying the adjacency matrix accordingly). If a negative cycle exists after running Bellman-Ford, the algorithm performs an additional relaxation step and identifies the vertex whose distance increases during this step. It then traces back the vertices using the previous vertex list to find the cycle path until it returns to the same vertex, at which point it returns the result. If no negative cycles are found, it returns "no negative cycle."

## Code Structure

- `Graph.hpp`: Declaration of the `Graph` class, which represents a graph using an adjacency matrix.
- `Graph.cpp`: Implementation of the `Graph` class methods.
- `Algorithms.hpp`: Declaration of the `Algorithms` class, which provides various graph algorithms.
- `Algorithms.cpp`: Implementation of the graph algorithms in the `Algorithms` class.

## Additional Features

- A function in the main program is created to handle the printing of adjacency matrices, allowing users to create new matrices and call the function to print them.
- Additional test cases have been added to check the algorithms, including cases with self-edges.
- In the `Algorithms.hpp` file, a private constructor has been added to prevent the creation of objects from the `Algorithms` class.
- In the `Graph.hpp` file, an empty default constructor has been included because the matrix is initialized in the `loadGraph` function.

## Known Limitations

- The implementation assumes that all edges are directed. Undirected edges are treated as a special case of directed edges.
- The weight of 0 is used to represent the absence of an edge between two vertices, which may differ from other conventions.

