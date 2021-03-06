#include <vector>

// The below implementations of Binary Search will search and 
// return the index of the first occurrence of the given target
// in range [L, R].
// If the given target does not exist in array, return -1.
// The input data must be sorted.
// Time complexity: O(logN).

/* ======= RECURSIVE BINARY SEARCH IMPLEMENTATION ======= */

template<class T>
    int recursiveBinarySearch(std::vector<T> arr, int L, int R, T target) {
        if (L + 1 >= R) {
            for (int M = L; M <= R; M++) 
                if (arr[M] == target) return M;
            return -1;
        }

        int M = (L + R) >> 1;
        return (arr[M] >= target) ? recursiveBinarySearch(arr, L, M, target) : recursiveBinarySearch(arr, M, R, target);
    }

/* ======= ITERATIVE BINARY SEARCH IMPLEMENTATION ======= */

template<class T>
    int iterativeBinarySearch(std::vector<T> arr, int L, int R, T target) {
        while (1) {
            if (L + 1 >= R) {
                for (int M = L; M <= R; M++)
                    if (arr[M] == target) return M;
                    return -1;
            }
        
            int M = (L + R) >> 1;
            if (arr[M] >= target) R = M; else L = M;
        }
    }
