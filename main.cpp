#include <iostream>
#include <vector>
#include <deque>
#include <list>

int main()
{
  std::cout << "=== INTERNAL STRUCTURES ===\n";

  // ===========================
  // VECTOR (continuous memory)
  // ===========================
  /*
      VECTOR
      -------- Memory Layout --------
      [ 0 ][ 1 ][ 2 ][ 3 ][ 4 ][ 5 ]  ... contiguous

      Pros:
          - Fast random access (arr[i])
          - Very fast push_back
      Cons:
          - Slow insert/erase at beginning/middle (shift all elements)
  */
  std::vector<int> vec = {1, 2, 3};

  // ===========================
  // DEQUE (multiple blocks)
  // ===========================
  /*
      DEQUE
      ---------- Layout ----------
      Block1: [ a ][ b ][ c ]
      Block2: [ d ][ e ][ f ]
      Block3: [ g ][ h ][ i ]

      Fast push_front + push_back
      Random access: good but slower than vector
      Insert middle: expensive
  */
  std::deque<int> deq = {1, 2, 3};

  // ===========================
  // LIST (linked list)
  // ===========================
  /*
      LIST (doubly linked)
      -------- Layout --------
      [1] <-> [2] <-> [3] <-> [4]

      Pros:
          - Fast insert/erase at any position IF you already have an iterator
          - Stable memory (no reallocation)
      Cons:
          - No random access (no arr[i])
          - More memory per element (pointers)
          - Slow traversal (cache unfriendly)
  */
  std::list<int> lst = {1, 2, 3};

  std::cout << "\n=== INSERTIONS ===\n";

  // Insert at FRONT
  vec.insert(vec.begin(), 100); // BAD for vector (shifts all)
  deq.push_front(100);          // GOOD for deque
  lst.push_front(100);          // GOOD for list

  // Insert at MIDDLE
  vec.insert(vec.begin() + vec.size() / 2, 200);
  deq.insert(deq.begin() + deq.size() / 2, 200);
  auto it = lst.begin();
  std::advance(it, lst.size() / 2);
  lst.insert(it, 200); // GOOD (just pointer change)

  // Insert at END
  vec.push_back(300);
  deq.push_back(300);
  lst.push_back(300);

  std::cout << "vector: ";
  for (auto &x : vec)
    std::cout << x << " ";
  std::cout << "\n";

  std::cout << "deque : ";
  for (auto &x : deq)
    std::cout << x << " ";
  std::cout << "\n";

  std::cout << "list  : ";
  for (auto &x : lst)
    std::cout << x << " ";
  std::cout << "\n";

  std::cout << "\n=== ERASE FROM MIDDLE ===\n";

  // ERASE MIDDLE
  vec.erase(vec.begin() + vec.size() / 2); // slow
  deq.erase(deq.begin() + deq.size() / 2); // medium
  auto it2 = lst.begin();
  std::advance(it2, lst.size() / 2);
  lst.erase(it2); // fastest

  std::cout << "vector: ";
  for (auto &x : vec)
    std::cout << x << " ";
  std::cout << "\n";

  std::cout << "deque : ";
  for (auto &x : deq)
    std::cout << x << " ";
  std::cout << "\n";

  std::cout << "list  : ";
  for (auto &x : lst)
    std::cout << x << " ";
  std::cout << "\n";

  std::cout << "\n=== RANDOM ACCESS TEST ===\n";

  std::cout << "vector[2] = " << vec[2] << "\n"; // direct
  std::cout << "deque[2]  = " << deq[2] << "\n"; // direct
  // list has NO random access

  std::cout << "list[2]   = no direct access (must iterate)\n";

  return 0;
}

// === INTERNAL STRUCTURES ===

// === INSERTIONS ===
// vector: 100 1 200 2 3 300
// deque : 100 1 200 2 3 300
// list  : 100 1 200 2 3 300

// === ERASE FROM MIDDLE ===
// vector: 100 1 200 3 300
// deque : 100 1 200 3 300
// list  : 100 1 200 3 300

// === RANDOM ACCESS TEST ===
// vector[2] = 200
// deque[2]  = 200
// list[2]   = no direct access (must iterate)