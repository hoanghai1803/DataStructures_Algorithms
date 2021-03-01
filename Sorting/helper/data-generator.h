#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>

#define ASCENDING_DATA 1
#define DESCENDING_DATA 2
#define ALMOST_SORTED_DATA 3

/* ========== DATA GENERATOR METHODS ========= */

void generateAscendingData(std::vector<long long>& arr, int n) {
    for (int i = 0; i < n; i++) arr[i] = i;
}

void generateDescendingData(std::vector<long long>& arr, int n) {
    for (int i = 0; i < n; i++) arr[i] = n - i;
}

void generateAlmostSortedData(std::vector<long long>& arr, int n) {
    for (int i = 0; i < n; i++) arr[i] = i;
    int shuffle = rand() % std::min(n, 100);
    while (shuffle--) {
        int idx_1 = rand() % n;
        int idx_2 = rand() % n;
        std::swap(arr[idx_1], arr[idx_2]); 
    }
}

void generateRandomData(std::vector<long long>& arr, int n) {
    const int RANGE = 1e6;
    for (int i = 0; i < n; i++) 
        arr[i] = rand() % (2 * RANGE + 1) - RANGE;
}

// Main function
void generateData(std::vector<long long>& arr, int n, int type) {
    // Initialize random seed
    srand(time(NULL));

    // Generate sorted data
    if (type == ASCENDING_DATA) {
        generateAscendingData(arr, n);
        return;
    }

    if (type == DESCENDING_DATA) {
        generateDescendingData(arr, n);
        return;
    }

    if (type == ALMOST_SORTED_DATA) {
        generateAlmostSortedData(arr, n);
        return;
    }

    // Generate random data
    generateRandomData(arr, n);
}
