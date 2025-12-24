#include <fstream>
#include <iostream>

int main()
{
  // Open the file for both reading and writing
  std::fstream file(
      "D:\\Mahmood Reda\\C++Learning-Lab\\log.txt",
      std::ios::in | std::ios::out);

  // Check if the file was opened successfully
  if (!file.is_open())
    return 1;

  // Move the WRITE pointer (put pointer) to byte offset 6 from the beginning of the file
  file.seekp(6, std::ios::beg);

  // Write text starting from the current write position
  file << "gggg,";

  // Move the READ pointer (get pointer) to byte offset 5 from the beginning of the file
  file.seekg(5, std::ios::beg);

  // Get the current read position (in bytes from the beginning)
  std::streampos pos = file.tellg();
  std::cout << pos;

  // Read a line starting from the current read position
  std::string line;
  std::getline(file, line);

  // Print the read line
  std::cout << line << std::endl;

  // Close the file
  file.close();

  return 0;
}
