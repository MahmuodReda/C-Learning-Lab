#include <iostream>
#include <vector>
#include <string>

template <typename T>
void print_vector(const std::vector<T> &v, const std::string &name)
{
  std::cout << name << " (size: " << v.size()
            << ", capacity: " << v.capacity() << "): ";
  for (const auto &e : v)
    std::cout << e << " ";
  std::cout << "\n";
}

int main()
{
  // 1. Constructors
  std::vector<int> v1;                       // default constructor
  std::vector<int> v2(3, 10);                // fill constructor: 3 elements, each 10
  std::vector<int> v3 = {1, 2, 3, 4};        // initializer list
  std::vector<int> v4(v3);                   // copy constructor
  std::vector<int> v5(v3.begin(), v3.end()); // range constructor
  std::vector<int> v6 = std::move(v4);       // move constructor

  print_vector(v3, "v3");
  print_vector(v2, "v2");
  print_vector(v4, "v4 (moved)"); // should be empty
  print_vector(v6, "v6 (moved from v4)");

  // 2. Modifiers
  v3.push_back(5);                      // add element at the end
  v3.emplace_back(6);                   // add element in place at the end
  v3.insert(v3.begin(), 0);             // insert element at beginning
  v3.emplace(v3.begin() + 2, 99);       // insert element in place
  v3.erase(v3.begin() + 1);             // remove element at index 1
  v3.erase(v3.begin(), v3.begin() + 2); // remove first two elements
  v3.assign({7, 8, 9, 10});             // assign new values
  v3.assign(3, 42);                     // assign 3 elements of value 42

  print_vector(v3, "v3 after modifications");

  // 3. Element access
  std::cout << "First element (front): " << v3.front() << "\n";
  std::cout << "Last element (back): " << v3.back() << "\n";
  std::cout << "Element at index 1 (at): " << v3.at(1) << "\n";

  // 4. Capacity
  std::cout << "Empty? " << (v3.empty() ? "Yes" : "No") << "\n";
  std::cout << "Size: " << v3.size() << "\n";
  std::cout << "Max size: " << v3.max_size() << "\n";
  std::cout << "Capacity: " << v3.capacity() << "\n";
  v3.reserve(10); // reserve space for 10 elements
  std::cout << "Capacity after reserve(10): " << v3.capacity() << "\n";
  v3.shrink_to_fit(); // reduce capacity to fit size
  std::cout << "Capacity after shrink_to_fit(): " << v3.capacity() << "\n";

  // 5. Iterators
  std::cout << "Vector using iterators: ";
  for (auto it = v3.begin(); it != v3.end(); ++it)
    std::cout << *it << " ";
  std::cout << "\n";

  std::cout << "Vector using reverse iterators: ";
  for (auto rit = v3.rbegin(); rit != v3.rend(); ++rit)
    std::cout << *rit << " ";
  std::cout << "\n";

  // 6. Swap
  std::vector<int> swap_vec = {100, 200, 300};
  v3.swap(swap_vec);
  print_vector(v3, "v3 after swap");
  print_vector(swap_vec, "swap_vec after swap");

  // 7. Clear
  v3.clear();
  print_vector(v3, "v3 after clear");

  return 0;
}
// v3 (size: 4, capacity: 4): 1 2 3 4
// v2 (size: 3, capacity: 3): 10 10 10
// v4 (moved) (size: 0, capacity: 0):
// v6 (moved from v4) (size: 4, capacity: 4): 1 2 3 4
// v3 after modifications (size: 3, capacity: 8): 42 42 42
// First element (front): 42
// Last element (back): 42
// Element at index 1 (at): 42
// Empty? No
// Size: 3
// Max size: 2305843009213693951
// Capacity: 8
// Capacity after reserve(10): 10
// Capacity after shrink_to_fit(): 3
// Vector using iterators: 42 42 42
// Vector using reverse iterators: 42 42 42
// v3 after swap (size: 3, capacity: 3): 100 200 300
// swap_vec after swap (size: 3, capacity: 3): 42 42 42
// v3 after clear (size: 0, capacity: 3):