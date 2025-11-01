#include <iostream>
#include <vector>
#include <algorithm>

/**

* @brief Merge two arrays using lambda expressions and std::for_each.
*
* Steps:
* 1. Read two integer arrays from the user.
* 2. Use std::for_each with a lambda to copy all elements from both arrays into a new array (arr3).
* 3. Print the merged result.
     */
     int main() {
     int n1, n2;

  // Read first array
  std::cout << "Enter number of elements in first array: ";
  std::cin >> n1;
  std::vector<int> arr1(n1);
  std::cout << "Enter elements of first array: ";
  for (int i = 0; i < n1; i++) {
  std::cin >> arr1[i];
  }

  // Read second array
  std::cout << "Enter number of elements in second array: ";
  std::cin >> n2;
  std::vector<int> arr2(n2);
  std::cout << "Enter elements of second array: ";
  for (int i = 0; i < n2; i++) {
  std::cin >> arr2[i];
  }

  // Create an empty vector to store the merged result
  std::vector<int> arr3;

  // Copy all elements from arr1 into arr3 using a lambda
  std::for_each(arr1.begin(), arr1.end(),
  [&arr3](int val) mutable {
  arr3.push_back(val);  // Append current element from arr1
  });

  // Copy all elements from arr2 into arr3 using another lambda
  std::for_each(arr2.begin(), arr2.end(),
  [&arr3](int val) mutable {
  arr3.push_back(val);  // Append current element from arr2
  });

  // Print the merged array
  std::cout << "Merged array: ";
  for (int val : arr3) {
  std::cout << val << " ";
  }
  std::cout << std::endl;

  return 0;
  }
