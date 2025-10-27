/**
 * @file overloaded_multiplication.cpp
 * @brief Demonstrates function overloading using int and float parameters.
 */

#include <iostream>

// Global variable to store the result
float result = 0;

/**
 * @brief Multiplies two integers.
 * @param a First integer
 * @param b Second integer
 * @return Product of a and b
 */
float multiply(int a, int b) {
    std::cout << "[int version called]\n";
    return a * b;
}

/**
 * @brief Multiplies two floating-point numbers.
 * @param x First float
 * @param y Second float
 * @return Product of x and y
 */
float multiply(float x, float y) {
    std::cout << "[float version called]\n";
    return x * y;
}

/**
 * @brief Main function to test overloaded multiply functions.
 */
int main() {
    // Call the integer version
    result = multiply(2, 3);
    std::cout << "Result (int): " << result << "\n";

    // Call the float version
    result = multiply(1.6f, 2.1f);
    std::cout << "Result (float): " << result << "\n";

    return 0;
}
