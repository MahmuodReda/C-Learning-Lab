/**
 * @file tasks_menu.cpp
 * @brief Combined program for Tasks 1..7 with interactive menu.
 *
 * The user selects a task number from the menu; the program runs the corresponding
 * function. Each function has a Doxygen-style comment so you can generate documentation.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <bitset>
#include <cctype>
#include <limits>

/**
 * @brief Print a simple ASCII table for a user-specified range.
 * @details Prompts user for start and end codes (0-255) and prints Dec, Hex, Oct and Char (or label).
 */
void task_ascii_table() {
    // Print table header
    std::cout << "ASCII Table\n";
    std::cout << "-----------------------------\n";
    std::cout << "Char\t|\tASCII\n";
    std::cout << "-----------------------------\n";

    // Loop through ASCII codes from 0 to 240
    for (int i = 0; i <= 240; ++i) {
        std::cout << " Char " << char(i) << "\t|\t ASCII  " << i << std::endl;
    }
}

/**
 * @brief Read three integers from the user and print the maximum.
 * @details Handles equal values by reporting that there is no single largest number.
 */
void task_max_of_three() {
    int a=0, b=0, c=0;
    std::cout << "Enter first number: ";  if (!(std::cin >> a)) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); return; }
    std::cout << "Enter second number: "; if (!(std::cin >> b)) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); return; }
    std::cout << "Enter third number: ";  if (!(std::cin >> c)) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); return; }

    if (a > b && a > c) std::cout << "The largest number is: " << a << '\n';
    else if (b > a && b > c) std::cout << "The largest number is: " << b << '\n';
    else if (c > a && c > b) std::cout << "The largest number is: " << c << '\n';
    else std::cout << "There is no single largest number (some numbers may be equal)." << '\n';
}

/**
 * @brief Print a right-angled triangle of '*' characters.
 * @details Prompts the user for the number of rows; prints rows from 1..n stars.
 */
void task_right_triangle() {
    int rows = 0;
    std::cout << "Enter the number of rows: ";
    if (!(std::cin >> rows)) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); return; }
    for (int i = 1; i <= rows; ++i) {
        for (int j = 0; j < i; ++j) std::cout << '*';
        std::cout << '\n';
    }
}

/**
 * @brief Check whether a single-character input is a vowel.
 * @details Validates input is an alphabetic character; compares against a,e,i,o,u (case-insensitive).
 */
void task_check_vowel() {
    char letter;
    std::cout << "Enter a letter: ";
    if (!(std::cin >> letter)) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); return; }

    if (!std::isalpha(static_cast<unsigned char>(letter))) {
        std::cout << "Invalid input. Please enter an alphabetic character.\n";
        return;
    }
    letter = static_cast<char>(std::tolower(static_cast<unsigned char>(letter)));
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
        std::cout << "The letter '" << letter << "' is a vowel.\n";
    else
        std::cout << "The letter '" << letter << "' is not a vowel.\n";
}

/**
 * @brief Print the multiplication table from 1 to 10.
 * @details Each product is printed in a grid-like row for readability.
 */
void task_multiplication_table() {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            std::cout << std::setw(2) << i << "x" << std::setw(2) << j << "=" << std::setw(3) << (i*j) << "  ";
        }
        std::cout << '\n';
    }
}

/**
 * @brief Calculate and print the sum of digits of a user-entered integer.
 * @details Works with negative numbers by ignoring the sign.
 */
void task_sum_digits() {
    int number;
    std::cout << "Enter a number: ";
    if (!(std::cin >> number)) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); return; }
    std::string s = std::to_string(number);
    int sum = 0;
    for (char ch : s) {
        if (std::isdigit(static_cast<unsigned char>(ch))) sum += (ch - '0');
    }
    std::cout << "Sum of digits = " << sum << '\n';
}

/**
 * @brief Convert decimal to binary and binary to decimal interactively.
 * @details Uses 8-bit bitset for decimal->binary and std::stoi with base 2 for binary->decimal.
 */
void task_decimal_binary() {
    int decimal;
    std::string binary;
    std::cout << "Enter a decimal number: ";
    if (!(std::cin >> decimal)) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); return; }
    std::bitset<16> bset(decimal); // choose 16 bits to be a bit more flexible
    std::cout << "Decimal number: " << decimal << '\n';
    std::cout << "Binary representation: " << bset.to_string() << '\n';

    std::cout << "Enter a binary number: ";
    if (!(std::cin >> binary)) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); return; }
    // validate binary string
    for (char ch : binary) {
        if (ch != '0' && ch != '1') {
            std::cout << "Invalid binary input.\n";
            return;
        }
    }
    try {
        int dec = static_cast<int>(std::stol(binary, nullptr, 2));
        std::cout << "Decimal representation: " << dec << '\n';
    } catch (...) {
        std::cout << "Conversion error (number too large?)\n";
    }
}

/**
 * @brief Display menu and run selected task until user chooses to exit.
 */
int main() {
    while (true) {
        std::cout << "\n=== Tasks Menu ===\n"
                  << "1. ASCII table\n"
                  << "2. Maximum of three values\n"
                  << "3. RIGHT angle triangle\n"
                  << "4. Check if letter is vowel\n"
                  << "5. Multiplication table\n"
                  << "6. Sum digits of integer\n"
                  << "7. Decimal <-> Binary conversion\n"
                  << "0. Exit\n"
                  << "Select a task (0-7): ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 0 and 7.\n";
            continue;
        }

        switch (choice) {
            case 0: std::cout << "Exiting.\n"; return 0;
            case 1: task_ascii_table(); break;
            case 2: task_max_of_three(); break;
            case 3: task_right_triangle(); break;
            case 4: task_check_vowel(); break;
            case 5: task_multiplication_table(); break;
            case 6: task_sum_digits(); break;
            case 7: task_decimal_binary(); break;
            default: std::cout << "Please choose a valid option (0-7).\n"; break;
        }
    }
    return 0;
}
