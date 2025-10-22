#include <iostream> // Include the standard input/output library

int main() {
    int number; // Declare an integer variable to store user input

    // Prompt the user to enter a number
    std::cout << "Please enter a number: ";
    std::cin >> number; // Read the number from user input

    // Display the entered number
    std::cout << "You entered: " << number << std::endl;

    // Display the number doubled
    std::cout << "Doubled: " << number * 2 << std::endl;

    // Display the number tripled
    std::cout << "Tripled: " << number * 3 << std::endl;

    // Display the number halved (integer division)
    std::cout << "Halved: " << number / 2 << std::endl;

    return 0; // Exit the program
}
