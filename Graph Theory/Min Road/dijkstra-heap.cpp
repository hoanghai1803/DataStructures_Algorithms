/* ========== DIJKSTRA HEAP ALGORITHM IMPLEMENTATION ========== */

// This implementation of Dijkstra algorithm caculates the minimum distance 
// from the given source vertex to all vertices in a weighted undirected graph 
// with non-negative edge weights. If cannot reach to vertex
// v from src vertex, then dist[v] = -1.

// Time complexity: 
// Dijkstra: O(V^2)
// Dijkstra + Heap: O(max(V, E)log_2(V)) - Implemented bellow

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define INF INT_MAX
#define N 100005

typedef std::pair<int, int> ii;

int n, m; // The number of vertices and edges
int src; // The given source vertex
long long F[N]; // Minimum distance from src vertex -> all vertices
std::vector<ii> adj[N]; // Adjacency list
std::priority_queue<ii, std::vector<ii>, std::greater<ii> > Heap; // Min Heap

void Dijkstra(int s) {
    Heap.push(ii(F[s], s));
    while (Heap.size()) {
        int Fu = Heap.top().first, u = Heap.top().second;
        Heap.pop();
        if (Fu != F[u]) continue;
        int v; 
        for (ii edge: adj[u]) 
            if (F[v = edge.first] > F[u] + edge.second) {
                F[v] = F[u] + edge.second;
                Heap.push(ii(F[v], v));
            }
    }
}

// Driver code
int main() {
    std::cin >> n >> m;

    while (m--) {
        int u, v, w;
        std::cin >> u >> v >> w;
        
        // Push (u,w) into adj[v] and (v, w) into adj[u]
        // If the graph is directed, only push (v, w) into adj[u]
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }

    // Initialize distance from src -> all vertices
    for (int u = 1; u <= n; u++) F[u] = +INF;
    std::cin >> src;
    F[src] = 0;

    Dijkstra(src);
    for (int u = 1; u <= n; u++) 
        std::cout << "dist[" << u << "] = " << (F[u] != INF ? F[u] : -1) << "\n";
}
