#include <vector>

/* ========== LINEAR SEARCH IMPLEMENTATION ========== */

// The below implementation of linear search will search and 
// return the index of the first occurrence of the given target
// in range [L, R].
// If the given target does not exist in array, return -1.
// Time complexity: O(n).

template<class T>
    int linearSearch(std::vector<T> arr, int L, int R, T target) {
        for (int i = L; i <= R; i++)
            if (arr[i] == target) return i;
        return -1;
    }
