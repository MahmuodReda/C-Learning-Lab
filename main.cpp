#include <cstdlib>
#include <thread>

int main()
{
  system("\"D:\\Mahmood Reda\\C++Learning-Lab\\.gitignore\"");  // Attempt to open a .gitignore file
  std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Wait for 1 second
  system("echo Hello, World!");                                 // Print Hello, World! to the console
  std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Wait for 1 second
  system("calc.exe");                                           // Open Calculator

  return 0;
}
