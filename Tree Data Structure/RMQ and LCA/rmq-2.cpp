/* ========== RANGE MINIMUM QUERY PROBLEM (RMQ) ========== */

// Problem: Given an array arr[1..n]. Answer q queries. Each query is pair of indices 
// (L, R) (1 <= L <= R <= n), find the minimum value in range [L, R] in the given arr.

// The bellow solution uses Sparse Table.
// Time complexity: 
// Pre-computing: O(Nlog_2(N)). 
// Query: O(1).

#include <iostream>
#include <math.h>

#define N 100005
#define LOG 22

int n, q; // Size of array and number of queries
int arr[N];
int M[N][LOG];

void preProcess() {
    for (int i = 1; i <= n; i++) M[i][0] = arr[i];
    
    for (int j = 1; (1 << j) <= n; j++) 
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            M[i][j] = std::min(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);
}

int RMQ(int L, int R) {
    int j = log2(R - L + 1);
    return std::min(M[L][j], M[R - (1 << j) + 1][j]);
}

// Drive code
int main() {
    // Input data
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) 
        std::cin >> arr[i];

    preProcess();

    // Queries
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << RMQ(l, r) << "\n"; 
    }  
}
