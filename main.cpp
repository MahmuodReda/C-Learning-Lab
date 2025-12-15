/********************************************************************
 * Comprehensive std::pair Example
 * ------------------------------------------------------------------
 * This example demonstrates the most important and common usages of
 * std::pair in C++:
 *
 * 1) Creating pairs (direct initialization and make_pair)
 * 2) Accessing elements using .first and .second
 * 3) Modifying pair elements
 * 4) Using pair in containers (vector, map)
 * 5) Structured bindings (C++17)
 * 6) Pair comparison (lexicographical)
 * 7) Returning pair from a function
 ********************************************************************/

#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <string>

/********************************************************************
 * Function returning a pair
 ********************************************************************/
std::pair<int, std::string> createPair()
{
  // Returning multiple values using std::pair
  return std::make_pair(7, "Seven");
}

int main()
{
  /****************************************************************
   * 1) Creating a pair (direct initialization)
   ****************************************************************/
  std::pair<int, std::string> p1(42, "Hello");

  std::cout << "p1: " << p1.first << ", " << p1.second << std::endl;

  /****************************************************************
   * 2) Creating a pair using std::make_pair
   *    (type deduction)
   ****************************************************************/
  auto p2 = std::make_pair(100, std::string("World"));

  std::cout << "p2: " << p2.first << ", " << p2.second << std::endl;

  /****************************************************************
   * 3) Modifying pair elements
   ****************************************************************/
  p1.first = 10;
  p1.second = "Changed";

  std::cout << "Modified p1: "
            << p1.first << ", " << p1.second << std::endl;

  /****************************************************************
   * 4) Structured bindings (C++17)
   *    Unpack pair into separate variables
   ****************************************************************/
  auto [number, text] = p1;

  std::cout << "Structured binding:\n";
  std::cout << "number = " << number << ", text = " << text << std::endl;

  /****************************************************************
   * 5) Pair comparison (lexicographical order)
   *    First elements are compared first, then second
   ****************************************************************/
  std::pair<int, int> a{1, 10};
  std::pair<int, int> b{2, 5};

  if (a < b)
  {
    std::cout << "Pair a is less than pair b\n";
  }

  /****************************************************************
   * 6) Using pair inside a vector
   ****************************************************************/
  std::vector<std::pair<int, std::string>> vec;

  vec.push_back({1, "One"});
  vec.push_back({2, "Two"});

  std::cout << "Vector of pairs:\n";
  for (const auto &p : vec)
  {
    std::cout << p.first << " -> " << p.second << std::endl;
  }

  /****************************************************************
   * 7) Using pair in a map
   *    (map internally stores key-value pairs)
   ****************************************************************/
  std::map<int, std::string> myMap;

  myMap.insert({1, "Apple"});
  myMap.insert({2, "Banana"});

  std::cout << "Map elements:\n";
  for (const auto &entry : myMap)
  {
    // entry is std::pair<const int, std::string>
    std::cout << entry.first << " => " << entry.second << std::endl;
  }

  /****************************************************************
   * 8) Returning and using a pair from a function
   ****************************************************************/
  auto result = createPair();

  std::cout << "Returned pair: "
            << result.first << ", " << result.second << std::endl;

  return 0;
}

// p1: 42, Hello
// p2: 100, World
// Modified p1: 10, Changed
// Structured binding:
// number = 10, text = Changed
// Pair a is less than pair b
// Vector of pairs:
// 1 -> One
// 2 -> Two
// Map elements:
// 1 => Apple
// 2 => Banana
// Returned pair: 7, Seven