#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Helper to measure time of any function
template <typename Func>
long long measure(Func f)
{
  auto start = high_resolution_clock::now();
  f();
  auto end = high_resolution_clock::now();
  return duration_cast<nanoseconds>(end - start).count(); // nanoseconds
}

int main()
{
  const int N = 200000; // test size

  vector<int> vec;
  deque<int> deq;
  list<int> lst;

  // Fill containers
  for (int i = 0; i < N; i++)
  {
    vec.push_back(i);
    deq.push_back(i);
    lst.push_back(i);
  }

  cout << "=== INSERT FRONT ===\n";
  cout << "vector : "
       << measure([&]()
                  { vec.insert(vec.begin(), -1); })
       << " ns\n"; // result: 82700 ns  ← very slow

  cout << "deque  : "
       << measure([&]()
                  { deq.push_front(-1); })
       << " ns\n"; // result: 2600 ns   ← fast

  cout << "list   : "
       << measure([&]()
                  { lst.push_front(-1); })
       << " ns\n\n"; // result: 1900 ns   ← fastest

  cout << "=== INSERT MIDDLE ===\n";
  cout << "vector : "
       << measure([&]()
                  { vec.insert(vec.begin() + vec.size() / 2, -2); })
       << " ns\n"; // result: 26000 ns

  cout << "deque  : "
       << measure([&]()
                  { deq.insert(deq.begin() + deq.size() / 2, -2); })
       << " ns\n"; // result: 142700 ns

  cout << "list   : "
       << measure([&]()
                  { 
             auto it = lst.begin();
             advance(it, lst.size()/2);
             lst.insert(it, -2); })
       << " ns\n\n"; // result: 1143700 ns

  cout << "=== INSERT BACK ===\n";
  cout << "vector : "
       << measure([&]()
                  { vec.push_back(-3); })
       << " ns\n"; // result: 2800 ns

  cout << "deque  : "
       << measure([&]()
                  { deq.push_back(-3); })
       << " ns\n"; // result: 900 ns

  cout << "list   : "
       << measure([&]()
                  { lst.push_back(-3); })
       << " ns\n\n"; // result: 3500 ns

  cout << "=== ERASE MIDDLE ===\n";
  cout << "vector : "
       << measure([&]()
                  { vec.erase(vec.begin() + vec.size() / 2); })
       << " ns\n"; // result: 60700 ns

  cout << "deque  : "
       << measure([&]()
                  { deq.erase(deq.begin() + deq.size() / 2); })
       << " ns\n"; // result: 198400 ns

  cout << "list   : "
       << measure([&]()
                  { 
             auto it = lst.begin();
             advance(it, lst.size()/2);
             lst.erase(it); })
       << " ns\n\n"; // result: 1153600 ns

  cout << "=== RANDOM ACCESS (ELEMENT #10000) ===\n";
  cout << "vector : "
       << measure([&]()
                  { volatile int x = vec[10000]; })
       << " ns\n"; // result: 400 ns

  cout << "deque  : "
       << measure([&]()
                  { volatile int x = deq[10000]; })
       << " ns\n"; // result: 1100 ns

  cout << "list   : list has no random access\n";

  /* ---------------------------------------------------
     EXPLANATION & ASCII ILLUSTRATIONS
  ----------------------------------------------------

  INSERT FRONT:
  ------------------------
  VECTOR (slow: 82700 ns)
  Contiguous memory:
     [A][B][C][D][E]
  Insert FRONT → all elements shift:
     [X][A][B][C][D][E]  ← shift O(n)

  DEQUE (fast: 2600 ns)
  Segmented blocks:
     [Block1][Block2][Block3]
  push_front() adds small block → O(1)

  LIST (fastest: 1900 ns)
  Doubly linked:
     A<->B<->C<->D
  push_front() just changes head pointer → O(1)

  INSERT MIDDLE:
  ------------------------
  VECTOR (26000 ns)
     [0 1 2 | X | 3 4 5] → shift right O(n/2)

  DEQUE (142700 ns)
     [B1][B2][B3][B4] → internal block shifting → O(n/2)

  LIST (1143700 ns)
     traverse to middle → 100k steps → O(n), insert O(1)

  INSERT BACK:
  ------------------------
  VECTOR (2800 ns)
     amortized O(1) if capacity sufficient

  DEQUE (900 ns)
     back insert O(1) always

  LIST (3500 ns)
     pointer update O(1), slight allocation overhead

  ERASE MIDDLE:
  ------------------------
  VECTOR (60700 ns)
     shift left elements → O(n/2)

  DEQUE (198400 ns)
     block shifts → heavier than vector

  LIST (1153600 ns)
     traverse to middle → O(n), erase O(1)

  RANDOM ACCESS:
  ------------------------
  VECTOR (fastest: 400 ns)
     direct indexing → O(1)

  DEQUE (1100 ns)
     block lookup + index → still O(1)

  LIST (no random access)
     must traverse node-by-node → O(n)
  */

  return 0;
}

// === INSERT FRONT ===
// vector : 82700 ns
// deque  : 2600 ns
// list   : 1900 ns

// === INSERT MIDDLE ===
// vector : 26000 ns
// deque  : 142700 ns
// list   : 1143700 ns

// === INSERT BACK ===
// vector : 2800 ns
// deque  : 900 ns
// list   : 3500 ns

// === ERASE MIDDLE ===
// vector : 60700 ns
// deque  : 198400 ns
// list   : 1153600 ns

// === RANDOM ACCESS (ELEMENT #10000) ===
// vector : 400 ns
// deque  : 1100 ns
// list   : list has no random access