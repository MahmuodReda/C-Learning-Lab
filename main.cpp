#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Remove all occurrences of a given number from an array using a lambda.
 * 
 * This program:
 * 1. Reads an array from the user.
 * 2. Reads a target number to delete.
 * 3. Uses std::remove_if with a lambda to remove matching numbers.
 * 4. Erases the removed elements from the vector.
 */
int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);

    // Input array elements
    std::cout << "Enter array elements: ";
    for (size_t i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int target;
    std::cout << "Enter number to delete: ";
    std::cin >> target;

    /**
     * @brief Lambda checks if the element equals the target value.
     *        Used by std::remove_if to mark elements for removal.
     */
    auto newEnd = std::remove_if(arr.begin(), arr.end(), [target](int x) {
        return x == target;
    });

    // Erase the "removed" elements
    arr.erase(newEnd, arr.end());

    // Display result
    std::cout << "Array after deletion: ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
