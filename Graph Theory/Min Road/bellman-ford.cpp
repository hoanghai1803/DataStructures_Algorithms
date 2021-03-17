/* ========== BELLMAN-FORD ALGORITHM IMPLEMENTATION ========== */

// This implementation of Bellman-Ford algorithm calculates the minimum distance
// from the given source vertex to all vertices in a weighted undirected graph
// with non-negative weight cycles (may contain negative weight edges).
// If there is a negative cycle in the graph, report: "Graph contains negative
// weight cycle". 

// Time complexity: 
// Using adjacency matrix: O(V^3)
// Using edge list: O(V * E) - Implemented bellow

#include <iostream>
#include <climits>
#include <vector>

#define INF INT_MAX
#define N 2555

int n, m; // Number of vertices and edges
int src; // The given source vertex
int dist[N]; // Distances from src to all vertex

struct Edge {
    int u, v;
    int w;
};

std::vector<Edge> edges;

void BellmanFord(int s) {
    // Initialization
    for (int u = 1; u <= n; u++) dist[u] = +INF;
    dist[s] = 0;

    // Calculate dist[]
    for (int i = 1; i < n; i++) 
        for (Edge e: edges) 
            if (dist[e.u] != +INF && dist[e.u] + e.w < dist[e.v]) 
                dist[e.v] = dist[e.u] + e.w;

    // Check for negative weight cycles. 
    for (Edge e: edges) 
        if (dist[e.u] != +INF && dist[e.u] + e.w < dist[e.v]) {
            std::cout << "Graph contains negative weight cycle\n";
            return;
        }

    // Print out result
    for (int u = 1; u <= n; u++) 
        if (dist[u] == INF) 
            std::cout << "Cannot reach from source vertex to vertex " << u << "\n";
        else
            std::cout << "dist[" << u << "] = " << dist[u] << "\n";
}

// Driver code
int main() {
    std::cin >> n >> m;
    
    while (m--) {
        int u, v, w;
        std::cin >> u >> v >> w;

        Edge e = {u, v, w};
        edges.push_back(e);
        
        // If the graph is undirected, also push edge (v, e) with weight w 
        // to the edge list
        Edge _e = {v, u, w};
        edges.push_back(_e);
    }

    std::cin >> src;

    BellmanFord(src);
}
