#include <fstream>
#include <iostream>

int main()
{
  std::fstream f1("D:\\Mahmood Reda\\C++Learning-Lab\\log.txt", std::ios::in);
  if (!f1.is_open())
  {
    std::cerr << "Open failed\n";
    return 1;
  }

  std::fstream f2 = std::move(f1);

  std::cout << "f1 is open: " << f1.is_open() << std::endl;
  std::cout << "f2 is open: " << f2.is_open() << std::endl;

  return 0;
}
// f1 is open: 0
// f2 is open: 1