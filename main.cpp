#include <iostream>

// original code before insights transformation

// template<typename T>
// void print(T t)
// {
//   (std::cout << t) << std::endl;
// }

// /* First instantiated from: insights.cpp:12 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// void print<float>(float t)
// {
//   std::cout.operator<<(t).operator<<(std::endl);
// }
// #endif

// template<typename T, typename ... Args>
// void print(T t, Args... arg)
// {
//   std::cout << t;
//   std::operator<<(std::cout, " SIZE : ").operator<<(sizeof...(arg)).operator<<(std::endl);
//   print(arg... );
// }

// /* First instantiated from: insights.cpp:17 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// void print<int, double, const char *, float>(int t, double __arg1, const char * __arg2, float __arg3)
// {
//   std::cout.operator<<(t);
//   std::operator<<(std::cout, " SIZE : ").operator<<(3).operator<<(std::endl);
//   print(__arg1, __arg2, __arg3);
// }
// #endif

// /* First instantiated from: insights.cpp:12 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// void print<double, const char *, float>(double t, const char * __arg1, float __arg2)
// {
//   std::cout.operator<<(t);
//   std::operator<<(std::cout, " SIZE : ").operator<<(2).operator<<(std::endl);
//   print(__arg1, __arg2);
// }
// #endif

// /* First instantiated from: insights.cpp:12 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// void print<const char *, float>(const char * t, float __arg1)
// {
//   std::operator<<(std::cout, t);
//   std::operator<<(std::cout, " SIZE : ").operator<<(1).operator<<(std::endl);
//   print(__arg1);
// }
// #endif

// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// void print<float>(float t);
// #endif

template <typename T>
void print(T t)
{
  std::cout << t << std::endl;
}
template <typename T, typename... Args>
void print(T t, Args... arg)
{
  std::cout << t;
  std::cout << " SIZE : " << sizeof...(arg) << std::endl;
  print(arg...);
}

int main()
{
  print(1, 2.5, "Hello", 3.5f);

  return 0;
}
// print(1, 2.5, "Hello", 3.5f)
//  └── print(2.5, "Hello", 3.5f)
//       └── print("Hello", 3.5f)
//            └── print(3.5f)
//                 └── base case

// 1 SIZE : 3
// 2.5 SIZE : 2
// Hello SIZE : 1
// 3.5