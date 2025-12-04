#include <iostream>
#include <set>
#include <string>

template <typename T, typename Compare = std::less<T>>
void print_set(const std::set<T, Compare> &s, const std::string &name)
{
  std::cout << name << " (size: " << s.size() << "): ";
  for (const auto &e : s)
    std::cout << e << " ";
  std::cout << "\n";
}

int main()
{
  // 1. Constructors
  std::set<int> s1;                       // default constructor
  std::set<int> s2 = {4, 1, 3, 2, 2};     // initializer list constructor (duplicates ignored)
  std::set<int> s3(s2);                   // copy constructor
  std::set<int> s4(s2.begin(), s2.end()); // range constructor
  std::set<int> s5(std::move(s4));        // move constructor (s4 becomes empty)

  print_set(s2, "s2");
  print_set(s3, "s3 (copy of s2)");
  print_set(s4, "s4 (moved, should be empty)");
  print_set(s5, "s5 (moved from s4)");

  // 2. Modifiers
  s2.insert(5);         // insert single element
  s2.insert({6, 7, 8}); // insert initializer list
  s2.erase(1);          // erase element by value
  s2.erase(s2.begin()); // erase element by iterator
  print_set(s2, "s2 after insert and erase");

  s3.clear(); // clear set
  print_set(s3, "s3 after clear");

  // 3. Element access / lookup
  std::cout << "s2 contains 5? " << (s2.count(5) ? "Yes" : "No") << "\n";
  auto it = s2.find(6);
  if (it != s2.end())
    std::cout << "Found element 6 in s2: " << *it << "\n";
  else
    std::cout << "Element 6 not found in s2\n";

  std::cout << "Lower bound of 4 in s2: " << *s2.lower_bound(4) << "\n";
  std::cout << "Upper bound of 4 in s2: " << *s2.upper_bound(4) << "\n";

  // 4. Iterators
  std::cout << "s2 using iterators: ";
  for (auto it = s2.begin(); it != s2.end(); ++it)
    std::cout << *it << " ";
  std::cout << "\n";

  std::cout << "s2 using reverse iterators: ";
  for (auto rit = s2.rbegin(); rit != s2.rend(); ++rit)
    std::cout << *rit << " ";
  std::cout << "\n";

  // 5. Swap
  std::set<int> swap_set = {100, 200, 300};
  s2.swap(swap_set);
  print_set(s2, "s2 after swap");
  print_set(swap_set, "swap_set after swap");

  // 6. Size / empty
  std::cout << "s2 empty? " << (s2.empty() ? "Yes" : "No") << "\n";
  std::cout << "s2 size: " << s2.size() << "\n";

  // 7. Custom comparator
  std::set<int, std::greater<int>> s_desc = {1, 2, 3, 4, 5};
  print_set(s_desc, "s_desc (descending order)");

  return 0;
}

/*

Explanation:

Constructors:
- Default: empty
- Initializer list: fills with unique sorted elements
- Copy: duplicates another set
- Range: builds from iterator range
- Move: moves content, source becomes empty

Modifiers:
- insert(value), insert({list})
- erase(value) or erase(iterator)
- clear(), swap(other)

Element Access / Lookup:
- find(value): returns iterator or end
- count(value): 0 or 1 since set has unique elements
- lower_bound(value): first element >= value
- upper_bound(value): first element > value

Iterators:
- begin() to end(): ascending order
- rbegin() to rend(): descending iteration

Custom comparator:
- set<int, greater<int>> sorts elements in descending order

*/

// s2 (size: 4): 1 2 3 4
// s3 (copy of s2) (size: 4): 1 2 3 4
// s4 (moved, should be empty) (size: 0):
// s5 (moved from s4) (size: 4): 1 2 3 4
// s2 after insert and erase (size: 6): 3 4 5 6 7 8
// s3 after clear (size: 0):
// s2 contains 5? Yes
// Found element 6 in s2: 6
// Lower bound of 4 in s2: 4
// Upper bound of 4 in s2: 5
// s2 using iterators: 3 4 5 6 7 8
// s2 using reverse iterators: 8 7 6 5 4 3
// s2 after swap (size: 3): 100 200 300
// swap_set after swap (size: 6): 3 4 5 6 7 8
// s2 empty? No
// s2 size: 3
// s_desc (descending order) (size: 5): 5 4 3 2 1