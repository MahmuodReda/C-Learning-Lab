/********************************************************************
 * PART 2: std::shared_ptr with int
 * ------------------------------------------------------------------
 * Demonstrates:
 * - Heap allocation
 * - Shared ownership
 * - Reference counting
 ********************************************************************/

#include <iostream>
#include <memory>

int main()
{
  // Create shared int on HEAP
  std::shared_ptr<int> spInt1 = std::make_shared<int>(100);

  std::cout << "Value: " << *spInt1 << "\n";
  std::cout << "Use count: " << spInt1.use_count() << "\n";

  {
    // Copy shared_ptr (increase reference count)
    std::shared_ptr<int> spInt2 = spInt1;

    std::cout << "Use count after copy: "
              << spInt1.use_count() << "\n";

    *spInt2 = 200;
  } // spInt2 destroyed

  std::cout << "Use count after scope: "
            << spInt1.use_count() << "\n";
  std::cout << "Final value: " << *spInt1 << "\n";

  // Heap memory released when last shared_ptr is destroyed
  return 0;
}
