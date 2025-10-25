#include <iostream> // For input/output

// Declare global variables for row control
int totalRows = 0;
int currentRow = 0;
int starCount = 0;

/**
 * @brief Prints a right-angled triangle pattern using asterisks (*).
 *        The height of the triangle is entered by the user.
 */
void printRightAngleTriangle() {
    // Ask the user to enter the number of rows (height of triangle)
    std::cout << "Enter the number of rows: ";
    std::cin >> totalRows;

    // Outer loop: controls the number of rows
    for (currentRow = 0; currentRow < totalRows; currentRow++) {
        // Inner loop: prints stars in each row
        for (starCount = 0; starCount <= currentRow; starCount++) {
            std::cout << "*";
        }
        // Move to the next line after each row
        std::cout << std::endl;
    }
}

/**
 * @brief Main function that starts the program.
 */
int main() {
    printRightAngleTriangle(); // Call the function to print the triangle
    return 0;
}
