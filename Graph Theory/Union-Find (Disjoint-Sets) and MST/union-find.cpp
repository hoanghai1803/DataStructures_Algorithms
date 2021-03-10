/* ========== UNION-FIND (DISJOINT-SETS) IMPLEMENTATION ========== */

// This implementation of disjoint set uses for detecting cycle in an undirected graph.
// We assume that the graph doesn't contain any self-loops.

#include <iostream>
#include <vector>

#define N 100005

int n, m; // Number of vertices and edges
int par[N]; // par[u] - parent vertex of u

int findRoot(int u) {
    return par[u] == u ? u : (par[u] = findRoot(par[u]));
}

void Union(int u, int v) {
    if ((u = findRoot(u)) == (v = findRoot(v))) return;
    par[u] = v;
}

// Driver code
int main() {
    std::cin >> n >> m;
    for (int u = 1; u <= n; u++) par[u] = u;
    
    while (m--) {
        int u, v;
        std::cin >> u >> v;

        if ((u = findRoot(u)) == (v = findRoot(v))) {
            std::cout << "The graph contains cycle\n";
            return 0;
        }

        Union(u, v);
    }

    std::cout << "The graph doesn't contain any cycles\n";
}
