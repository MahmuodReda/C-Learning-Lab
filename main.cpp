#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Search for a number in the array using a lambda expression.
 * 
 * This program:
 * 1. Reads an array from the user.
 * 2. Asks for a target number.
 * 3. Uses a lambda inside std::find_if to locate the number.
 */
int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    // Read elements into the array
    for (size_t i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int target;
    std::cout << "Enter number to search: ";
    std::cin >> target;

    /**
     * @brief Lambda to check if the current element equals the target.
     */
    auto it = std::find_if(arr.begin(), arr.end(), [target](int x) {
        return x == target; // Return true if found
    });

    // Check if the number was found
    if (it != arr.end()) {

        int index = std::distance(arr.begin(), it); 
        std::cout << "Number found in the array: " << *it << std::endl;
        std::cout << "Index: " << index << std::endl;
    } else {
        std::cout << "Number not found in the array." << std::endl;
    }

    return 0;
}
