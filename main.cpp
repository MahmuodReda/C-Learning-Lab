#include <iostream>

int main()
{
  try
  {
    int x = 10, y = 0;
    if (y == 0)
    {
      throw std::runtime_error("Division by zero error");
    }
    int z = x / y;
    std::cout << "Result: " << z << std::endl;
  }

  catch (const std::runtime_error &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return 0;
}
// Error: Division by zero error