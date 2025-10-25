#include <iostream> // For input/output
#include <cctype>   // For tolower()

/**
 * @brief Checks whether a given character is a vowel or not.
 */
void checkIfVowel() {
    char letter;

    // Ask the user to enter a letter
    std::cout << "Enter a letter: ";
    std::cin >> letter;

    // Validate that the input is an alphabetic character
    if (letter >= 'A' && letter <= 'Z' || letter >= 'a' && letter <= 'z') {
        // Convert to lowercase to simplify comparison
        letter = std::tolower(letter);
    } else {
        // If input is not a letter, show error and exit
        std::cout << "Invalid input. Please enter an alphabetic character." << std::endl;
        return;
    }

    // Check if the letter is a vowel
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
        std::cout << "The letter '" << letter << "' is a vowel." << std::endl;
    } else {
        std::cout << "The letter '" << letter << "' is not a vowel." << std::endl;
    }
}

/**
 * @brief Main function that starts the program.
 */
int main() {
    checkIfVowel(); // Call the function to check for vowel
    return 0;
}
