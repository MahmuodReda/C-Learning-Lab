/**
 * @file null_vs_nullptr.cpp
 * @brief Demonstrates the difference between NULL and nullptr in function overloading.
 */

#include <iostream>

/**
 * @brief Called when an integer is passed.
 * @param x Integer value
 */
void identify(int x) {
    std::cout << "Called identify(int)\n";
}

/**
 * @brief Called when a pointer to int is passed.
 * @param x Pointer to int
 */
void identify(int* x) {
    std::cout << "Called identify(int*)\n";
}
int main() {
    // Ambiguous: NULL is treated as 0 (int), not a pointer
    identify(NULL);      // Warning: passing NULL to int

    // Clear: nullptr is a null pointer → calls pointer version
    identify(nullptr);   // No warning
    return 0;
}

// main.cpp: In function 'int main()':
// main.cpp:25:18: warning: passing NULL to non-pointer argument 1 of 'void identify(int)' [-Wconversion-null]
//      identify(NULL);      // Warning: passing NULL to int
//                   ^
// Called identify(int)
// Called identify(int*)