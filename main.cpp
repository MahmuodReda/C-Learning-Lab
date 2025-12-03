#include <iostream>
#include <array>
#include <algorithm>

template <typename T, std::size_t N>
void print_array(const std::array<T, N> &arr, const std::string &name)
{
  std::cout << name << " (size: " << arr.size() << "): ";
  for (const auto &e : arr)
    std::cout << e << " ";
  std::cout << "\n";
}

int main()
{
  // 1. Constructors
  std::array<int, 5> a1;                   // default (uninitialized values)
  std::array<int, 5> a2 = {1, 2, 3, 4, 5}; // initializer list
  std::array<int, 5> a3(a2);               // copy constructor
  std::array<int, 5> a4 = a2;              // copy assignment
  std::array<int, 5> a5 = {0};             // fill first element, rest become 0

  print_array(a2, "a2");
  print_array(a3, "a3");
  print_array(a5, "a5");

  // 2. Element access
  std::cout << "a2[0]: " << a2[0] << "\n";         // operator[]
  std::cout << "a2.at(1): " << a2.at(1) << "\n";   // bounds-checked
  std::cout << "front: " << a2.front() << "\n";    // first element
  std::cout << "back: " << a2.back() << "\n";      // last element
  std::cout << "data(): " << *(a2.data()) << "\n"; // pointer to raw array

  // 3. Iterators
  std::cout << "Forward iteration: ";
  for (auto it = a2.begin(); it != a2.end(); ++it)
    std::cout << *it << " ";
  std::cout << "\n";

  std::cout << "Reverse iteration: ";
  for (auto rit = a2.rbegin(); rit != a2.rend(); ++rit)
    std::cout << *rit << " ";
  std::cout << "\n";

  // 4. Capacity (all fixed)
  std::cout << "size: " << a2.size() << "\n";
  std::cout << "max_size: " << a2.max_size() << "\n";
  std::cout << "empty: " << (a2.empty() ? "yes" : "no") << "\n";

  // 5. Operations
  a1.fill(7); // fill all elements with 7
  print_array(a1, "a1 after fill()");

  a1.swap(a2); // swap contents of two arrays
  print_array(a1, "a1 after swap");
  print_array(a2, "a2 after swap");

  // 6. Algorithms (work perfectly with array)
  std::sort(a2.begin(), a2.end());
  print_array(a2, "a2 after sort");

  std::reverse(a2.begin(), a2.end());
  print_array(a2, "a2 after reverse");

  int sum = 0;
  for (auto &x : a2)
    sum += x;
  std::cout << "Sum = " << sum << "\n";

  return 0;
}

// a2 (size: 5): 1 2 3 4 5
// a3 (size: 5): 1 2 3 4 5
// a5 (size: 5): 0 0 0 0 0
// a2[0]: 1
// a2.at(1): 2
// front: 1
// back: 5
// data(): 1
// Forward iteration: 1 2 3 4 5
// Reverse iteration: 5 4 3 2 1
// size: 5
// max_size: 5
// empty: no
// a1 after fill() (size: 5): 7 7 7 7 7
// a1 after swap (size: 5): 1 2 3 4 5
// a2 after swap (size: 5): 7 7 7 7 7
// a2 after sort (size: 5): 7 7 7 7 7
// a2 after reverse (size: 5): 7 7 7 7 7
// Sum = 35