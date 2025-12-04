#include <iostream>
#include <list>
#include <algorithm> // for std::find, reverse, sort

// Print function
template <typename T>
void print_list(const std::list<T> &lst, const std::string &title = "")
{
  if (!title.empty())
    std::cout << "\n=== " << title << " ===\n";
  for (const auto &elem : lst)
  {
    std::cout << elem << " ";
  }
  std::cout << "\n";
}

int main()
{

  // ----------------------------
  // Constructors
  // ----------------------------

  std::list<int> l1;
  // Empty constructor

  std::list<int> l2(5);
  // Fill constructor: 5 default-initialized elements (0)

  std::list<int> l3(5, 10);
  // Fill constructor: 5 elements all = 10

  std::list<int> l4 = {1, 2, 3, 4};
  // Initializer list constructor

  std::list<int> l5(l4.begin(), l4.end());
  // Range constructor

  std::list<int> l6(l4);
  // Copy constructor

  std::list<int> l7(std::move(l4));
  // Move constructor

  print_list(l3, "l3 (fill constructor 5x10)");
  print_list(l4, "l4 (after move, unspecified or empty)");
  print_list(l7, "l7 (moved from l4)");

  // ----------------------------
  // Element Access
  // ----------------------------

  std::list<int> l = {10, 20, 30, 40, 50};

  std::cout << "\nfront(): " << l.front();
  // access first element

  std::cout << "\nback(): " << l.back();
  // access last element

  // IMPORTANT: no operator[] or at()
  // list does NOT support random access!
  // Only front/back or iterators

  std::cout << "\n";

  // ----------------------------
  // Modifiers
  // ----------------------------

  l.push_back(60);
  // add to back

  l.push_front(5);
  // add to front

  l.emplace_back(70);
  // optimized construction at back

  l.emplace_front(1);
  // optimized construction at front

  print_list(l, "After push and emplace");

  l.pop_back();
  // remove last

  l.pop_front();
  // remove first

  print_list(l, "After pop");

  // Insert at a position (only with iterator)
  auto it = l.begin();
  std::advance(it, 2); // move iterator to index 2
  l.insert(it, 999);

  print_list(l, "After insert at index 2");

  // Insert multiple copies
  l.insert(l.begin(), 3, 111);

  print_list(l, "After inserting 3 copies of 111");

  // Insert range
  std::list<int> tmp = {7, 7, 7};
  l.insert(l.end(), tmp.begin(), tmp.end());

  print_list(l, "After inserting range");

  // Assign new values
  l.assign(5, 42);
  print_list(l, "After assign 5 elements of 42");

  // Assign from initializer list
  l.assign({1, 2, 3, 4, 5});
  print_list(l, "After assign initializer list");

  // Erase single element
  auto it2 = l.begin();
  std::advance(it2, 1);
  l.erase(it2);
  print_list(l, "After erase index 1");

  // Erase range
  auto first = l.begin();
  auto last = l.begin();
  std::advance(last, 2);
  l.erase(first, last);
  print_list(l, "After erasing a range");

  // Clear
  l.clear();
  print_list(l, "After clear");

  // ----------------------------
  // Capacity
  // ----------------------------

  std::list<int> lc = {1, 2, 3, 4};
  std::cout << "\nsize(): " << lc.size();
  std::cout << "\nempty(): " << lc.empty() << "\n";

  // ----------------------------
  // Operations
  // ----------------------------

  lc = {10, 20, 30, 40, 50};

  auto it_find = std::find(lc.begin(), lc.end(), 30);

  if (it_find != lc.end())
    std::cout << "\nFound 30\n";
  else
    std::cout << "\n30 not found\n";

  // reverse
  lc.reverse(); // list has its own reverse()
  print_list(lc, "After reverse");

  // sort (list has its own merge sort)
  lc.sort();
  print_list(lc, "After sort");

  // unique (remove duplicates)
  lc = {1, 1, 2, 2, 3, 3};
  lc.unique();
  print_list(lc, "After unique (remove duplicates)");

  // remove by value
  lc = {10, 20, 30, 20, 40, 20};
  lc.remove(20);
  print_list(lc, "After remove(20)");

  return 0;
}

// === l3 (fill constructor 5x10) ===
// 10 10 10 10 10

// === l4 (after move, unspecified or empty) ===

// === l7 (moved from l4) ===
// 1 2 3 4

// front(): 10
// back(): 50

// === After push and emplace ===
// 1 5 10 20 30 40 50 60 70

// === After pop ===
// 5 10 20 30 40 50 60

// === After insert at index 2 ===
// 5 10 999 20 30 40 50 60

// === After inserting 3 copies of 111 ===
// 111 111 111 5 10 999 20 30 40 50 60

// === After inserting range ===
// 111 111 111 5 10 999 20 30 40 50 60 7 7 7

// === After assign 5 elements of 42 ===
// 42 42 42 42 42

// === After assign initializer list ===
// 1 2 3 4 5

// === After erase index 1 ===
// 1 3 4 5

// === After erasing a range ===
// 4 5

// === After clear ===

// size(): 4
// empty(): 0

// Found 30

// === After reverse ===
// 50 40 30 20 10

// === After sort ===
// 10 20 30 40 50

// === After unique (remove duplicates) ===
// 1 2 3

// === After remove(20) ===
// 10 30 40
