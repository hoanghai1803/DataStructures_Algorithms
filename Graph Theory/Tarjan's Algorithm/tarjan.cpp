/*  TARJAN'S ALGORITHM IMPLEMENTATION FOR DETECTING STRONGLY CONNECTED COMPONENTS */

// This implementation of Tarjan's algorithm to count number of Strongly
// Connected Components in a directed graph.

// Time complexity: O(V + E).

#include <iostream>
#include <vector>
#include <stack>

#define N 100005

int n, m; // Number of vertices and edges
std::vector<int> adj[N]; // Adjacency list
std::stack<int> Stack; // Stack to store the vertices after visiting, then remove them when SCC is found
int dfn[N]; // The order of the vertex
int low[N]; // low[u] - the minimum dfn[v], where v is all vertices can visit when start traversal from vertex u 
int Remove[N]; // To mark whether the vertex has been removed
int scc; // Number of Strongly Connected Components
int num; // Counting the order of the vertices 

void dfs(int u) {
    Stack.push(u);
    dfn[u] = low[u] = ++num;
    
    for (int v: adj[u]) {
        if (Remove[v]) continue;
        if (dfn[v]) {
            low[u] = std::min(low[u], dfn[v]);
            continue;
        }
        dfs(v);
        low[u] = std::min(low[u], low[v]);
    }

    // If this condition is satisfied, we have found
    // a strongly connected component
    if (low[u] == dfn[u]) {
        scc++;
        // Removing all vertices of this SCC from the Stack
        while (1) {
            int v = Stack.top(); 
            Stack.pop();
            Remove[v] = true; 
            if (u == v) break;
        } 
    }
}

// Driver code
int main() {
    std::cin >> n >> m;
    
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }
    
    for (int u = 1; u <= n; u++)
        if (!dfn[u]) dfs(u);

    std::cout << scc << "\n";
}
