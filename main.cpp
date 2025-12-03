#include <array>
#include <iostream>

int main()
{
  // Create a fixed-size array of 5 integers
  std::array<int, 5> arr = {1, 0, 3}; // indices 1,3,4 default to 0

  // Print array size
  std::cout << "Array size: " << arr.size() << std::endl; // size() returns 5

  // Check if array is empty
  std::cout << "Is array empty? " << (arr.empty() ? "Yes" : "No") << std::endl;

  // Access elements using at() with bounds checking
  try
  {
    std::cout << "Element at index 2: " << arr.at(2) << std::endl;
    // arr.at(10); // would throw out_of_range if uncommented
  }
  catch (const std::out_of_range &e)
  {
    std::cout << "Error: " << e.what() << std::endl;
  }

  // Modify an element using []
  arr[1] = 12; // index 1

  // Print all elements using range-based for loop
  std::cout << "Array elements: ";
  for (const auto &i : arr)
  {
    std::cout << i << " "; // prints: 1 12 3 0 0
  }
  std::cout << std::endl;

  return 0;
}

// Array size: 5
// Is array empty? No
// Element at index 2: 3
// Array elements: 1 12 3 0 0