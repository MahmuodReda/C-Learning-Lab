#include <iostream> // For std::cout
#include <thread>   // For std::thread
#include <chrono>   // For sleep_for, seconds, milliseconds
#include <random>
#include <iterator>
#include <algorithm>
#include <c++/15.2.0/array>
#include <c++/15.2.0/bits/chrono.h>
#include <c++/15.2.0/bits/std_thread.h>

void task3(int id)
{
  std::cout << "Task " << id << " is starting.\n"; // Task 1 is starting.
  std::random_device rd;                           // Obtain a random number from hardware
  std::mt19937 gen(rd());                          // Seed the generator
  std::uniform_int_distribution<int> dist(1, 5);   // Define the range
  std::cout << dist(gen) << " " << std::endl;

  auto start = std::chrono::steady_clock::now();                    // Record start time
  auto next = std::chrono::steady_clock::now();                     // Get current time
  std::cout << "next: " << next.time_since_epoch().count() << "\n"; // next: 514050732527200
  next += std::chrono::seconds(10);                                 // Schedule wake-up time 10 seconds later
  std::cout << "next: " << next.time_since_epoch().count() << "\n"; // next: 514060732527200

  std::this_thread::sleep_for(std::chrono::seconds(dist(gen))); // Sleep for a random duration between 1 and 5 seconds

  std::this_thread::sleep_until(next); // Sleep until the scheduled wake-up time

  std::cout << "Awake now!\n";                 // Awake now!
  auto end = std::chrono::steady_clock::now(); // Record end time
  auto elapsed = end - start;                  // Calculate elapsed time
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::seconds>(elapsed).count()
            << " seconds\n"; // Elapsed time: 10 seconds
}
int main()
{
  std::thread t1(task3, 1); // Start task3 in a new thread with id 1

  t1.join(); // Wait for thread t1 to finish
  // Program ends only after both threads have finished
  return 0;
}
// Task 1 is starting.
// 1
// next: 514050732527200
// next: 514060732527200
// Awake now!
// Elapsed time: 10 seconds