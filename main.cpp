#include <iostream>
#include <thread>
#include <future>

/*
  worker thread:
  - receives a promise
  - computes a value
  - stores the value in the promise
*/
void worker(std::promise<int> p)
{
  // Simulate heavy computation
  std::this_thread::sleep_for(std::chrono::seconds(2));
  int result = 21 * 2;

  // Put the result into the promise
  p.set_value(result);
}

int main()
{
  // 1) Create a promise object
  std::promise<int> prom;

  // 2) Extract the future from the promise
  std::future<int> fut = prom.get_future();

  // 3) Start a thread and move the promise into it
  std::thread t(worker, std::move(prom));

  // 4) Wait for the result (BLOCKING)
  int value = fut.get();

  std::cout << "Received value: " << value << std::endl;

  t.join();
  return 0;
}

// Main thread:   fut.get() --------------(waiting)--------------> value
// Worker thread:      compute ---> set_value()

// Received value: 42