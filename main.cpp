#include <iostream>

int &f() {
    static int x = 0;     // static variable: lives for entire program
    std::cout << "Current x = " << x << std::endl;
    return x;              // return a reference to x (not address)
}

int main() {
    f() = 10;   // f() returns reference to x → means x = 10
    // ↳ "f()" behaves exactly like "x" because it's a reference
    // ↳ So this line stores 10 into x

    f() = 0;    // Again assigns 0 to the same x (through reference)
    // ↳ x = 0 now
}
