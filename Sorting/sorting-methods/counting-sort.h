#include <vector>

/* ========== COUNTING SORT IMPLEMENTATION ========== */

// Time complexity: O(N + K), where N is the number of elements in 
// input array and K is the range of input.

void countingSort(std::vector<long long>& arr, int n) {
    const long long RANGE = 1e7;
    
    // This is for negative numbers
    for (int i = 0; i < n; i++) arr[i] += RANGE;

    std::vector<int> count(2 * RANGE + 1, 0);
    for (long long num: arr) count[num]++;
    
    std::vector<long long> output;
    for (long long num = 0; num <= 2 * RANGE; num++)
        while (count[num]--) output.push_back(num - RANGE);

    for (int i = 0; i < n; i++) arr[i] = output[i];
}
