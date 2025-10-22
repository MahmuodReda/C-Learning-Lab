#include <iostream>   // Include the standard input/output library
#include <iomanip>    // Include the I/O manipulators library for formatting

using namespace std;

int main() {
    // Declare variables used in arithmetic and comparison
    int a = 10, b = 3;

    // Arithmetic Operators
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "a / b = " << a / b << std::endl;
    std::cout << "a % b = " << a % b << std::endl;

    // Comparison Operators
    std::cout << "\nComparison Operators: " << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;

    // Logical Operators
    bool x = true, y = false;
    std::cout << "\nLogical Operators: " << std::endl;
    std::cout << "x && y: " << (x && y) << std::endl;
    std::cout << "x || y: " << (x || y) << std::endl;
    std::cout << "!x: " << (!x) << std::endl;

    // Bitwise Operators
    unsigned int num1 = 5, num2 = 3;
    std::cout << "\nBitwise Operators: " << std::endl;
    std::cout << "num1 & num2: " << (num1 & num2) << std::endl;
    std::cout << "num1 | num2: " << (num1 | num2) << std::endl;
    std::cout << "num1 ^ num2: " << (num1 ^ num2) << std::endl;
    std::cout << "~num1: " << (~num1) << std::endl;
    std::cout << "num1 << 1: " << (num1 << 1) << std::endl;
    std::cout << "num1 >> 1: " << (num1 >> 1) << std::endl;

    // Assignment Operators
    int c = 2;
    std::cout << "\nAssignment Operators: " << std::endl;
    std::cout << "c = 3: " << (c = 3) << std::endl;
    std::cout << "c += 2: " << (c += 2) << std::endl;

    return 0;
}
