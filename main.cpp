#include <iostream> // For input/output

// Declare three global integer variables to store user input
int a = 0, b = 0, c = 0;

/**
 * @brief Finds and prints the maximum number among three user-entered values.
 */
void findMaxOfThree() {
    // Ask the user to enter three numbers
    std::cout << "Enter first number: ";
    std::cin >> a;

    std::cout << "Enter second number: ";
    std::cin >> b;

    std::cout << "Enter third number: ";
    std::cin >> c;

    // Compare the three numbers to determine the largest
    if (a > b && a > c) {
        std::cout << "The largest number is: " << a << std::endl;
    } 
    else if (b > a && b > c) {
        std::cout << "The largest number is: " << b << std::endl;
    } 
    else if (c > a && c > b) {
        std::cout << "The largest number is: " << c << std::endl;
    } 
    else {
        // If no single number is strictly greater, then at least two are equal
        std::cout << "There is no single largest number (some numbers may be equal)." << std::endl;
    }     
}

/**
 * @brief Main function that starts the program.
 */
int main() {
    findMaxOfThree(); // Call the function to find and print the maximum
    return 0;
}
