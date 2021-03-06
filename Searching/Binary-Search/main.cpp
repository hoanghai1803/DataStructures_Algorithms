#include <iostream>
#include <algorithm>

// Include binary search methods
#include "binary-search-1.h"
#include "binary-search-2.h"

int main() {
    std::cout << "*** BINARY SEARCH IMPLEMENTATION***\n";
    std::cout << "===================================\n";
    
    // Input data
    int n;
    std::cout << "Enter length of array n (n <= 10^6): ";
    std::cin >> n;

    std::vector<long long> arr(n);
    std::cout << "Enter n element of the array:\n";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    // Check if the array is sorted or not. If not, sort the array
    long long sign = arr[1] - arr[0];
    for (int i = 2; i < n; i++) {
        if (sign * (arr[i] - arr[i - 1]) < 0) {
            std::sort(arr.begin(), arr.end());
            std::cout << "Because your input data is not sorted yet, we do it for you. The array after sorting:\n";
            for (long long value: arr) std::cout << value << " ";
            std::cout << "\n";
            break;
        } 
        sign = arr[i] - arr[i - 1];
    }

    // Searching
    std::cout << "Enter the value you want to search: "; 
    long long value;
    std::cin >> value;
    int res_1 = BinarySearch_1(arr, 0, n - 1, value);
    int res_2 = BinarySearch_2(arr, 0, n - 1, value);

    // Compare results of 2 implementations of BS
    if (res_1 != res_2) {
        std::cout << "Oops, wrong answer! Something went wrong with these implementations of Binary Search:\n";
        return 0;
    }
    
    // Print out result
    std::cout << "Index of the first occurrent of " << value << " is: " << res_1 << "\n";
    std::cout << "(The array indices is counted from 0)\n";
}
