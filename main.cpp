#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>
using namespace std;

int main()
{
  cout << "\n================ 15) reverse =================\n";
  vector<int> v15 = {1, 2, 3, 4, 5};

  // reverse(): reverses elements inside a range
  reverse(v15.begin(), v15.end());

  cout << "Reversed: ";
  for (int x : v15)
    cout << x << " ";
  cout << "\n";

  cout << "\n================ 16) rotate =================\n";
  vector<int> v16 = {10, 20, 30, 40, 50};

  // rotate(first, middle, last):
  // Places element at 'middle' as the first element
  rotate(v16.begin(), v16.begin() + 2, v16.end());

  cout << "Rotated: ";
  for (int x : v16)
    cout << x << " ";
  cout << "\n";

  cout << "\n================ 17) next_permutation =================\n";
  vector<int> v17 = {1, 2, 3};

  // next_permutation(): generates next lexicographical permutation
  do
  {
    for (int x : v17)
      cout << x << " ";
    cout << "\n";
  } while (next_permutation(v17.begin(), v17.end()));

  cout << "\n================ 18) prev_permutation =================\n";
  vector<int> v18 = {3, 2, 1};

  // prev_permutation(): generates previous lexicographical permutation
  do
  {
    for (int x : v18)
      cout << x << " ";
    cout << "\n";
  } while (prev_permutation(v18.begin(), v18.end()));

  cout << "\n================ 19) remove_if =================\n";
  vector<int> v19 = {1, 2, 3, 4, 5, 6, 7, 8};

  // remove_if(): moves elements that do NOT match the condition to the front
  // Here we remove even numbers → return new logical end
  v19.erase(remove_if(v19.begin(), v19.end(),
                      [](int x)
                      { return x % 2 == 0; }),
            v19.end());

  cout << "After removing even numbers: ";
  for (int x : v19)
    cout << x << " ";
  cout << "\n";

  cout << "\n================ 20) unique =================\n";
  vector<int> v20 = {1, 1, 2, 2, 3, 3, 3, 4};

  // unique(): removes consecutive duplicates only
  auto ut = unique(v20.begin(), v20.end());
  v20.erase(ut, v20.end());

  cout << "Unique elements: ";
  for (int x : v20)
    cout << x << " ";
  cout << "\n";

  cout << "\n================ 21) partition =================\n";
  vector<int> v21 = {1, 2, 3, 4, 5, 6};

  // partition(): groups elements by predicate (order is not preserved)
  partition(v21.begin(), v21.end(),
            [](int x)
            { return x % 2 == 0; });

  cout << "Partition (evens first): ";
  for (int x : v21)
    cout << x << " ";
  cout << "\n";

  cout << "\n================ 22) stable_partition =================\n";
  vector<int> v22 = {1, 2, 3, 4, 5, 6};

  // stable_partition(): preserves relative order of elements
  stable_partition(v22.begin(), v22.end(),
                   [](int x)
                   { return x % 2 == 0; });

  cout << "Stable partition: ";
  for (int x : v22)
    cout << x << " ";
  cout << "\n";

  cout << "\n================ 23) nth_element =================\n";
  vector<int> v23 = {9, 1, 8, 2, 7, 3, 6, 4, 5};

  // nth_element(): rearranges so that nth element is in its final sorted position
  nth_element(v23.begin(), v23.begin() + 4, v23.end());

  cout << "5th smallest element = " << v23[4] << "\n";

  cout << "\n================ 24) partial_sort =================\n";
  vector<int> v24 = {9, 5, 7, 3, 8, 1, 2, 6};

  // partial_sort(): sort only first N elements
  partial_sort(v24.begin(), v24.begin() + 4, v24.end());

  cout << "First 4 sorted: ";
  for (int x : v24)
    cout << x << " ";
  cout << "\n";

  cout << "\n================ 25) iota =================\n";
  vector<int> v25(10);

  // iota(): fill with increasing values starting from X
  iota(v25.begin(), v25.end(), 100);

  cout << "iota: ";
  for (int x : v25)
    cout << x << " ";
  cout << "\n";

  cout << "\n================ 26) replace =================\n";
  vector<int> v26 = {1, 2, 3, 4, 5};

  // replace(): replace all occurrences of a value
  replace(v26.begin(), v26.end(), 3, 99);

  cout << "replace 3 → 99: ";
  for (int x : v26)
    cout << x << " ";
  cout << "\n";

  cout << "\n================ 27) transform =================\n";
  vector<int> v27 = {1, 2, 3, 4, 5};
  vector<int> out27(5);

  // transform(): apply function to each element
  transform(v27.begin(), v27.end(), out27.begin(),
            [](int x)
            { return x * x; });

  cout << "Squares: ";
  for (int x : out27)
    cout << x << " ";
  cout << "\n";

  cout << "\n================ 28) copy_if =================\n";
  vector<int> v28 = {1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> out28;

  // copy_if(): copy only elements matching predicate
  copy_if(v28.begin(), v28.end(), back_inserter(out28),
          [](int x)
          { return x > 4; });

  cout << "copy_if (>4): ";
  for (int x : out28)
    cout << x << " ";
  cout << "\n";

  cout << "\n================ 29) accumulate =================\n";
  vector<int> v29 = {10, 20, 30};

  // accumulate(): sum elements
  int total = accumulate(v29.begin(), v29.end(), 0);

  cout << "accumulate = " << total << "\n";

  cout << "\n================ 30) equal =================\n";
  vector<int> v30a = {1, 2, 3, 4};
  vector<int> v30b = {1, 2, 3, 4};

  // equal(): compares two ranges
  bool same = equal(v30a.begin(), v30a.end(), v30b.begin());

  cout << "equal result = " << boolalpha << same << "\n";

  return 0;
}
// ================ 15) reverse =================
// Reversed: 5 4 3 2 1

// ================ 16) rotate =================
// Rotated: 30 40 50 10 20

// ================ 17) next_permutation =================
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1

// ================ 18) prev_permutation =================
// 3 2 1
// 3 1 2
// 2 3 1
// 2 1 3
// 1 3 2
// 1 2 3

// ================ 19) remove_if =================
// After removing even numbers: 1 3 5 7

// ================ 20) unique =================
// Unique elements: 1 2 3 4

// ================ 21) partition =================
// Partition (evens first): 6 2 4 3 5 1

// ================ 22) stable_partition =================
// Stable partition: 2 4 6 1 3 5

// ================ 23) nth_element =================
// 5th smallest element = 5

// ================ 24) partial_sort =================
// First 4 sorted: 1 2 3 5 9 8 7 6

// ================ 25) iota =================
// iota: 100 101 102 103 104 105 106 107 108 109

// ================ 26) replace =================
// replace 3 ظْ 99: 1 2 99 4 5

// ================ 27) transform =================
// Squares: 1 4 9 16 25

// ================ 28) copy_if =================
// copy_if (>4): 5 6 7 8

// ================ 29) accumulate =================
// accumulate = 60

// ================ 30) equal =================
// equal result = true