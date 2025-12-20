#include <iostream>
#include <thread>
#include <future>

/********************************************************************
 * CASE 7.1 : packaged_task WITHOUT arguments
 ********************************************************************/

// Function with no parameters
int task_no_args()
{
  std::cout << "[task_no_args] Running...\n";
  return 10;
}

/********************************************************************
 * CASE 7.2 : packaged_task WITH one argument
 ********************************************************************/

// Function with one argument
int task_one_arg(int x)
{
  std::cout << "[task_one_arg] Running with x = " << x << "\n";
  return x * 2;
}

/********************************************************************
 * CASE 7.3 : packaged_task WITH multiple arguments (different types)
 ********************************************************************/

// Function with multiple arguments of different types
double task_multi_args(int a, double b)
{
  std::cout << "[task_multi_args] Running with a = "
            << a << ", b = " << b << "\n";
  return a + b;
}

int main()
{
  /****************************************************************
   * CASE 7.1 : No arguments
   ****************************************************************/
  {
    // Wrap function inside packaged_task
    std::packaged_task<int()> task(task_no_args);

    // Get future associated with the task
    std::future<int> result = task.get_future();

    // Run task in a separate thread
    std::thread t(std::move(task));

    // Wait for result
    std::cout << "Result (no args): " << result.get() << "\n";

    t.join();
  }

  /****************************************************************
   * CASE 7.2 : One argument
   ****************************************************************/
  {
    // packaged_task signature must match function signature
    std::packaged_task<int(int)> task(task_one_arg);

    std::future<int> result = task.get_future();

    // Arguments are passed when thread starts
    std::thread t(std::move(task), 5);

    std::cout << "Result (one arg): " << result.get() << "\n";

    t.join();
  }

  /****************************************************************
   * CASE 7.3 : Multiple arguments (different types)
   ****************************************************************/
  {
    std::packaged_task<double(int, double)> task(task_multi_args);

    std::future<double> result = task.get_future();

    std::thread t(std::move(task), 3, 4.5);

    std::cout << "Result (multi args): " << result.get() << "\n";

    t.join();
  }

  return 0;
}

// Result (no args): [task_no_args] Running...
// 10
// Result (one arg): [task_one_arg] Running with x = 5
// 10
// Result (multi args): [task_multi_args] Running with a = 3, b = 4.5
// 7.5