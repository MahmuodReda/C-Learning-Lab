#include <iostream>
#include <memory>

//  Original code before insights transformation:
// template<typename T>
// T fun(T a, T b)
// {
//   return a / b;
// }

// /* First instantiated from: insights.cpp:11 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// double fun<double>(double a, double b)
// {
//   return a / b;
// }
// #endif

// /* First instantiated from: insights.cpp:12 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// int fun<int>(int a, int b)
// {
//   return a / b;
// }
// #endif

// /* First instantiated from: insights.cpp:13 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// float fun<float>(float a, float b)
// {
//   return a / b;
// }
// #endif

// int main()
// {
//   std::cout.operator<<(fun(1.0, 2.0)).operator<<(std::endl);
//   std::cout.operator<<(fun(5, 2)).operator<<(std::endl);
//   std::cout.operator<<(fun(5.0F, 2.0F)).operator<<(std::endl);
//   return 0;
// }

template <typename T>
T fun(T a, T b)
{
  return a / b;
}
int main()
{
  std::cout << fun(1.0, 2.0) << std::endl;
  std::cout << fun(5, 2) << std::endl;
  std::cout << fun(5.0f, 2.0f) << std::endl;

  return 0;
}
