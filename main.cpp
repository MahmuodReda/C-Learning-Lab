/********************************************************************
 * Comprehensive std::tuple Example
 * ------------------------------------------------------------------
 * This example demonstrates most common and important usages of
 * std::tuple in C++:
 *
 * 1) Creating a tuple with heterogeneous types
 * 2) Accessing elements by index using std::get
 * 3) Modifying tuple elements
 * 4) Accessing nested objects inside a tuple
 * 5) Querying tuple size at compile time
 * 6) Using std::tie to unpack a tuple
 * 7) Using std::make_tuple
 * 8) Structured bindings (C++17)
 * 9) Using tuple as a return type
 ********************************************************************/

#include <tuple>
#include <vector>
#include <string>
#include <iostream>

/********************************************************************
 * Function returning multiple values using std::tuple
 ********************************************************************/
std::tuple<int, double, std::string> createData()
{
  return std::make_tuple(42, 3.14, "Pi");
}

int main()
{
  /****************************************************************
   * 1) Creating a tuple with different types
   ****************************************************************/
  std::tuple<int, float, std::string, std::vector<int>> t{
      1,
      2.0f,
      "Hello",
      {1, 2, 3}};

  /****************************************************************
   * 2) Accessing tuple elements using std::get<index>
   *    Index is compile-time constant
   ****************************************************************/
  std::cout << "Element 0 (int): " << std::get<0>(t) << std::endl;
  std::cout << "Element 1 (float): " << std::get<1>(t) << std::endl;
  std::cout << "Element 2 (string): " << std::get<2>(t) << std::endl;

  /****************************************************************
   * 3) Modifying tuple elements
   ****************************************************************/
  std::get<0>(t) = 10;
  std::get<2>(t) = "World";

  std::cout << "Modified element 0: " << std::get<0>(t) << std::endl;
  std::cout << "Modified element 2: " << std::get<2>(t) << std::endl;

  /****************************************************************
   * 4) Accessing nested containers inside a tuple
   ****************************************************************/
  std::cout << "First element of vector inside tuple: "
            << std::get<3>(t)[0] << std::endl;

  /****************************************************************
   * 5) Getting tuple size at compile time
   ****************************************************************/
  std::cout << "Tuple size: "
            << std::tuple_size<decltype(t)>::value << std::endl;

  /****************************************************************
   * 6) Unpacking a tuple using std::tie
   ****************************************************************/
  int a;
  float b;
  std::string c;
  std::vector<int> d;

  std::tie(a, b, c, d) = t;

  std::cout << "Unpacked values via std::tie:\n";
  std::cout << "a = " << a << ", b = " << b
            << ", c = " << c << ", d[1] = " << d[1] << std::endl;

  /****************************************************************
   * 7) Creating tuple using std::make_tuple
   ****************************************************************/
  auto t2 = std::make_tuple(5, 'A', 9.9);

  std::cout << "t2 values: "
            << std::get<0>(t2) << ", "
            << std::get<1>(t2) << ", "
            << std::get<2>(t2) << std::endl;

  /****************************************************************
   * 8) Structured bindings (C++17)
   *    Automatically unpack tuple into variables
   ****************************************************************/
  auto [id, value, name] = createData();

  std::cout << "Structured binding result:\n";
  std::cout << "id = " << id
            << ", value = " << value
            << ", name = " << name << std::endl;

  /****************************************************************
   * 9) Using tuple as a return type
   ****************************************************************/
  auto result = createData();

  std::cout << "Returned tuple values:\n";
  std::cout << std::get<0>(result) << ", "
            << std::get<1>(result) << ", "
            << std::get<2>(result) << std::endl;

  return 0;
}

// Element 0 (int): 1
// Element 1 (float): 2
// Element 2 (string): Hello
// Modified element 0: 10
// Modified element 2: World
// First element of vector inside tuple: 1
// Tuple size: 4
// Unpacked values via std::tie:
// a = 10, b = 2, c = World, d[1] = 2
// t2 values: 5, A, 9.9
// Structured binding result:
// id = 42, value = 3.14, name = Pi
// Returned tuple values:
// 42, 3.14, Pi
