#include <iostream>
#include <memory>

// /* Original Code Before Insights Transformation */
// template<typename T>
// class container
// {

//   public:
//   T value;
//   inline container(T val)
//   : value(val)
//   {
//   }

//   inline void print()
//   {
//     (std::cout << this->value) << std::endl;
//   }

// };

// /* First instantiated from: insights.cpp:15 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// class container<int>
// {

//   public:
//   int value;
//   inline container(int val)
//   : value{val}
//   {
//   }

//   inline void print()
//   {
//     std::cout.operator<<(this->value).operator<<(std::endl);
//   }

// };

// #endif
// /* First instantiated from: insights.cpp:17 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// class container<double>
// {

//   public:
//   double value;
//   inline container(double val)
//   : value{val}
//   {
//   }

//   inline void print()
//   {
//     std::cout.operator<<(this->value).operator<<(std::endl);
//   }

// };

// #endif

// int main()
// {
//   container<int> c1 = container<int>(10);
//   c1.print();
//   container<double> c2 = container<double>(3.1400000000000001);
//   c2.print();
//   return 0;
// }
template <typename T>
class container
{
public:
  T value;

  container(T val) : value(val) {}
  void print() { std::cout << value << std::endl; }
};

int main()
{
  container<int> c1(10);
  c1.print();
  container<double> c2(3.14);
  c2.print();

  return 0;
}
