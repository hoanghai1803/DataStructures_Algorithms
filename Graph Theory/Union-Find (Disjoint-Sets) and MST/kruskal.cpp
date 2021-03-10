/* ========== KRUSKAL ALGORITHM IMPLEMENTATION ========== */

#include <iostream>
#include <algorithm>
#include <vector>

#define N 10004

#define src second.first
#define dest second.second
#define weight first

typedef std::pair<int, std::pair<int, int>> Edge;

int n, m; // Number of vertices and edges
std::vector<Edge> edges; // Edge list
int par[N]; // par[u] - parent vertex of vertex u
int minCost; // Minimum weight spanning tree

int findRoot(int u) {
    return par[u] < 0 ? u : (par[u] = findRoot(par[u]));
}

void Union(int u, int v, int w) {
    if (par[v] < par[u]) std::swap(u, v);
    par[u] += par[v];
    par[v] = u;
    minCost += w;
}

void Kruskal() {
    for (Edge e: edges) {
        int u = e.src, v = e.dest;
        int w = e.weight;
        if ((u = findRoot(u)) == (v = findRoot(v))) continue;
        Union(u, v, w);
    }
}

// Driver code
int main() {
    std::cin >> n >> m;

    while (m--) {
        int u, v, w;
        std::cin >> u >> v >> w;

        Edge e;
        e.src = u, e.dest = v, e.weight = w;
        edges.push_back(e);
    }

    for (int u = 1; u <= n; u++) par[u] = -1;
    std::sort(edges.begin(), edges.end());
    
    Kruskal();
    std::cout << minCost << "\n";
}
