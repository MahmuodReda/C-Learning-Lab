#include <iostream>   // Include the standard input/output library
#include <iomanip>    // Include the I/O manipulators library for formatting

// using namespace std;

int main() {
    int num1 = 42;

    // Print number with a width of 6 characters (right-aligned by default)
    std::cout << "Number: " << setw(6) << num1 << std::endl;

    double pi = 3.1415926535;

    // Print pi with 4 digits of precision
    std::cout << "Pi: " << setprecision(4) << pi << std::endl;

    double num2 = 123.456789;

    // Print number in scientific notation
    std::cout << "Sci: " << scientific << num2 << std::endl;

    int num3 = 42;

    // Print number in hexadecimal format
    std::cout << "Hex: " << hex << num3 << std::endl;

    // Print number in octal format
    std::cout << "Oct: " << oct << num3 << std::endl;

    // Print number in decimal format
    std::cout << "Dec: " << dec << num3 << std::endl;

    // Print number in hexadecimal format with base prefix (e.g., 0x2a)
    std::cout << hex << showbase << num3 << std::endl;

    return 0;
}
