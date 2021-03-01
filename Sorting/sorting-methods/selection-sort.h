#include <vector>

/* ========== SELECTION SORT IMPLEMENTATION ========== */

// Time complexity: O(N^2).

void selectionSort(std::vector<long long>& arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j]) std::swap(arr[i], arr[j]);
}
