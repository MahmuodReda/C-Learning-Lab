/**
 * @file const_constexpr_define_examples.cpp
 * @brief Demonstrates the difference between const, constexpr, and #define
 *        when applied to variables and functions (no classes used).
 */

#include <iostream>
using namespace std;

//--------------------------------------------
// Example of #define (text substitution)
//--------------------------------------------
#define PI 3.1415926535                 ///< Macro constant (no type checking)
#define SQUARE(x) ((x) * (x))           ///< Macro function (expanded as text)

//--------------------------------------------
// Example of constexpr function
//--------------------------------------------
constexpr int add(int a, int b) {       ///< Compile-time addition
    return a + b;
}

//--------------------------------------------
// Example of const variable and const parameter
//--------------------------------------------
void printConst(const int value) {      ///< Function parameter marked const → read-only
    cout << "Constant value: " << value << endl;
}

//--------------------------------------------
// Example using all of them together
//--------------------------------------------
int main() {
    // const variable: runtime constant (value cannot be changed)
    const int maxValue = 10;            ///< Constant known at runtime

    // constexpr variable: compile-time constant
    constexpr int baseValue = 5;        ///< Constant known at compile-time

    // Compute using constexpr function (evaluated at compile-time)
    constexpr int sum = add(baseValue, 3);

    // Use #define macro to calculate area of a circle
    double radius = 2.0;
    double circleArea = PI * SQUARE(radius);  ///< Macro substitution: ((radius)*(radius))

    // Use const variable in runtime computation
    int scaled = maxValue * sum;        ///< Computed at runtime

    // Print results
    printConst(sum);
    printConst(scaled);
    cout << "Circle area using PI macro: " << circleArea << endl;

    //--------------------------------------------
    // Difference demonstration
    //--------------------------------------------
    // #define → text replacement, no scope, no type
    // const → runtime constant, has type and scope
    // constexpr → compile-time constant, faster and safer
    //--------------------------------------------


    return 0;
}

/**
 * @note
 *  - #define performs simple text substitution before compilation.
 *  - const guarantees immutability at runtime.
 *  - constexpr ensures compile-time evaluation for optimization.
 */

