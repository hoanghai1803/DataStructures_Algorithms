#include <vector>

/* ========== MERGE SORT IMPLEMENTATION ========== */

// Time complexity: O(NlogN) in all 3 cases (worst, average and best).

void runMergeSort(std::vector<long long>& arr, int L, int R) {
    // Base case
	if (L >= R) return;
	
	// Merge sort two halves
	int M = (L + R) >> 1;
	runMergeSort(arr, L, M);
	runMergeSort(arr, M + 1, R);

	// Merge the two halves (are sorted above)
	std::vector<long long> mergeArr;
	int i = L, j = M + 1;
	for (; i <= M; i++) { 
		while (j <= R && arr[j] < arr[i]) 
			mergeArr.push_back(arr[j++]);
		mergeArr.push_back(arr[i]);
	}
	while (j <= R) mergeArr.push_back(arr[j++]);

	// Copy the mergeArr[] to arr[]
	for (int i = 0; i <= R - L; i++)
		arr[i + L] = mergeArr[i];
}

void mergeSort(std::vector<long long>& arr, int n) {
	runMergeSort(arr, 0, n - 1);
}
