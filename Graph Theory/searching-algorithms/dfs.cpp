/* ========== DEPTH FIRST SEARCH IMPLEMENTATION ========== */

// This implementation of DFS calculates number of connected components 
// in an undirected graph.
// Time complexity: O(N + M).

#include <iostream>
#include <vector>

#define N 100005

int n, m; // Number of vertices and edges
std::vector<int> adj[N]; // Adjacency list
bool visited[N]; // Array to mark if the vertex is visited or not
int ncc; // Number of connected component

void dfs(int u) {
    visited[u] = true;
    for (int v: adj[u])
        if (!visited[v]) dfs(v);
}

int main() {
    std::cin >> n >> m;

    while (m--) {
        int u, v;
        std::cin >> u >> v;

        // Push u into adj[v] and v into adj[u].
        // If the graph is directed, only push v into adj[u]
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int u = 1; u <= n; u++)
        if (!visited[u]) {
            std::cout << u << "\n";
            ncc++;
            dfs(u);
        }

    std::cout << ncc << "\n";
}
