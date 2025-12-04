#include <iostream>
#include <deque>
#include <algorithm> // for std::find

// Print function
template <typename T>
void print_deque(const std::deque<T> &dq, const std::string &title = "")
{
  if (!title.empty())
    std::cout << "\n=== " << title << " ===\n";
  for (const auto &elem : dq)
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

  std::deque<int> d1;
  // Empty constructor

  std::deque<int> d2(5);
  // Fill constructor: 5 default-initialized elements (0)

  std::deque<int> d3(5, 10);
  // Fill constructor: 5 elements initialized with 10

  std::deque<int> d4 = {1, 2, 3, 4};
  // Initializer list constructor

  std::deque<int> d5(d4.begin(), d4.end());
  // Range constructor

  std::deque<int> d6(d4);
  // Copy constructor

  std::deque<int> d7(std::move(d4));
  // Move constructor

  print_deque(d3, "d3 (fill constructor 5x10)");
  print_deque(d4, "d4 (after move, should be empty or unspecified)");
  print_deque(d7, "d7 (moved from d4)");

  // ----------------------------
  // Element Access
  // ----------------------------

  std::deque<int> d = {10, 20, 30, 40, 50};

  std::cout << "\nfront(): " << d.front();
  // Access first element

  std::cout << "\nback(): " << d.back();
  // Access last element

  std::cout << "\nat(2): " << d.at(2);
  // Safe access with bounds checking

  std::cout << "\noperator: " << d[3] << "\n";
  // Fast access without bounds checking

  // ----------------------------
  // Modifiers
  // ----------------------------

  d.push_back(60);
  // Adds at the back

  d.push_front(5);
  // Adds at the front

  d.emplace_back(70);
  // Emplace optimized at back

  d.emplace_front(1);
  // Emplace optimized at front

  print_deque(d, "After push and emplace");

  d.pop_back();
  // remove last

  d.pop_front();
  // remove first

  print_deque(d, "After pop");

  // Insert
  d.insert(d.begin() + 2, 999);
  print_deque(d, "After insert at index 2");

  // Insert multiple
  d.insert(d.begin(), 3, 111);
  print_deque(d, "After inserting 3 copies of 111 at front");

  // Insert range
  std::deque<int> temp = {7, 7, 7};
  d.insert(d.end(), temp.begin(), temp.end());
  print_deque(d, "After inserting range");

  // Assign
  d.assign(5, 42);
  print_deque(d, "After assign 5 elements of value 42");

  // Assign from initializer list
  d.assign({1, 2, 3, 4, 5});
  print_deque(d, "After assign initializer list");

  // Erase
  d.erase(d.begin() + 1);
  print_deque(d, "After erase index 1");

  // Erase range
  d.erase(d.begin(), d.begin() + 2);
  print_deque(d, "After erasing a range");

  // Clear
  d.clear();
  print_deque(d, "After clear");

  // ----------------------------
  // Capacity
  // ----------------------------

  std::deque<int> dc = {1, 2, 3, 4};
  std::cout << "\nsize(): " << dc.size();
  std::cout << "\nempty(): " << dc.empty() << "\n";

  // ----------------------------
  // Operations
  // ----------------------------

  dc = {10, 20, 30, 40, 50};
  auto it = std::find(dc.begin(), dc.end(), 30);

  if (it != dc.end())
    std::cout << "\nFound 30 at index: " << std::distance(dc.begin(), it) << "\n";
  else
    std::cout << "\n30 not found\n";

  // reverse
  std::reverse(dc.begin(), dc.end());
  print_deque(dc, "After reverse");

  // Sort (requires random access iterators → deque supports it)
  std::sort(dc.begin(), dc.end());
  print_deque(dc, "After sort");

  return 0;
}

// === d3 (fill constructor 5x10) ===
// 10 10 10 10 10

// === d4 (after move, should be empty or unspecified) ===

// === d7 (moved from d4) ===
// 1 2 3 4

// front(): 10
// back(): 50
// at(2): 30
// operator: 40

// === After push and emplace ===
// 1 5 10 20 30 40 50 60 70

// === After pop ===
// 5 10 20 30 40 50 60

// === After insert at index 2 ===
// 5 10 999 20 30 40 50 60

// === After inserting 3 copies of 111 at front ===
// 111 111 111 5 10 999 20 30 40 50 60

// === After inserting range ===
// 111 111 111 5 10 999 20 30 40 50 60 7 7 7

// === After assign 5 elements of value 42 ===
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

// Found 30 at index: 2

// === After reverse ===
// 50 40 30 20 10

// === After sort ===
// 10 20 30 40 50