#include <iostream>

int getValue() {
    // Returns a prvalue (temporary integer with no name)
    return 5;
}

// Overload to detect lvalue
void inspect(int& x) {
    std::cout << "[inspect] Lvalue reference called, value = " << x << "\n";
}

// Overload to detect rvalue
void inspect(int&& x) {
    std::cout << "[inspect] Rvalue reference called, value = " << x << "\n";
}

int main() {

    std::cout << "===== LVALUE EXAMPLE =====\n";
    int a = 10;   // 'a' is an lvalue (has name + address)
    inspect(a);   // Calls inspect(int&)

    std::cout << "\n===== RVALUE EXAMPLE =====\n";
    inspect(20);  // 20 is an rvalue → calls inspect(int&&)

    std::cout << "\n===== BINDING RVALUE TO RVALUE REFERENCE =====\n";
    int&& tempRef = getValue();
    /*
        getValue() returns a prvalue (temporary).
        int&& can bind to that temporary.
        After binding, tempRef becomes an LVALUE (because it has a name now).
    */
    std::cout << "tempRef = " << tempRef << "\n"; // prints 5

    std::cout << "\n===== WHAT THE COMPILER SEES =====\n";
    // These two are identical in semantics:
    int&& x1 = getValue();     // programmer version
    int&& x2 = int(5);         // what compiler interprets (temporary int)

    std::cout << "x1 = " << x1 << ", x2 = " << x2 << "\n";

    std::cout << "\n===== XVALUE DEMO (std::move) =====\n";
    int b = 50;
    inspect(std::move(b));  // move(b) turns b into an xvalue (expiring value)

    return 0;
}

/*
==========================================
               MEMORY DIAGRAM
==========================================

Stack:
---------------------------------------------------------
| a (lvalue) -> value: 10                                 |
| b (lvalue) -> value: 50                                 |
| tempRef (lvalue name but refers to Rvalue) -> 5         |
| x1 (lvalue name but refers to Rvalue) -> 5              |
| x2 (lvalue name but refers to Rvalue) -> 5              |
---------------------------------------------------------

Temporaries Area (compiler-managed):
---------------------------------------------------------
| temporary #1: result of getValue() → 5                  |
| temporary #2: literal 20 (rvalue)                       |
| temporary #3: result of std::move(b) → xvalue of b      |
---------------------------------------------------------

Notes:
1. getValue() returns a prvalue (rvalue with no name).
2. int&& binds to rvalues only.
*/