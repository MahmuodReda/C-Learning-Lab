/********************************************************************
 * std::weak_ptr
 * ------------------------------------------------------------------
 * PURPOSE:
 * - Non-owning smart pointer
 * - Observes an object managed by std::shared_ptr
 * - Does NOT increase reference count
 * - Prevents cyclic ownership (memory leaks)
 ********************************************************************/

#include <iostream>
#include <memory>

/********************************************************************
 * PART 1: weak_ptr with int
 ********************************************************************/
int main()
{
  // Create shared ownership of int
  std::shared_ptr<int> sp = std::make_shared<int>(42);

  // Create weak_ptr observing the same object
  std::weak_ptr<int> wp = sp;

  std::cout << "shared_ptr use_count: " << sp.use_count() << "\n";

  // weak_ptr does NOT increase reference count
  // use_count is still 1

  // Check if object still exists
  if (!wp.expired())
  {
    // Convert weak_ptr -> shared_ptr safely
    std::shared_ptr<int> locked = wp.lock();

    std::cout << "Value via weak_ptr: " << *locked << "\n";
    std::cout << "use_count after lock: "
              << locked.use_count() << "\n";
  }

  // Destroy shared_ptr (owner)
  sp.reset();

  // Now the object is destroyed
  if (wp.expired())
  {
    std::cout << "Object already destroyed\n";
  }

  return 0;
}
