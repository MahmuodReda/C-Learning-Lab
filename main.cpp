#include <iostream>

int main() {
    const int val = 10;               // Original constant value
    const int* ptr = &val;            // Pointer to const int

    // Memory illustration (conceptual):
    // 0x01 -> val [10]   // actual memory address of val
    // 0x050 -> ptr [0x01] // ptr points to address of val

    // Unsafe cast: remove const qualifier
    // int* ptr2 = ptr;   //  Invalid: discards const qualifier
    int* ptr2 = const_cast<int*>(ptr); //  Legal but dangerous

    // Modify value through non-const pointer
    *ptr2 = 100; //  Undefined behavior: modifying a const object

    // Print addresses and values
    std::cout << "Address of val   : " << &val << "\n";
    std::cout << "Address in ptr   : " << ptr << "\n";
    std::cout << "Address in ptr2  : " << ptr2 << "\n";
    std::cout << "Value via ptr2   : " << *ptr2 << "\n";
    std::cout << "Value of val     : " << val << "\n";

    return 0;
}

// Address of val   : 0x9f3b7ffd1c
// Address in ptr   : 0x9f3b7ffd1c
// Address in ptr2  : 0x9f3b7ffd1c
// Value via ptr2   : 100
// Value of val     : 10