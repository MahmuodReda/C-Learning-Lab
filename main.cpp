#include <iostream> // For std::cout
#include <thread>   // For std::thread
#include <chrono>   // For sleep_for, seconds, milliseconds

/*********************************************************************
 * Example 3: Using sleep_for with threads
 *
 * This example demonstrates:
 * 1) Creating multiple threads
 * 2) Pausing thread execution using sleep_for
 * 3) Observing interleaved output between threads
 *********************************************************************/

//---------------------------------------------------------------
// task()
// A simple task that:
// - Prints a start message
// - Sleeps for 1 second
// - Prints a finish message
//---------------------------------------------------------------
void task(int id)
{
  // Print which thread has started
  std::cout << "Thread " << id << " started\n";

  // Pause the current thread for 1 second
  std::this_thread::sleep_for(std::chrono::seconds(1));

  // Print when the thread finishes execution
  std::cout << "Thread " << id << " finished\n";
}

//---------------------------------------------------------------
// task2()
// A longer task that:
// - Runs a loop 10 times
// - Sleeps for 100 ms in each iteration
// - Prints progress information
//---------------------------------------------------------------
void task2(int id)
{
  for (int i = 0; i < 10; i++)
  {
    // Pause the current thread for 100 milliseconds
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Print current progress of the thread
    std::cout << "Thread " << id << " working: " << i << "\n";
  }
}

int main()
{
  // Create first thread running task()
  std::thread t1(task, 1);

  // Create second thread running task2()
  std::thread t2(task2, 2);

  // Wait for t1 to finish execution
  // join() blocks the main thread until t1 completes
  t1.join();

  // Wait for t2 to finish execution
  t2.join();

  // Program ends only after both threads have finished
  return 0;
}
// Thread 1 started
// Thread 2 working: 0
// Thread 2 working: 1
// Thread 2 working: 2
// Thread 2 working: 3
// Thread 2 working: 4
// Thread 2 working: 5
// Thread 2 working: 6
// Thread 2 working: 7
// Thread 2 working: 8
// Thread 1 finished
// Thread 2 working: 9