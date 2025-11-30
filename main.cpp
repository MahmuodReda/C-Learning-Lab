#include <string>
#include <iostream>

/**
 * @brief Demonstrates common std::string operations.
 *
 * This example covers:
 * - Character access
 * - Modification (append, replace, erase, insert, resize)
 * - Substring search and extraction
 * - C-style string conversion
 * - Checking length and emptiness
 */
int main()
{
    // ------------------------------------------------------------
    // Create a string
    // ------------------------------------------------------------
    std::string str = "Hello, World!";

    /** @brief Accessing individual characters */
    char firstChar = str[0];
    char lastChar = str[str.length() - 1];

    // ------------------------------------------------------------
    // Modifying the string
    // ------------------------------------------------------------
    str += " Welcome!"; // Append using operator+=

    std::cout << "After first append: " << str << std::endl;

    str.append(" How are you?"); // Append using append()

    std::cout << "After second append: " << str << std::endl;
    // Now: "Hello, World! Welcome! How are you?"

    // ------------------------------------------------------------
    // Finding a substring
    // ------------------------------------------------------------
    size_t found = str.find("World");
    if (found != std::string::npos)
    {
        std::cout << "Substring 'World' found at index " << found << std::endl;
    }

    // ------------------------------------------------------------
    // Replacing part of the string
    // Replace 5 characters starting at 'found'
    // ------------------------------------------------------------
    str.replace(found, 5, "Universe");
    // Now: "Hello, Universe! Welcome! How are you?"

    std::cout << "After replacement: " << str << std::endl;
    // ------------------------------------------------------------
    // Removing part of the string
    // Erase 7 characters starting at index 0
    // ------------------------------------------------------------
    str.erase(0, 7);
    std::cout << "After erasure: " << str << std::endl;
    // Now: "Universe! Welcome! How are you?"

    // ------------------------------------------------------------
    // Getting string length
    // ------------------------------------------------------------
    size_t length = str.length();

    std::cout << "String length: " << length << std::endl;
    // ------------------------------------------------------------
    // Check if empty
    // ------------------------------------------------------------
    bool isEmpty = str.empty();

    std::cout << "Is string empty? " << (isEmpty ? "Yes" : "No") << std::endl;
    // ------------------------------------------------------------
    // Convert to C-style string
    // ------------------------------------------------------------
    const char *cstr = str.c_str();

    std::cout << "C-style string: " << cstr << std::endl;
    // ------------------------------------------------------------
    // Extract substring
    // Substring starting at index 0, length = 8
    // ------------------------------------------------------------
    std::string substr = str.substr(0, 8);
    // substr = "Universe"
    std::cout << "Extracted substring: " << substr << std::endl;

    // ------------------------------------------------------------
    // Insert into the string
    // Insert " there" at index 5
    // ------------------------------------------------------------
    str.insert(5, " there");
    // Now: "Unive thereerse! Welcome! How are you?"

    std::cout << "After insertion: " << str << std::endl;
    // ------------------------------------------------------------
    // Resize the string to 10 characters
    // ------------------------------------------------------------
    str.resize(10);
    // Now: "Unive ther"

    std::cout << "After resizing: " << str << std::endl;
    return 0;
}

// After first append: Hello, World! Welcome!
// After second append: Hello, World! Welcome! How are you?
// Substring 'World' found at index 7
// After replacement: Hello, Universe! Welcome! How are you?
// After erasure: Universe! Welcome! How are you?
// String length: 31
// Is string empty? No
// C-style string: Universe! Welcome! How are you?
// Extracted substring: Universe
// After insertion: Unive thererse! Welcome! How are you?
// After resizing: Unive ther