#include <iostream>
#include <stack>
#include <queue>
#include <vector>

int main()
{

  /* ----------------------------------------------------
     1) STACK  (LIFO: Last In First Out)
     -----------------------------------------------------
     - Uses: recursion, undo history, parsers.
     - Default underlying container = deque.
  ----------------------------------------------------- */
  std::stack<int> st;

  st.push(10); // add on top
  st.push(20);
  st.push(30);

  std::cout << "--- STACK ---\n";
  std::cout << "Top: " << st.top() << "\n"; // 30

  st.pop(); // remove last inserted (30)

  std::cout << "Top after pop: " << st.top() << "\n"; // 20
  std::cout << "Size: " << st.size() << "\n\n";

  /* STACK SHAPE (before pop)
        top
         ↓
      | 30 |
      | 20 |
      | 10 |

     after pop:
      | 20 |
      | 10 |
  */

  /* ----------------------------------------------------
     2) QUEUE  (FIFO: First In First Out)
     -----------------------------------------------------
     - Uses: message queues, tasks, event handlers.
     - Default underlying container = deque.
  ----------------------------------------------------- */
  std::queue<int> q;

  q.push(1); // insert at back
  q.push(2);
  q.push(3);

  std::cout << "--- QUEUE ---\n";
  std::cout << "Front: " << q.front() << "\n"; // 1
  std::cout << "Back : " << q.back() << "\n";  // 3

  q.pop(); // remove 1 (first inserted)

  std::cout << "Front after pop: " << q.front() << "\n";
  std::cout << "Size: " << q.size() << "\n\n";

  /* QUEUE SHAPE (before pop)
     front → [1][2][3] ← back

     after pop:
     front → [2][3] ← back
  */

  /* ----------------------------------------------------
     3) PRIORITY QUEUE  (Max-Heap by default)
     -----------------------------------------------------
     - Largest element always at top.
     - Default underlying container = vector.
     - Uses: scheduling, graph algorithms (Dijkstra), etc.
  ----------------------------------------------------- */
  std::priority_queue<int> pq;

  pq.push(40);
  pq.push(10);
  pq.push(70);
  pq.push(50);

  std::cout << "--- PRIORITY QUEUE ---\n";
  std::cout << "Top (max): " << pq.top() << "\n"; // 70

  pq.pop(); // remove max element (70)

  std::cout << "Top after pop: " << pq.top() << "\n"; // 50
  std::cout << "Size: " << pq.size() << "\n\n";

  /* PRIORITY QUEUE SHAPE (as heap)
         (70)
        /    \
      50     40
     /
   10

     after pop:
         (50)
        /    \
      10     40
  */

  return 0;
}
// --- STACK ---
// Top: 30
// Top after pop: 20
// Size: 2

// --- QUEUE ---
// Front: 1
// Back : 3
// Front after pop: 2
// Size: 2

// --- PRIORITY QUEUE ---
// Top (max): 70
// Top after pop: 50
// Size: 3
