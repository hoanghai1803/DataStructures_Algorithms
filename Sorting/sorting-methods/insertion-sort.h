#include <vector>

/* ========== INSERTION SORT IMPLEMENTATION ========== */

// Time complexity: O(N^2).

void insertionSort(std::vector<long long>& arr, int n) {
	for (int i = 1; i < n; i++) {
		long long key = arr[i];
		int j = i;
		for (; j && arr[j - 1] > key; j--) arr[j] = arr[j - 1];
		arr[j] = key;
	}
}
