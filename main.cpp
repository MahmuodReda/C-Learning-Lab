#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>
#include <random>
#include <string>

int main()
{

  // Initial vector
  std::vector<int> v = {5, 1, 4, 2, 8};
  std::cout << "Original vector: ";
  for (int x : v)
    std::cout << x << " ";
  std::cout << "\n\n";

  // ------------------------------------------------------------
  // 1) sort
  std::sort(v.begin(), v.end());
  std::cout << "1) sort: ";
  for (int x : v)
    std::cout << x << " ";
  std::cout << "\n";

  // 2) reverse
  std::reverse(v.begin(), v.end());
  std::cout << "2) reverse: ";
  for (int x : v)
    std::cout << x << " ";
  std::cout << "\n";

  // 3) stable_sort
  std::stable_sort(v.begin(), v.end());
  std::cout << "3) stable_sort: ";
  for (int x : v)
    std::cout << x << " ";
  std::cout << "\n";

  // ------------------------------------------------------------
  // SEARCHING ALGORITHMS
  // ------------------------------------------------------------

  // 4) find
  auto f1 = std::find(v.begin(), v.end(), 4);
  std::cout << "4) find(4): " << (f1 != v.end() ? "found" : "not found") << "\n";

  // 5) find_if
  auto f2 = std::find_if(v.begin(), v.end(), [](int x)
                         { return x > 3; });
  std::cout << "5) find_if(x>3): " << (f2 != v.end() ? std::to_string(*f2) : "none") << "\n";

  // 6) find_if_not
  auto f3 = std::find_if_not(v.begin(), v.end(), [](int x)
                             { return x < 4; });
  std::cout << "6) find_if_not(x<4): " << (f3 != v.end() ? std::to_string(*f3) : "none") << "\n";

  // ------------------------------------------------------------
  // COUNTING
  // ------------------------------------------------------------

  // 7) count
  int c1 = std::count(v.begin(), v.end(), 2);
  std::cout << "7) count(2): " << c1 << "\n";

  // 8) count_if
  int c2 = std::count_if(v.begin(), v.end(), [](int x)
                         { return x % 2 == 0; });
  std::cout << "8) count_if(even): " << c2 << "\n";

  // ------------------------------------------------------------
  // CONDITION CHECKS
  // ------------------------------------------------------------

  // 9) all_of
  std::cout << "9) all_of(>0): "
            << std::all_of(v.begin(), v.end(), [](int x)
                           { return x > 0; })
            << "\n";

  // 10) any_of
  std::cout << "10) any_of(>5): "
            << std::any_of(v.begin(), v.end(), [](int x)
                           { return x > 5; })
            << "\n";

  // 11) none_of
  std::cout << "11) none_of(==100): "
            << std::none_of(v.begin(), v.end(), [](int x)
                            { return x == 100; })
            << "\n";

  // ------------------------------------------------------------
  // MIN / MAX
  // ------------------------------------------------------------

  // 12) min_element
  auto mn = std::min_element(v.begin(), v.end());
  std::cout << "12) min_element: " << *mn << "\n";

  // 13) max_element
  auto mx = std::max_element(v.begin(), v.end());
  std::cout << "13) max_element: " << *mx << "\n";

  // 14) minmax_element
  auto mm = std::minmax_element(v.begin(), v.end());
  std::cout << "14) minmax_element: min=" << *mm.first << ", max=" << *mm.second << "\n";

  // ------------------------------------------------------------
  // MODIFY ELEMENTS
  // ------------------------------------------------------------

  // 15) for_each
  std::cout << "15) for_each (*2): ";
  std::for_each(v.begin(), v.end(), [](int &x)
                { x *= 2; });
  for (int x : v)
    std::cout << x << " ";
  std::cout << "\n";

  // 16) transform
  std::vector<int> t(v.size());
  std::transform(v.begin(), v.end(), t.begin(), [](int x)
                 { return x + 1; });
  std::cout << "16) transform (+1): ";
  for (int x : t)
    std::cout << x << " ";
  std::cout << "\n";

  // ------------------------------------------------------------
  // REMOVE / REMOVE_IF
  // ------------------------------------------------------------

  // 17) remove (logical remove — then erase)
  std::vector<int> rm = {1, 2, 3, 2, 4, 2, 5};
  rm.erase(std::remove(rm.begin(), rm.end(), 2), rm.end());
  std::cout << "17) remove(2): ";
  for (int x : rm)
    std::cout << x << " ";
  std::cout << "\n";

  // 18) remove_if
  std::vector<int> rm2 = {1, 2, 3, 4, 5, 6};
  rm2.erase(std::remove_if(rm2.begin(), rm2.end(), [](int x)
                           { return x % 2 == 0; }),
            rm2.end());
  std::cout << "18) remove_if(even): ";
  for (int x : rm2)
    std::cout << x << " ";
  std::cout << "\n";

  // ------------------------------------------------------------
  // UNIQUE
  // ------------------------------------------------------------

  // 19) unique
  std::vector<int> u = {1, 1, 2, 2, 2, 3, 3, 4};
  u.erase(std::unique(u.begin(), u.end()), u.end());
  std::cout << "19) unique: ";
  for (int x : u)
    std::cout << x << " ";
  std::cout << "\n";

  // ------------------------------------------------------------
  // BINARY SEARCH FAMILY
  // ------------------------------------------------------------

  std::vector<int> b = {1, 2, 2, 2, 3, 4, 5};
  std::cout << "\nBinary search vector: ";
  for (int x : b)
    std::cout << x << " ";
  std::cout << "\n";

  // 20) binary_search
  bool exists = std::binary_search(b.begin(), b.end(), 3);
  std::cout << "20) binary_search(3): " << exists << "\n";

  // 21) lower_bound
  auto lb = std::lower_bound(b.begin(), b.end(), 2);
  std::cout << "21) lower_bound(2): index=" << (lb - b.begin()) << "\n";

  // 22) upper_bound
  auto ub = std::upper_bound(b.begin(), b.end(), 2);
  std::cout << "22) upper_bound(2): index=" << (ub - b.begin()) << "\n";

  // ------------------------------------------------------------
  // MISMATCH
  // ------------------------------------------------------------

  // 23) mismatch
  std::vector<int> m1 = {1, 2, 3, 4};
  std::vector<int> m2 = {1, 2, 0, 4};
  auto mis = std::mismatch(m1.begin(), m1.end(), m2.begin());
  std::cout << "23) mismatch: first diff = ("
            << *mis.first << ", " << *mis.second << ")\n";

  // ------------------------------------------------------------
  // ACCUMULATE (sum)
  // ------------------------------------------------------------

  // 24) accumulate
  int sum = std::accumulate(b.begin(), b.end(), 0);
  std::cout << "24) accumulate(sum): " << sum << "\n";

  // ------------------------------------------------------------
  // FILL / GENERATE / RANDOM SHUFFLE
  // ------------------------------------------------------------

  // 25) fill
  std::vector<int> f(5);
  std::fill(f.begin(), f.end(), 7);
  std::cout << "25) fill with 7: ";
  for (int x : f)
    std::cout << x << " ";
  std::cout << "\n";

  // 26) generate
  int counter = 1;
  std::vector<int> g(5);
  std::generate(g.begin(), g.end(), [&counter]()
                { return counter++; });
  std::cout << "26) generate (1..5): ";
  for (int x : g)
    std::cout << x << " ";
  std::cout << "\n";

  // 27) shuffle
  std::random_device rd;
  std::mt19937 gen(rd());
  std::shuffle(g.begin(), g.end(), gen);
  std::cout << "27) shuffle: ";
  for (int x : g)
    std::cout << x << " ";
  std::cout << "\n";

  return 0;
}

// 1) sort: 1 2 4 5 8
// 2) reverse: 8 5 4 2 1
// 3) stable_sort: 1 2 4 5 8
// 4) find(4): found
// 5) find_if(x>3): 4
// 6) find_if_not(x<4): 4
// 7) count(2): 1
// 8) count_if(even): 3
// 9) all_of(>0): 1
// 10) any_of(>5): 1
// 11) none_of(==100): 1
// 12) min_element: 1
// 13) max_element: 8
// 14) minmax_element: min=1, max=8
// 15) for_each (*2): 2 4 8 10 16
// 16) transform (+1): 3 5 9 11 17
// 17) remove(2): 1 3 4 5
// 18) remove_if(even): 1 3 5
// 19) unique: 1 2 3 4

// Binary search vector: 1 2 2 2 3 4 5
// 20) binary_search(3): 1
// 21) lower_bound(2): index=1
// 22) upper_bound(2): index=4
// 23) mismatch: first diff = (3, 0)
// 24) accumulate(sum): 19
// 25) fill with 7: 7 7 7 7 7
// 26) generate (1..5): 1 2 3 4 5
// 27) shuffle: 4 1 5 2 3