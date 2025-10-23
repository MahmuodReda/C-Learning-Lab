#include <iostream> // For input/output


int main() {
    int number;
    int option;

    // ======= Part 1: Using if-else =======
    std::cout << "Enter a number: ";
    std::cin >> number;

    // Check if the number is even or odd using if-else
    if (number % 2 == 0) {
        std::cout << "Using if-else: The number is even." << std::endl;
    } else {
        std::cout << "Using if-else: The number is odd." << std::endl;
    }

    // ======= Part 2: Using switch =======
    std::cout << "\nChoose an option:\n";
    std::cout << "1 - Print square of the number\n";
    std::cout << "2 - Print cube of the number\n";
    std::cout << "3 - Print double of the number\n";
    std::cout << "Enter your choice: ";
    std::cin >> option;

    // Perform operation based on user's choice using switch
    switch (option) {
        case 1:
            std::cout << "Using switch: Square = " << number * number << std::endl;
            break;
        case 2:
            std::cout << "Using switch: Cube = " << number * number * number << std::endl;
            break;
        case 3:
            std::cout << "Using switch: Double = " << number * 2 << std::endl;
            break;
        default:
            std::cout << "Using switch: Invalid option selected." << std::endl;
    }

    return 0;
}
