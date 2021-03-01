#include <vector>

/* ========== BUBBLE SORT IMPLEMENTATION ========== */

// Time complexity: O(N^2) in all 3 cases (worst, average and best).
// If we use optimized version of Buble Sort (Ref: https://www.geeksforgeeks.org/bubble-sort/),
// the best case will take time complexity O(N), occurs when array is already sorted.

void bubbleSort(std::vector<long long>& arr, int n) {
	for (int step = 1; step < n; step++)
		for (int i = 0; i < n - step; i++)
			if (arr[i] > arr[i + 1]) std::swap(arr[i], arr[i + 1]);
}
