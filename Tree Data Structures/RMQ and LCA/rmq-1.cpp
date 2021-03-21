/* ========== RANGE MINIMUM QUERY PROBLEM (RMQ) ========== */
 
// Problem: Given an array arr[1..n]. Answer q queries. Each query is pair of indices 
// (L, R) (1 <= L <= R <= n), find the minimum value in range [L, R] in the given arr.

// The bellow solution uses Square Root Decomposition
// Time complexity:
// Pre-computing: O(N).
// Query: O(SQRT(N)).

#include <iostream>
#include <math.h>

#define N 100005

int n, q; // Size of array and number of queries

// Driver code
int main() {
    // Input data
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) 
        std::cin >> arr[i];

    preProcess();
}
