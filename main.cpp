/********************************************************************
 * PART 1: std::unique_ptr with int
 * ------------------------------------------------------------------
 * Demonstrates:
 * - Heap allocation of a primitive type (int)
 * - Exclusive ownership
 * - Move semantics
 * - Automatic deletion
 ********************************************************************/

#include <iostream>
#include <memory>

int main()
{
  // Allocate int on HEAP, owned by unique_ptr
  std::unique_ptr<int> upInt = std::make_unique<int>(10);

  // Access the value
  std::cout << "Value via unique_ptr<int>: " << *upInt << "\n";

  // Transfer ownership using std::move
  std::unique_ptr<int> upInt2 = std::move(upInt);

  // After move, upInt no longer owns the resource
  if (!upInt)
  {
    std::cout << "upInt is nullptr after move\n";
  }

  // Modify value through new owner
  *upInt2 = 20;
  std::cout << "Modified value: " << *upInt2 << "\n";

  // Memory is released automatically when upInt2 goes out of scope
  return 0;
}
