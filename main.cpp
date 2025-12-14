#include <iostream>
#include <memory>

// /* Original Code */
// template<typename T>
// class container2
// {

//   public:
//   T value;
//   inline container2(T val)
//   : value(val)
//   {
//   }

//   template<typename U>
//   inline void add(U val)
//   {
//     this->value = static_cast<T>(this->value + val);
//     std::operator<<(std::operator<<(std::cout, "type of U: "), typeid(U).name()).operator<<(std::endl);
//   }
//   inline void print()
//   {
//     (std::cout << this->value) << std::endl;
//   }

// };

// /* First instantiated from: insights.cpp:24 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// class container2<int>
// {

//   public:
//   int value;
//   inline container2(int val)
//   : value{val}
//   {
//   }

//   template<typename U>
//   inline void add(U val);

//   /* First instantiated from: insights.cpp:25 */
//   #ifdef INSIGHTS_USE_TEMPLATE
//   template<>
//   inline void add<double>(double val)
//   {
//     this->value = static_cast<int>(static_cast<double>(this->value) + val);
//     std::operator<<(std::operator<<(std::cout, "type of U: "), typeid(double).name()).operator<<(std::endl);
//   }
//   #endif

//   /* First instantiated from: insights.cpp:27 */
//   #ifdef INSIGHTS_USE_TEMPLATE
//   template<>
//   inline void add<int>(int val)
//   {
//     this->value = static_cast<int>(this->value + val);
//     std::operator<<(std::operator<<(std::cout, "type of U: "), typeid(int).name()).operator<<(std::endl);
//   }
//   #endif

//   inline void print()
//   {
//     std::cout.operator<<(this->value).operator<<(std::endl);
//   }

// };

// #endif

// int main()
// {
//   container2<int> c = container2<int>(10);
//   c.add<double>(2.5);
//   c.print();
//   c.add<int>(5);
//   c.print();
//   return 0;
// }

// template<typename T>
// container2(T val) -> container2<T>;

// /* First instantiated from: insights.cpp:24 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// container2(int val) -> container2<int>;
// #endif

template <typename T>
class container2
{
public:
  T value;

  container2(T val) : value(val) {}

  template <typename U>
  void add(U val)
  {
    value += val;
    std::cout << "type of U: " << typeid(U).name() << std::endl;
  }

  void print() { std::cout << value << std::endl; }
};

int main()
{
  container2 c(10);
  c.add(2.5);
  c.print(); // Should output 12
  c.add(5);
  c.print(); // Should output 17

  return 0;
}
// type of U: d
// 12
// type of U: i
// 17
