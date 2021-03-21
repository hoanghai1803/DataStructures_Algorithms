/* ========== BRIDGES AND ARTICULATION POINTS DETECTION ========== */

// Tarjan's algorithm to count Bridges and Articulation Points in an undirected graph.

// Time complexity: O(V + E).

#include <iostream>
#include <vector>

#define N 100005

int n, m; // Number of vertices and edges
std::vector<int> adj[N]; // Adjacency list
int num; // Counting the order of vertices
int dfn[N]; // The order of vertex
int low[N]; // low[u] - the minimum dfn[v], where v is all vertices that can be visited when start traversal from vertex u
int Bridges, AP; // Bridges and Articulation Points

void dfs(int u, int par) {
    int children = 0;
    dfn[u] = low[u] = ++num; 

    for (int v: adj[u]) {
        if (v == par) continue;
        if (dfn[v]) {
            low[u] = std::min(low[u], dfn[v]);
            continue;
        } 

        dfs(v, u);
        low[u] = std::min(low[u], low[v]);
        children += (low[v] >= dfn[u]);
    }

    Bridges += (low[u] == dfn[u] && par);
    AP += par ? (children >= 1) : (children >= 2);
}

// Driver code
int main() {
    std::cin >> n >> m;
    
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 1; u <= n; u++)
        if (!dfn[u]) dfs(u, 0);

    std::cout << Bridges << " " << AP << "\n";
}
