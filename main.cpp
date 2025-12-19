#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

/*********************************************************************
 * DEMO: Race Condition vs Mutex vs Atomic
 *
 * This program compares three cases:
 * 1) No synchronization        -> Race condition (WRONG result)
 * 2) Mutex synchronization     -> Correct but slower
 * 3) Atomic variable           -> Correct and efficient
 *********************************************************************/

/*********************************************************************
 * CASE 1: NO SYNCHRONIZATION (Race Condition)
 *********************************************************************/

// Shared variable accessed by multiple threads
int counter = 0;

void increment()
{
  // Each thread tries to increment the same variable
  for (int i = 0; i < 100000; ++i)
  {
    // NOT atomic:
    // This operation = read + modify + write
    // Multiple threads can interleave here
    counter++;
  }
}

/*********************************************************************
 * CASE 2: MUTEX PROTECTION
 *********************************************************************/

// Shared variable protected by a mutex
int counter1 = 0;
std::mutex mtx;

void increment1()
{
  for (int i = 0; i < 100000; ++i)
  {
    // lock_guard locks the mutex at construction
    // and unlocks it automatically when leaving scope (RAII)
    std::lock_guard<std::mutex> lock(mtx);

    // Only ONE thread can execute this line at a time
    counter1++;
  }
}

/*********************************************************************
 * CASE 3: ATOMIC VARIABLE
 *********************************************************************/

// Atomic integer guarantees thread-safe operations
std::atomic<int> counter2{0};

void increment2()
{
  for (int i = 0; i < 100000; ++i)
  {
    // Atomic increment
    // Implemented using CPU atomic instructions
    counter2++;
  }
}

int main()
{
  /*****************************************************************
   * TEST 1: Race condition (no synchronization)
   *****************************************************************/
  {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    // Result is unpredictable and usually WRONG
    std::cout << "Final counter (no synchronization): "
              << counter << std::endl;
  }

  /*****************************************************************
   * TEST 2: Mutex-protected counter
   *****************************************************************/
  {
    std::thread t1(increment1);
    std::thread t2(increment1);

    t1.join();
    t2.join();

    // Result is correct: 200000
    std::cout << "Final counter1 (with mutex): "
              << counter1 << std::endl;
  }

  /*****************************************************************
   * TEST 3: Atomic counter
   *****************************************************************/
  {
    std::thread t1(increment2);
    std::thread t2(increment2);

    t1.join();
    t2.join();

    // load() safely reads the atomic value
    std::cout << "Final counter2 (with atomic): "
              << counter2.load() << std::endl;
  }

  return 0;
}

// Final counter (no synchronization): 127358
// Final counter1 (with mutex): 200000
// Final counter2 (with atomic): 200000