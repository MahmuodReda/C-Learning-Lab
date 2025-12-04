#include <iostream>
#include <unordered_set>
#include <string>

template <typename T>
void print_unordered_set(const std::unordered_set<T> &s, const std::string &name)
{
  std::cout << name << " (size: " << s.size() << "): ";
  for (const auto &e : s)
    std::cout << e << " ";
  std::cout << "\n";
}

int main()
{
  // 1. Constructors
  std::unordered_set<int> us1;                         // default constructor
  std::unordered_set<int> us2 = {4, 1, 3, 2, 2};       // initializer list constructor (duplicates ignored)
  std::unordered_set<int> us3(us2);                    // copy constructor
  std::unordered_set<int> us4(us2.begin(), us2.end()); // range constructor
  std::unordered_set<int> us5(std::move(us4));         // move constructor (us4 becomes empty)

  print_unordered_set(us2, "us2");
  print_unordered_set(us3, "us3 (copy of us2)");
  print_unordered_set(us4, "us4 (moved, should be empty)");
  print_unordered_set(us5, "us5 (moved from us4)");

  // 2. Modifiers
  us2.insert(5);         // insert single element
  us2.insert({6, 7, 8}); // insert initializer list
  us2.erase(1);          // erase element by value
  print_unordered_set(us2, "us2 after insert and erase");

  us3.clear(); // clear set
  print_unordered_set(us3, "us3 after clear");

  // 3. Lookup
  std::cout << "us2 contains 5? " << (us2.count(5) ? "Yes" : "No") << "\n";
  auto it = us2.find(6);
  if (it != us2.end())
    std::cout << "Found element 6 in us2: " << *it << "\n";
  else
    std::cout << "Element 6 not found in us2\n";

  // 4. Iterators (order is unspecified)
  std::cout << "us2 using iterators (unordered, no order guaranteed): ";
  for (auto it = us2.begin(); it != us2.end(); ++it)
    std::cout << *it << " ";
  std::cout << "\n";

  // 5. Swap
  std::unordered_set<int> swap_set = {100, 200, 300};
  us2.swap(swap_set);
  print_unordered_set(us2, "us2 after swap");
  print_unordered_set(swap_set, "swap_set after swap");

  // 6. Size / empty
  std::cout << "us2 empty? " << (us2.empty() ? "Yes" : "No") << "\n";
  std::cout << "us2 size: " << us2.size() << "\n";

  return 0;
}

/*

Notes about unordered_set:

- Constructors:
  - default, initializer list, copy, range, move
- Modifiers:
  - insert(value), insert({list})
  - erase(value), clear(), swap(other)
- Lookup:
  - find(value), count(value)
- Iteration:
  - begin() to end() iterates in unspecified order
- No ordering guarantees unlike std::set
- Uniqueness of elements is enforced

*/

// us2 (size: 4): 2 3 1 4
// us3 (copy of us2) (size: 4): 2 3 1 4
// us4 (moved, should be empty) (size: 0):
// us5 (moved from us4) (size: 4): 4 1 3 2
// us2 after insert and erase (size: 7): 8 7 6 5 2 3 4
// us3 after clear (size: 0):
// us2 contains 5? Yes
// Found element 6 in us2: 6
// us2 using iterators (unordered, no order guaranteed): 8 7 6 5 2 3 4
// us2 after swap (size: 3): 300 200 100
// swap_set after swap (size: 7): 8 7 6 5 2 3 4
// us2 empty? No
// us2 size: 3