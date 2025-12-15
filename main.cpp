#include <iostream>

// original code with comments showing insights output

// template<typename T, typename U>
// struct Pair
// {
//   static inline void print()
//   {
//     std::operator<<(std::cout, "Primary template\n");
//   }

// };

// /* First instantiated from: insights.cpp:23 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// struct Pair<float, double>
// {
//   static inline void print()
//   {
//     std::operator<<(std::cout, "Primary template\n");
//   }

// };

// #endif
// /* First instantiated from: insights.cpp:24 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// struct Pair<char, int>
// {
//   static inline void print()
//   {
//     std::operator<<(std::cout, "Partial specialization: U = int\n");
//   }

// };

// #endif

// template<typename T>
// struct Pair<T, int>
// {
//   static inline void print()
//   {
//     std::operator<<(std::cout, "Partial specialization: U = int\n");
//   }

// };

// Primary template
template <typename T, typename U>
struct Pair
{
  static void print()
  {
    std::cout << "Primary template\n";
  }
};
template <typename T>
struct Pair<T, int>
{
  static void print()
  {
    std::cout << "Partial specialization: U = int\n";
  }
};

int main()
{
  Pair<float, double>::print(); // Primary template
  Pair<char, int>::print();     // Partial specialization

  return 0;
}
// Primary template
// Partial specialization: U = int