/* ========== PRIM'S ALGORITHM IMPLEMENTATION ========== */ 

// This implementation of prim's algorithm calculates the minimum 
// weight spanning tree of the weighted undirected graph with non-negative 
// edge weights. We assume that the graph is connected.

// Time complexity:
// Using adjacency matrix: O(V^2)
// Using adjacency list (+ binary heap): O(V * log_2(E))

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define INF INT_MAX
#define N 100005

typedef std::pair<int, int> Edge;

int n, m; // Number of vertices and edges
std::vector<Edge> adj[N]; // Adjacency List
int cost[N]; // cost[u] - cost of vertex u

void Prim() {
    // Initialize minCost = 0 (minimum cost of spanning tree).
    int minCost = 0;
    int u, v, costU;

    // Initialize cost of all vertices = +oo, except cost[1] = 0.
    for (int u = 2; u <= n; u++) cost[u] = +INF;
    cost[1] = 0;

    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge> > Heap; // Min Heap
    Heap.push(Edge(cost[1], 1)); // Push vertex 1 and its cost into Min Heap
    
    while (Heap.size()) {
        u = Heap.top().second, costU = Heap.top().first;
        Heap.pop();
       
        if (costU != cost[u]) continue;
        minCost += cost[u];
        cost[u] = 0;

        for (Edge e: adj[u]) {
            if (cost[v = e.first] > e.second) {
                cost[v] = e.second;
                Heap.push(Edge(cost[v], v));
            }
        }
    }

    std::cout << minCost << "\n";
}

// Driver code
int main() {
    std::cin >> n >> m;

    while (m--) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back(Edge(v, w));
        adj[v].push_back(Edge(u, w));
    }

    Prim();
}
