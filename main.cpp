#include <map>
#include <iostream>
#include <chrono>
#include <thread>

enum class fruit
{
  Apple,
  Banana,
  Orange
};

class intrface_fruit
{
public:
  virtual void info() = 0;
  virtual ~intrface_fruit() = default;
};
class Apple_fruit : public intrface_fruit
{
public:
  void info() override
  {
    std::cout << "This is an Apple" << std::endl;
  }
};
class Banana_fruit : public intrface_fruit
{
public:
  void info() override
  {
    std::cout << "This is a Banana" << std::endl;
  }
};
class Orange_fruit : public intrface_fruit
{
public:
  void info() override
  {
    std::cout << "This is an Orange" << std::endl;
  }
};
int main()
{
  std::map<fruit, std::pair<fruit, intrface_fruit *>> fruit_map = {
      {fruit::Apple, {fruit::Banana, new Banana_fruit()}},
      {fruit::Banana, {fruit::Orange, new Orange_fruit()}},
      {fruit::Orange, {fruit::Apple, new Apple_fruit()}}};
  fruit current_fruit = fruit::Apple;
  int count = 0;
  while (count++ < 3)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Current fruit : " << static_cast<int>(current_fruit) << std::endl;
    fruit_map[current_fruit].second->info();
    current_fruit = fruit_map[current_fruit].first;
  }
}
// Current fruit : 0
// This is a Banana
// Current fruit : 1
// This is an Orange
// Current fruit : 2
// This is an Apple