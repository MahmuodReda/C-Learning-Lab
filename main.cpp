#include <iostream>

// original code

// template<class T>
// class Box
// {

//   public:
//   inline Box(T v)
//   {
//     std::operator<<(std::cout, "Generic Box\n");
//   }

// };

// /* First instantiated from: insights.cpp:26 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// class Box<int>
// {

//   public:
//   inline Box(int v)
//   {
//     std::operator<<(std::cout, "Generic Box\n");
//   }

// };

// #endif
// /* First instantiated from: insights.cpp:28 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// class Box<double>
// {

//   public:
//   inline Box(double v)
//   {
//     std::operator<<(std::cout, "Generic Box\n");
//   }

// };

// #endif

// template<>
// class Box<float>
// {

//   public:
//   inline Box(float v)
//   {
//     std::operator<<(std::cout, "Float Box (Specialized)\n");
//   }

// };

template <class T>
class Box
{
public:
  Box(T v)
  {
    std::cout << "Generic Box\n";
  }
};

template <>
class Box<float>
{
public:
  Box(float v)
  {
    std::cout << "Float Box (Specialized)\n";
  }
};

int main()
{

  Box<int> a(5);      // Generic Box
  Box<float> b(3.5f); // Float Box (Specialized)
  Box c(1.2);         // Generic Box
  return 0;
}
// Generic Box
// Float Box (Specialized)
// Generic Box