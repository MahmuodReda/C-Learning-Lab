#include <iostream>
#include <thread>
#include <future>
#include <string>

// Function executed asynchronously
// Takes two arguments of different types
// Returns a std::string result
std::string combine(int x, double y)
{
  // This line proves that the function
  // runs in a separate thread when using std::launch::async
  std::cout << "Executed" << std::endl;

  // Convert the result of x + y to string and return it
  return std::to_string(x + y);
}

int main()
{
  // std::async creates a TASK (not just a thread)
  // std::launch::async forces execution in a new thread immediately
  // combine(3, 4.5) will start running in parallel
  std::future<std::string> f =
      std::async(std::launch::async, combine, 3, 4.5);

  // This line executes immediately
  // It may appear before or after "Executed"
  // depending on thread scheduling
  std::cout << "Before get() " << std::endl;

  // f.get():
  // - Blocks until the async task finishes
  // - Retrieves the returned value from combine()
  // - Transfers ownership of the result
  std::cout << f.get() << std::endl; // Expected output: "7.500000"

  return 0;
}

// Before get()
// Executed
// 7.500000