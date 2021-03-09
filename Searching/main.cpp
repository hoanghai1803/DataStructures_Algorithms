#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Include all searching methods
#include "searching-methods/all.h"

// Store all searching methods into searchingMethods[]
typedef int (*func)(std::vector<long long>, int, int, long long);
func searchingMethods[] = {
    linearSearch, recursiveBinarySearch, 
    iterativeBinarySearch, ternarySearch
};

// List of searching algorithms are implemented => For message to user
std::vector<std::string> searchingNames = {
    "Linear Search", "Recursive Binary Search",
    "Iterative Binary Search", "Ternary Search"
};

int main() {
    std::cout << "*** SEARCHING IMPLEMENTATIONS ***\n";
    std::cout << "===================================\n";
    
    // Input data
    int n;
    std::cout << "Enter length of array n (0 < n <= 10^6): ";
    std::cin >> n;
    if (n <= 0 || n > 1e6) return 0;

    std::vector<long long> arr(n);
    std::cout << "Enter n element of the array (the array indices is counted from 0):\n";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    // Check if the array is sorted or not. If not, sort the array
    long long sign = arr[1] - arr[0];
    for (int i = 2; i < n; i++) {
        if (sign * (arr[i] - arr[i - 1]) < 0) {
            std::sort(arr.begin(), arr.end());
            std::cout << "Because your input data is not sorted yet, we do it for you. The array after sorting:\n";
            for (long long num: arr) std::cout << num << " ";
            std::cout << "\n";
            break;
        } 
        sign = arr[i] - arr[i - 1];
    }

    // Searching
    while (1) {
        std::cout << "\n          *  *  *\n\n";

        // Chose target
        std::cout << "Enter the target you want to search: "; 
        long long target;
        std::cin >> target;

        // Chose method
        std::cout << "Enter the method you want to use:\n";
        std::cout << "0. Linear Search\n";
        std::cout << "1. Recursive Binary Search\n";
        std::cout << "2. Iterative Binary Search\n";
        std::cout << "3. Ternary Search\n";
        std::cout << "Type 0-3 to select method or another to exit: ";

        int id;
        std::cin >> id;
        if (id < 0 || id > 3) break;
        long long res = searchingMethods[id](arr, 0, n - 1, target);

        // Print out result
        std::cout << "Index of the first occurrence of " << target << " is: " << res << "\n";

        std::cout << "Do you want to continue search in this array?\nType \"y\" to continue or another to quit: ";
        std::string key;
        std::cin >> key;
        if (key != "y") break;
    }
}
