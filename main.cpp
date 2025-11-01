/**

* @file lambda_tasks.cpp
* @brief Combined program for Tasks 1–5 (Array operations using lambdas).
*
* The user selects a task number (1–5) to run:
* 1. Find maximum in array
* 2. Search for a number
* 3. Delete number
* 4. Merge two arrays
* 5. Separate even and odd numbers
     */

#include <iostream>
#include <vector>
#include <algorithm>

/**

* @brief Find the maximum number in an array using std::max_element and a lambda.
  */
  void task_find_max() {
  int n;
  std::cout << "Enter number of elements: ";
  std::cin >> n;
  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) std::cin >> arr[i];

  auto maxIt = std::max_element(arr.begin(), arr.end(), [](int a, int b) { return a < b; });
  std::cout << "Max element: " << *maxIt << '\n';
  }

/**

* @brief Search for a number in an array using std::find_if and a lambda.
  */
  void task_search_number() {
  int n, target;
  std::cout << "Enter number of elements: ";
  std::cin >> n;
  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) std::cin >> arr[i];

  std::cout << "Enter number to search: ";
  std::cin >> target;

  auto it = std::find_if(arr.begin(), arr.end(), [target](int x) { return x == target; });

  if (it != arr.end())
  std::cout << "Number found: " << *it << '\n';
  else
  std::cout << "Number not found.\n";
  }

/**

* @brief Delete all occurrences of a number using std::remove_if and a lambda.
  */
  void task_delete_number() {
  int n, del;
  std::cout << "Enter number of elements: ";
  std::cin >> n;
  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) std::cin >> arr[i];

  std::cout << "Enter number to delete: ";
  std::cin >> del;

  arr.erase(std::remove_if(arr.begin(), arr.end(), [del](int x) { return x == del; }), arr.end());

  std::cout << "Array after deletion: ";
  for (int v : arr) std::cout << v << " ";
  std::cout << '\n';
  }

/**

* @brief Merge two arrays using std::for_each and lambdas.
  */
  void task_merge_arrays() {
  int n1, n2;
  std::cout << "Enter size of first array: ";
  std::cin >> n1;
  std::vector<int> arr1(n1);
  for (int i = 0; i < n1; ++i) std::cin >> arr1[i];

  std::cout << "Enter size of second array: ";
  std::cin >> n2;
  std::vector<int> arr2(n2);
  for (int i = 0; i < n2; ++i) std::cin >> arr2[i];

  std::vector<int> merged;
  std::for_each(arr1.begin(), arr1.end(), [&merged](int v) { merged.push_back(v); });
  std::for_each(arr2.begin(), arr2.end(), [&merged](int v) { merged.push_back(v); });

  std::cout << "Merged array: ";
  for (int v : merged) std::cout << v << " ";
  std::cout << '\n';
  }

/**

* @brief Separate even and odd numbers into different vectors using a lambda.
  */
  void task_even_odd() {
  int n;
  std::cout << "Enter number of elements: ";
  std::cin >> n;
  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) std::cin >> arr[i];

  std::vector<int> even, odd;
  std::for_each(arr.begin(), arr.end(), [&even, &odd](int v) {
  (v % 2 == 0 ? even : odd).push_back(v);
  });

  std::cout << "Even numbers: ";
  for (int v : even) std::cout << v << " ";
  std::cout << "\nOdd numbers: ";
  for (int v : odd) std::cout << v << " ";
  std::cout << '\n';
  }

/**

* @brief Display a menu for lambda-based array tasks and execute the selected one.
  */
  int main() {
  while (true) {
  std::cout << "\n=== Lambda Array Tasks ===\n"
  << "1. Find maximum number\n"
  << "2. Search number\n"
  << "3. Delete number\n"
  << "4. Merge two arrays\n"
  << "5. Separate even/odd numbers\n"
  << "0. Exit\n"
  << "Select task (0_5): ";

   int choice;
   std::cin >> choice;
   if (!std::cin) break;

   switch (choice) {
       case 1: task_find_max(); break;
       case 2: task_search_number(); break;
       case 3: task_delete_number(); break;
       case 4: task_merge_arrays(); break;
       case 5: task_even_odd(); break;
       case 0: std::cout << "Exiting.\n"; return 0;
       default: std::cout << "Invalid option.\n"; break;
   }


  }
  return 0;
  }

// Commit: structured version of all 5 lambda array tasks with Doxygen comments and menu
