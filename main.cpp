#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Find the maximum element in an array using lambda and sorting.
 * @details The array is sorted in ascending order with a lambda comparator.
 * The last element after sorting is the maximum value.
 */
int main() {
    int n;
    std::cout << "n=" ;

    std::cin >> n;
    if (n == 0 || n > 20)
    {
          std::cout << " Error " << std::endl;
          return 0;
    }

    std::vector<int> arr(n);

    std::cout << " Input array elements " << std::endl;
    // Input array elements from user
    for (size_t i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Finding the maximum element in the array." << std::endl;

    // Sort array using lambda comparator (ascending order)
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        return a < b;
    });

    // Print the sorted array
    for (int val : arr) {
        std::cout << val << " ";
    }

    std::cout << std::endl;
    std::cout << "Maximum element: " << arr.back() << std::endl;

    return 0;
}

// n=10
//  Input array elements 
// 5
// 3
// 2
// 1
// 45
// 6
// 5
// 48
// 48
// 5
// Finding the maximum element in the array.
// 1 2 3 5 5 5 6 45 48 48
// Maximum element: 48