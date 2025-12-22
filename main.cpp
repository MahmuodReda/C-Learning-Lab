#include <fstream>
#include <iostream>

int main()
{
  // Open file for reading
  std::fstream file1("D:\\Mahmood Reda\\C++Learning-Lab\\log.txt", std::ios::in);
  if (file1.is_open())
  {
    std::cout << "File opened for reading." << std::endl;
  }
  else
  {
    std::cerr << "Failed to open file." << std::endl;
    return 1;
  }

  // Read the first line from the file
  std::string line;
  std::getline(file1, line);
  std::cout << "First line: " << line << std::endl;

  // Close the file
  file1.close();
  if (!file1.is_open())
  {
    std::cout << "File closed successfully." << std::endl;
  }

  return 0;
}
