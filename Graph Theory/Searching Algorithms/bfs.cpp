/* ========== BREADTH FIRST SEARCH IMPLEMENTATION ========== */

// This implementation of BFS calculates the distance from the given
// source vertex to all vertices in undirected graph. If cannot reach 
// to the vertex v from src vertex, then dist[v] = -1.

// Time complexity: O(V + E).

#include <iostream>
#include <vector>
#include <queue>

#define N 100005

int n, m; // Number of vertices and edges
int src; // Given source
std::vector<int> adj[N]; // Adjacency list
int dist[N]; // Distances from the given src to all vertices

void bfs() {
    std::queue<int> Q;
    Q.push(src);

    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (int v: adj[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            Q.push(v);
        }
    }
}

int main() {
    std::cin >> n >> m;

    while (m--) {
        int u, v;
        std::cin >> u >> v;

        // Push u into adj[v] and v into adj[u]
        // If the graph is directed, only push v into adj[u]
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize distance from src -> all vertices 
    for (int u = 1; u <= n; u++) dist[u] = -1;
    std::cin >> src;    
    dist[src] = 0;
    
    bfs();
    for (int u = 1; u <= n; u++)
        std::cout << "dist[" << u << "] = " << dist[u] << "\n";
}
