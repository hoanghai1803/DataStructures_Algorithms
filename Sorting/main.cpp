#include <iostream>
#include <fstream>
#include <vector>

// Include sorting methods
#include "sorting-methods/all.h"

// Include helper methods
#include "helper/data-generator.h"
#include "helper/check-sorting-array.h"

// Store all sorting methods into sortingMethods[]
typedef void (*func)(std::vector<long long>&, int);
func sortingMethods[] = {
    bubbleSort, insertionSort, selectionSort,
    quickSort, mergeSort, heapSort,
    countingSort, radixSort
};

// List of sorting algorithms are implemented => For message to user
std::vector<std::string> sortingNames = {
    "Bubble Sort", "Insertion Sort", "Selection Sort",
    "Quick Sort", "Merge Sort", "Heap Sort",
    "Counting Sort", "Radix Sort"
};

// List of range of array length 
const int N1 = 1e4, N2 = 1e6, N3 = 1e7;
int rangeN[] = { N1, N1, N1, N2, N2, N2, N3, N2 };

// List of exp => For message to user
int expN[] = { 4, 4, 4, 6, 6, 6, 7, 6 };

// List of range of array data
const long long A1 = 1e18, A2 = 1e7;
long long rangeA[] = { A1, A1, A1, A1, A1, A1, A2, A2 };

// List of exp => For message to user
int expA[] = { 18, 18, 18, 18, 18, 18, 7, 18 };

// This function for checking if input length (from user) is in range or not 
void inputLength(int& n, long long range, int exp) {
    std::cout << "Enter length of array n (0 < n < 10^" << exp << "): ";
    std::cin >> n;
    if (n <= 0 || n > range) {
        std::cout << "Invalid length!\n";
        exit(0);
    }
}

// This function for checking if input array (from user) is in range or not
void inputArray(std::vector<long long>& arr, int n, long long range, int exp) {
    std::cout << "Enter n integer numbers (in range [-10^" << exp << ", 10^" << exp << "]):\n";

    bool valid = true;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        if (arr[i] < -range || arr[i] > range) valid = false;
    } 
    
    if (!valid) {
        std::cout << "There are invalid numbers in your array!\n";
        exit(0);
    }
}

#define MANUAL_TESTING "m"

// This function for testing sorting method
void testingSortingMethod(int id) {
    // Initialize random seed
    srand(time(NULL));

    std::cout << "Press \"m\" to test manually or another to test automatically generated data: ";
    std::string test_type;
    std::cin >> test_type;

    /* === GET LENGTH OF ARRAY ==== */
    int n;
    if (test_type == MANUAL_TESTING)
        inputLength(n, rangeN[id], expN[id]);
    else
        n = rand() % rangeN[id] + 1;

    /* ========= GET DATA ========= */
    int data_type;
    if (test_type != MANUAL_TESTING) {
        std::cout << "Choose type of data to generate:\n";
        std::cout << "1. Ascending Data\n";
        std::cout << "2. Descending Data\n";
        std::cout << "3. Almost Sorted Data\n";
        std::cout << "4. Random Data\n";
        std::cout << "Or press another number to exit\n";

        std::cin >> data_type;
        if (data_type < 1 || data_type > 4) exit(0);
    }

    std::vector<long long> arr(n);
    if (test_type == MANUAL_TESTING)
        inputArray(arr, n, rangeA[id], expA[id]);
    else 
        generateData(arr, n, data_type);

    /* ====== SORTING ======= */
    std::vector<long long> originalArr = arr;
    sortingMethods[id](arr, n);

    /* ===== PRINT RESULT ===== */
    const char* DATA_FILE = "data.txt";
    const char* RESULT_FILE = "result.txt";
    std::ofstream out;

    if (test_type != MANUAL_TESTING) {
        std::cout << "The automatically generated data was written in " << DATA_FILE << " file.\n";
        std::cout << "The result of sorting was written in " << RESULT_FILE << " file.\n";

        out.open(DATA_FILE);
        out << n << "\n";
        for (int i = 0; i < n; i++) out << originalArr[i] << " ";
        out.close();
        out.open(RESULT_FILE);
        for (int i = 0; i < n; i++) out << arr[i] << "\n";
        out.close();
    } else {
        std::cout << "The array after sorting:\n";
        for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
        std::cout << "\n";
    }

    checkArray(originalArr, arr, sortingNames[id]);
}

// Driver code
int main() {
    std::cout << "===== SORTING ALGORITHMS IMPLEMENTATIONS =====\n";
    std::cout << "Select the sorting algorithm you want to use:\n";
    for (int id = 0; id <= 7; id++)
        std::cout << id << ". " << sortingNames[id] << "\n";

    while (1) {
        std::cout << "Type 0-7 to select method or another number to exit:";
        int id;
        std::cin >> id;
        if (id < 0 || id > 7) break;

        std::cout << "*** " << sortingNames[id] << " implementation ***\n";
        testingSortingMethod(id);
        std::cout << "================================================\n"; 
    }
}
