#include <vector>

/* ======= BINARY SEARCH IMPLEMENTS BY RECURSION ======= */

// The below implementation of binary search using recursion.
// It searches and returns the index of the first occurrence of the given value.
// If the given value does not exist in array, returns -1.
// The input data must be sorted.
// Time complexity: O(NlogN).

template<class T>
    int BinarySearch_1(std::vector<T> arr, int L, int R, T value) {
        if (L + 1 >= R) {
            for (int M = L; M <= R; M++) 
                if (arr[M] == value) return M;
            return -1;
        }

        int M = (L + R) >> 1;
        if (arr[M] >= value) return BinarySearch_1(arr, L, M, value);
        return BinarySearch_1(arr, M, R, value);
    }
