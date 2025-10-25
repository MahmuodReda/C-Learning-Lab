#include <iostream>  // For input/output
#include <string>    // For std::to_string

/**
 * @brief Calculates and prints the sum of digits of a user-entered integer.
 */
void sumDigitsOfInteger() {
    int number;

    // Ask the user to enter an integer
    std::cout << "Enter a number: ";
    std::cin >> number;

    // Convert the integer to a string
    std::string number_str = std::to_string(number);

    // Calculate the sum of digits using string manipulation
    int sum = 0;
    for (char digit : number_str) {
        sum += digit - '0'; // Convert character to integer
    }

    // Output the result
    std::cout << "Sum of digits = " << sum << std::endl;
}

/**
 * @brief Main function that starts the program.
 */
int main() {
    sumDigitsOfInteger(); // Call the function to calculate digit sum
    return 0;
}
