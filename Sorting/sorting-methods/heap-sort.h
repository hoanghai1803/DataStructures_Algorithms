#include <vector>

/* ========== HEAP SORT IMPLEMENTATION ========== */

// Time complexity: O(NlogN).

void heapify(std::vector<long long>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int L = 2 * i + 1, R = 2 * i + 2;
    
    // Case left child larger than root
    if (L < n && arr[L] > arr[largest]) 
        largest = L;

    // Case right child larger than root
    if (R < n && arr[R] > arr[largest])
        largest = R;

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<long long>& arr, int n) {
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to the end
        std::swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
