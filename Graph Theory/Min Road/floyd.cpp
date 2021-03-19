/* ========== FLOYD ALGORITHM IMPLEMENTATION ========== */

// This implementation of Floyd algorithm calculates the minimum distance 
// between every pair of vertices in a weighted undirected multigraph. If
// cannot reach from vertex u to vertex v, then dist[u][v] = -1.

// Time complexity: O(V^3).

#include <iostream>

#define N 502
const int INF = 1e9;

int n, m; // The number of vertices and edges
int dist[N][N]; // Minimum distance between every pair of vertices

// Driver code
int main() {
    // Initialization 
    std::cin >> n >> m;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            if (u != v) dist[u][v] = +INF;

    while (m--) {
        int u, v, d;
        std::cin >> u >> v >> d;
        dist[u][v] = std::min(dist[u][v], d);
        dist[v][u] = dist[u][v]; // Remove this line if the graph is directed
    }

    // Floyd algorithm
    for (int k = 1; k <= n; k++)
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
                dist[u][v] = std::min(dist[u][v], dist[u][k] + dist[k][v]);

    // Print out result
    for (int u = 1; u <= n; u++) {
        std::cout << "The distances from vertex " << u << " to all vertices:\n";
        for (int v = 1; v <= n; v++) std::cout << (dist[u][v] != INF ? dist[u][v] : -1) << " ";
        std::cout << "\n";
    }
}
