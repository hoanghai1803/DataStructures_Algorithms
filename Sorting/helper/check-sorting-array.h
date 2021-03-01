#include <iostream>
#include <algorithm>
#include <vector>

// This function uses sort function build-in C++ STL for checking
// if result of the implementation of any sorting algorithm are correct or not
void checkArray(std::vector<long long>& originalArr, std::vector<long long>& sortedArr, std::string sortingName) {
    bool chk = true;

    if (sortedArr.size() != originalArr.size()) chk = false;
    int _size = sortedArr.size();

    std::sort(originalArr.begin(), originalArr.end());
    for (int i = 0; i < _size; i++)
        if (sortedArr[i] != originalArr[i]) chk = false;

    if (chk) 
        std::cout << "The " << sortingName << " method runs correctly!\n";
    else
        std::cout << "Oops, wrong answer! There are problems with this implementation of " << sortingName << "!\n";
}
