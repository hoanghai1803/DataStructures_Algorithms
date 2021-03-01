#include <vector>

/* ========== RADIX SORT IMPLEMENTATION ========== */

// Time complexity: O(d * (N + b)), where:
// b is the base for representing numbers
// d = log_b(max{ai}) (i = 1,2,...n) 

void countingSort(std::vector<long long>& arr, int n, long long exp) {
	std::vector<int> count(10, 0);
	for (long long num: arr) count[num / exp % 10]++;

	// Update count[] so that count[digit] now contains 
	// actual position of this digit in output[]
	for (int digit = 1; digit < 10; digit++) 
		count[digit] += count[digit - 1];

	std::vector<long long> output(n);
	for (int i = n - 1; i >= 0; i--) {
		output[count[arr[i] / exp % 10] - 1] = arr[i];
		count[arr[i] / exp % 10]--;
	}

	for (int i = 0; i < arr.size(); i++) arr[i] = output[i];
}

void radixSort(std::vector<long long>& arr, int n) {
	const long long RANGE = 1e18;

	// This is for negative numbers
	for (int i = 0; i < n; i++) arr[i] += RANGE;

	long long maxNum = arr[0];
	for (long long num: arr) maxNum = std::max(maxNum, num);

	for (long long exp = 1; maxNum / exp > 0; exp *= 10) 
		countingSort(arr, n, exp);

	// Reset array to original numbers after sorting
	for (int i = 0; i < n; i++) arr[i] -= RANGE;
}