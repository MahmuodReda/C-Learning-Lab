#include <iostream>

// Regular function: works on a copy
void addTen(int x) {
    x += 10;
    std::cout << "Inside addTen (copy): x = " << x << "\n";
}

// Simulated method: works on original via reference
void addTenRef(int& x) {
    x += 10;
    std::cout << "Inside addTenRef (reference): x = " << x << "\n";
}

// Simulated method: works on original via pointer
void addTenPtr(int* x) {
    *x += 10;
    std::cout << "Inside addTenPtr (pointer): *x = " << *x << "\n";
}

int main() {
    int value = 5;

    // Call regular function (copy)
    addTen(value);
    std::cout << "After addTen: value = " << value << "\n";

    // Call reference-based function
    addTenRef(value);
    std::cout << "After addTenRef: value = " << value << "\n";

    int value2 = 5;
    // Call pointer-based function
    addTenPtr(&value2);
    std::cout << "After addTenPtr: value2 = " << value2 << "\n";

    return 0;
}

/*
| Feature              | Pass by Reference (int&) | Pass by Pointer (int*) |
|----------------------|---------------------------|--------------------------|
| Syntax               | addTenRef(x)              | addTenPtr(&x)            |
| Can be null?         | No                        | Yes                      |
| Needs dereferencing? | No                        | Yes (*)                  |
| Safety               | Safer                     | Requires null check      |
| Use case             | Direct access             | Flexible, dynamic access |
*/


// Inside addTen (copy): x = 15
// After addTen: value = 5
// Inside addTenRef (reference): x = 15
// After addTenRef: value = 15
// Inside addTenPtr (pointer): *x = 15
// After addTenPtr: value2 = 15