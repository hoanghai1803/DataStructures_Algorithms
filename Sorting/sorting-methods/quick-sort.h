#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>

/* ========== QUICK SORT IMPLEMENTATION ========== */

// Time complexity: O(NlogN) for best and average cases, O(N^2) for worst case.

// There are many different versions of Quick Sort that pick pivot in different ways:
// 1. Always pick first element as pivot
// 2. Always pick last element as pivot
// 3. Pick a random element as pivot
// 4. Pick median as pivot

// The worst case of Quick Sort occurs when the partition process always picks greatest or 
// smallest element as pivot. The below implementation uses the third way (pick a random 
// element as pivot).

void runQuickSort(std::vector<long long>& arr, int low, int high) {
    // Base case
    if (low >= high) return;

    // Get random pivot in range [low, high] and swap it with number at low
    int key = rand() % (high - low + 1) + low;
    std::swap(arr[low], arr[key]);

    // Partition
    long long pivot = arr[low];
    int i = low;
    for (int j = low + 1; j <= high; j++)
        if (arr[j] <= pivot) std::swap(arr[++i], arr[j]);

    // Swap pivot (at low) with i, after doing this, all number before pivot (at i)
    // are smaller than pivot, and all numbers after pivot are bigger than pivot.
    std::swap(arr[low], arr[i]);

    // Run Quick Sort for two halves (not include pivot)
    runQuickSort(arr, low, i - 1);
    runQuickSort(arr, i + 1, high);
}

void quickSort(std::vector<long long>& arr, int n) {	
    // Initialize random seed 
    srand(time(NULL));

    runQuickSort(arr, 0, n - 1);
}
