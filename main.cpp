#include <array>
#include <iostream>
#include <string>
#include <cstdlib> // for std::system

int main()
{
  using commands = std::array<std::string, 4>;

  // Standard C++ initialization
  commands keyboard = {
      "cat /etc/hosts",
      "cat /etc/issue",
      "cat /etc/os-release",
      "cat /etc/fstab"};

  for (const auto &command : keyboard)
  {
    if (!command.empty())
    {
      std::cout << std::string(100, '-') << std::endl;
      std::cout << command << std::endl;
    }
    std::system(command.c_str());
  }

  return 0;
}
