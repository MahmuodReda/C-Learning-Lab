#include <iostream>
#include <thread>

void worker()
{
  std::cout << " [0]Hello from worker thread\n";
  std::cout << " [1]Hello from worker thread\n";
  std::cout << " [2]Hello from worker thread\n";
}

int main()
{
  std::thread t(worker); // create new thread

  std::cout << " [0]Hello from main thread\n";
  std::cout << " [1]Hello from main thread\n";
  std::cout << " [2]Hello from main thread\n";
  std::cout << " [3]Hello from main thread\n";

  t.join(); // wait for thread to finish  Error: terminate called without an active exception
  std::cout << " [4]Hello from main thread\n";
  return 0;
}

//  [0]Hello from main thread
//  [1]Hello from main thread
//  [0]Hello from worker thread
//  [1]Hello from worker thread
//  [2]Hello from worker thread
//  [2]Hello from main thread
//  [3]Hello from main thread
//  [4]Hello from main thread