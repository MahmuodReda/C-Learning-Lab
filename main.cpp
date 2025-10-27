/**
 * @file pointer_reference_basics.cpp
 * @brief Covers all major pointer and reference concepts in C++ without classes.
 */

#include <iostream>
#include <memory> // For smart pointers

// Function to demonstrate function pointer
void greet() {
    std::cout << "Hello from greet()\n";
}

int main() {
    // Basic pointer
    int a = 10;
    int* p = &a;
    std::cout << "Basic pointer: *p = " << *p << "\n";

    // Pointer to pointer
    int** pp = &p;
    std::cout << "Pointer to pointer: **pp = " << **pp << "\n";

    // Reference
    int& ref = a;
    std::cout << "Reference: ref = " << ref << "\n";

    // Const reference (can't modify through cref)
    const int& cref = a;
    std::cout << "Const reference: cref = " << cref << "\n";

    // Const pointer (pointer itself is constant)
    int* const cp = &a;
    *cp = 20; // OK: can modify value
    std::cout << "Const pointer: *cp = " << *cp << "\n";

    // Pointer to const (can't modify value through pointer)
    const int* pc = &a;
    // *pc = 30; // Error: can't modify
    std::cout << "Pointer to const: *pc = " << *pc << "\n";

    // Function pointer
    void (*fp)() = greet;
    fp(); // Calls greet()

    // Smart pointer: unique_ptr
    std::unique_ptr<int> up = std::make_unique<int>(100);
    std::cout << "Smart pointer (unique_ptr): *up = " << *up << "\n";

    // Smart pointer: shared_ptr
    std::shared_ptr<int> sp = std::make_shared<int>(200);
    std::cout << "Smart pointer (shared_ptr): *sp = " << *sp << "\n";

    return 0;
}
