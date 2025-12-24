
#include <fstream>
#include <iostream>

int main()
{
  // Open file for writing (will overwrite existing content)
  std::fstream file("D:\\Mahmood Reda\\C++Learning-Lab\\log.txt", std::ios::out);
  if (!file.is_open())
  {
    std::cerr << "Failed to open file" << std::endl;
    return 1;
  }

  // Write text to file
  file << "Hello, C++ FileSystem!" << std::endl;
  file << "This is the second line." << std::endl;

  file.close();
  return 0;
}
