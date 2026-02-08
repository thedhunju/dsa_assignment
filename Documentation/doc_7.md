7. Given a weighted graph, implement Dijkstra’s algorithm to find the shortest path from a source node to all other nodes.


ANSWER:


The program uses arrays to represent a weighted graph and track the shortest path calculations:
Graph Representation

int g[N][N]: A 2D array representing the adjacency matrix of the weighted graph. The value at g[i][j] represents the weight of the edge between vertex i and vertex j. A value of 0 means there is no direct edge between those vertices.

Algorithm Arrays

int d[N]: This array stores the shortest distance from the source vertex to each vertex. It is initialized to INF (infinity) for all vertices except the source.
int v[N]: A visited array that keeps track of which vertices have been processed. A value of 1 means the vertex has been visited, 0 means it hasn't.
int p[N]: The parent array that stores the previous vertex in the shortest path. This is used to reconstruct the complete path from source to any vertex.

Constants

N: The number of vertices in the graph (set to 6).
INF: Represents infinity (set to 9999), used as an initial value for distances.

Functions Implemented
1. int getMin(int d[], int v[], int s)
This function finds the unvisited vertex with the minimum distance value. It loops through all vertices, checking which ones haven't been visited yet, and returns the index of the vertex with the smallest distance. This vertex will be processed next in Dijkstra's algorithm.
2. void path(int p[], int j)
This is a recursive function that prints the shortest path from the source to vertex j. It traces back through the parent array until it reaches the source vertex (which has parent -1), then prints the vertices in order as the recursion unwinds.
3. void solve(int g[N][N], int src)
This is the main function that implements Dijkstra's algorithm. It initializes all distances to infinity and the source distance to 0. Then it repeatedly selects the unvisited vertex with minimum distance, marks it as visited, and updates the distances of its neighbors if a shorter path is found. After processing all vertices, it prints the results showing the shortest distance and path to each vertex.
Main Method Organization
The main function sets up the graph and runs Dijkstra's algorithm:

1. A weighted graph is defined using a 6x6 adjacency matrix. The edges are represented with their weights, and 0 indicates no direct connection between vertices.
2. The solve() function is called with the graph and starting vertex 0 as parameters.
3. Inside solve(), Dijkstra's algorithm calculates the shortest paths from vertex 0 to all other vertices.
4. The results are displayed in a table format showing each vertex, its shortest distance from the source, and the complete path to reach it.
5. The program ends by returning 0.
**Input/Output**

![alt text](../Output/OUTPUT7.png)

