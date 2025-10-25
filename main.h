#ifndef TASKS_MENU_H
#define TASKS_MENU_H

/**
 * @file tasks_menu.h
 * @brief Declarations for Tasks 1..7 interactive menu program.
 *
 * This header exposes the task functions used by the combined menu program.
 * Each function is documented with Doxygen-style comments for automatic API
 * documentation generation.
 */

#include <string>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Print a simple ASCII table for a user-specified range.
 * @details Prompts user for start and end codes (0-255) and prints Dec, Hex,
 * Oct and Char (or a label for non-printable codes).
 */
void task_ascii_table();

/**
 * @brief Read three integers from the user and print the maximum.
 * @details Handles equal values by reporting that there is no single largest number.
 */
void task_max_of_three();

/**
 * @brief Print a right-angled triangle of '*' characters.
 * @details Prompts the user for the number of rows; prints rows from 1..n stars.
 */
void task_right_triangle();

/**
 * @brief Check whether a single-character input is a vowel.
 * @details Validates input is an alphabetic character; compares against
 * a, e, i, o, u in a case-insensitive manner.
 */
void task_check_vowel();

/**
 * @brief Print the multiplication table from 1 to 10.
 * @details Each product is printed in a grid-like row for readability.
 */
void task_multiplication_table();

/**
 * @brief Calculate and print the sum of digits of a user-entered integer.
 * @details Works with negative numbers by ignoring the sign character.
 */
void task_sum_digits();

/**
 * @brief Convert decimal to binary and binary to decimal interactively.
 * @details Uses a bitset for decimal->binary representation and std::stol
 * with base 2 for binary->decimal conversion. Validates binary input.
 */
void task_decimal_binary();

#ifdef __cplusplus
}
#endif

#endif // TASKS_MENU_H
