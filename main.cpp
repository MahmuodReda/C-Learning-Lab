#include <iostream>  // For input/output
#include <bitset>    // For binary conversion
#include <string>    // For string input

/**
 * @brief Converts a decimal number to binary and a binary string to decimal.
 */
void convertDecimalBinary() {
    int decimal;
    std::string binary;

    // Convert decimal to binary
    std::cout << "Enter a decimal number: ";
    std::cin >> decimal;

    std::bitset<8> binaryRep(decimal); // 8-bit representation
    std::cout << "Decimal number: " << decimal << std::endl;
    std::cout << "Binary representation: " << binaryRep << std::endl;

    // Convert binary to decimal
    std::cout << "Enter a binary number: ";
    std::cin >> binary;

    int decimalRep = std::stoi(binary, nullptr, 2); // Convert base-2 string to int
    std::cout << "Decimal representation: " << decimalRep << std::endl;
}

/**
 * @brief Main function that starts the program.
 */
int main() {
    convertDecimalBinary(); // Call the function to perform conversions
    return 0;
}
