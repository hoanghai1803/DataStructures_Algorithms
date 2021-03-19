/* ========== DIRECTED ACYCLIC GRAPH - BUILD AND DP ========== */

// Problem: Given a directed graph with score on each vertex. Traversal from
// any vertex, visit all possible vertices so that the sum of score is as maximum 
// as possible. Note that the score of each vertex is only counted the first time
// visit it.

// Solution: using Tarjan's algorithm to create the Directed Acyclic Graph (DAG) from a directed graph then dp on it.

// Time complexity for Tarjan's algorithm: O(V + E).
// Time complexity for insert all edges to vertex on DAG: O(E * log_2(V)). (Using set data structure in STL)
// Time complexity for DP on DAG: O(_E + _V), where _V and _E are the number of vertices and edges of DAG, respectively.

#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>

#define N 100005

/* The base graph */
int n, m; // The number of vertices and edges
int score[N]; // The score of the vertex
std::vector<int> adj[N]; // Adjacency list
std::stack<int> Stack; // Stack to store the vertices, then remove them when SCC is found
int dfn[N]; // The order of the vertex
int low[N]; // low[u] - the minimun dfn[v], where v is all vertices that can be visited when start traversal from u
int Remove[N]; // To mark whether the vertex has been removed
int num; // Counting the order of the vertices 

/* The new graph - DAG */
int nscc; // Number of Strongly Connected Components, or also the number of vertices in DAG
int score_dag[N]; // The store of the DAG
std::set<int> adj_dag[N]; // The adjacency list for DAG
int SCC[N]; // SCC[u], where u is the vertex in base graph, this is the SCC that u belong to.
int inDeg[N]; // The in-degree of vertex in new graph
int dp[N]; // Array for dynamic programming on DAG

// Tarjan's Algorithm for building a DAG
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

    // If this condition is satisfied, we have found a new
    // strongly connected component
    if (low[u] == dfn[u]) {
        nscc++;
        // Removing all vertices of this SCC from the Stack
        while (1) {
            int v = Stack.top(); 
            Stack.pop();
            SCC[v] = nscc;
            score_dag[nscc] += score[v], Remove[v] = true; 
            if (u == v) break;
         }
    }
}

// Build edges for DAG from edges in the base graph
void buildDAG() {
    for (int u = 1; u <= n; u++)
        for (int v: adj[u]) {
            if (SCC[u] == SCC[v]) continue;
            adj_dag[SCC[u]].insert(SCC[v]);   
        }

    for (int u = 1; u <= nscc; u++)
        for (int v: adj_dag[u]) inDeg[v]++;
}

void DP() {
    std::queue<int> Q;
    for (int u = 1; u <= nscc; u++)
        if (!inDeg[u]) Q.push(u), dp[u] = score_dag[u];
     
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (int v: adj_dag[u]) {
            dp[v] = std::max(dp[v], dp[u] + score_dag[v]);
            if (!--inDeg[v]) Q.push(v);
        }
    }
}

// Driver code
int main() {
    std::cin >> n >> m;
    for (int u = 1; u <= n; u++) std::cin >> score[u];
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int u = 1; u <= n; u++)
        if (!dfn[u]) dfs(u);

    buildDAG();
    DP();

    int res = 0;
    for (int u = 1; u <= nscc; u++) res = std::max(res, dp[u]);
    std::cout << res << "\n";
}
