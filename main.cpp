/**
 * @file enum_example.cpp
 * @brief Demonstrates the difference between enum and enum class in C++,
 *        including how to print their names and numeric values.
 */

#include <iostream>
#include <string>

// ============================================================================
// Traditional enum (old-style)
// ============================================================================

enum Color {
    Red,      // Implicitly assigned 0
    Green,    // Implicitly assigned 1
    Blue      // Implicitly assigned 2
};

// ============================================================================
// Modern enum class (strongly-typed enum)
// ============================================================================

enum class Direction {
    North,    // 0
    East,     // 1
    South,    // 2
    West      // 3
};

// ============================================================================
// Function to convert enum class 'Direction' to string
// ============================================================================

std::string toString(Direction dir) {
    switch (dir) {
        case Direction::North: return "North";
        case Direction::East:  return "East";
        case Direction::South: return "South";
        case Direction::West:  return "West";
        default:               return "Unknown";
    }
}

// ============================================================================
// Optional: Overload operator<< to allow direct printing of Direction values
// ============================================================================
// std::ostream& operator<<(std::ostream& os, Direction dir) {
//     return os << toString(dir);
// }

// ============================================================================
// Main Function
// ============================================================================

int main() {
    // ---------------------------------------------------------------
    // Example 1: Using traditional enum
    // ---------------------------------------------------------------
    Color c = Green;

    std::cout << "=== Traditional enum ===" << std::endl;
    std::cout << "Color (numeric): " << c << std::endl;  // Prints 1
    // We can compare directly because old enums convert to int implicitly
    if (c == Green) {
        std::cout << "Color is Green" << std::endl;
    }

    // ---------------------------------------------------------------
    // Example 2: Using enum class
    // ---------------------------------------------------------------
    Direction dir = Direction::East;

    std::cout << "\n=== enum class ===" << std::endl;

    // Print numeric value by casting to int
    std::cout << "Direction (numeric): " << static_cast<int>(dir) << std::endl;

    // Print textual name using helper function
    std::cout << "Direction (string): " << toString(dir) << std::endl;

    // Or print directly using overloaded operator<<
    // std::cout << "Direction (using operator<<): " << dir << std::endl;

    // Example of a switch using enum class
    std::cout << "\nSwitch example: ";
    switch (dir) {
        case Direction::North:
            std::cout << "Moving North";
            break;
        case Direction::East:
            std::cout << "Moving East";
            break;
        case Direction::South:
            std::cout << "Moving South";
            break;
        case Direction::West:
            std::cout << "Moving West";
            break;
    }
    std::cout << std::endl;

    return 0;
}
