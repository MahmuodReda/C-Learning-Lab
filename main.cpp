/**
 * @file lambda_capture_demo_full.cpp
 * @brief Comprehensive demonstration of all 9 C++ lambda capture types.
 * @details Includes code, explanations, and a final ASCII diagram showing memory layout.
 * @author Mahmood
 * @date 2025-10-30
 */

#include <iostream>
using namespace std;

//──────────────────────────── CASE 1 ────────────────────────────
/**
 * @brief Lambda without capture
 * @details Basic lambda that does not access external variables.
 */
void case1_noCapture() {
    auto add = [](int a, int b) {
        return a + b;
    };
    cout << "[1] No Capture → " << add(3, 4) << endl;
}

//──────────────────────────── CASE 2 ────────────────────────────
/**
 * @brief Capture by Value
 * @details Copies variable values at definition time. Changes outside do not affect captured copies.
 */
void case2_byValue() {
    int x = 10;
    auto f = [x]() { return x + 5; };
    x = 20;
    cout << "[2] Capture by Value → " << f() << " (x=10 copy used)\n";
}

//──────────────────────────── CASE 3 ────────────────────────────
/**
 * @brief Capture by Value + mutable
 * @details Allows modification of the internal copy inside the lambda.
 */
void case3_mutableValue() {
    int x = 10;
    auto f = [x]() mutable {
        x += 5;
        return x;
    };
    cout << "[3] Capture by Value + mutable → " << f() << " (x outer still 10)\n";
}

//──────────────────────────── CASE 4 ────────────────────────────
/**
 * @brief Capture by Reference
 * @details Modifies original variable directly through reference.
 */
void case4_byReference() {
    int x = 10;
    auto f = [&x]() {
        x += 5;
        return x;
    };
    f();
    cout << "[4] Capture by Reference → " << x << " (modified to 15)\n";
}

//──────────────────────────── CASE 5 ────────────────────────────
/**
 * @brief Capture by Pointer
 * @details Pointer is copied, but it still points to the same memory address.
 */
void case5_byPointer() {
    int x = 10;
    int* ptr = &x;
    auto f = [ptr]() {
        *ptr += 5;
        return *ptr;
    };
    f();
    cout << "[5] Capture by Pointer → " << x << " (modified via *ptr)\n";
}

//──────────────────────────── CASE 6 ────────────────────────────
/**
 * @brief Capture All by Value [=]
 * @details Captures all visible variables by value (copies).
 */
void case6_allByValue() {
    int a = 1, b = 2;
    auto f = [=]() { return a + b; };
    cout << "[6] Capture All by Value [=] → " << f() << endl;
}

//──────────────────────────── CASE 7 ────────────────────────────
/**
 * @brief Capture All by Reference [&]
 * @details Captures all visible variables by reference.
 */
void case7_allByRef() {
    int a = 1, b = 2;
    auto f = [&]() {
        a += 3;
        b += 4;
        return a + b;
    };
    cout << "[7] Capture All by Reference [&] → " << f() << " (a,b changed)\n";
}

//──────────────────────────── CASE 8 ────────────────────────────
/**
 * @brief Mixed Capture (by value and by reference)
 * @details Demonstrates partial capture: [=, &b] means all by value except b by reference.
 */
void case8_mixed() {
    int a = 1, b = 2, c = 3;
    auto f = [=, &b]() mutable {
        a += 10;
        b += 20;
        return a + b + c;
    };
    cout << "[8] Mixed Capture [=, &b] → " << f() << " (b modified)\n";
}

//──────────────────────────── CASE 9 ────────────────────────────
/**
 * @brief Capture with pointers and references combined
 * @details Shows a hybrid scenario with pointer and reference together.
 */
void case9_pointerAndRef() {
    int x = 10, y = 20;
    int* p = &x;
    auto f = [=, &y, p]() mutable {
        *p += 5;
        y += 10;
        return *p + y;
    };
    cout << "[9] Capture pointer + reference → " << f() << endl;
    cout << "After call: x=" << x << " y=" << y << endl;
}

//──────────────────────────── MAIN ────────────────────────────
/**
 * @brief Main interactive demo
 * @details User can select which lambda capture mode to run (1–9).
 */
int main() {
    cout << "C++ Lambda Capture Modes Demo (1–9)\n";
    cout << "-----------------------------------\n";
    cout << "1. No Capture\n";
    cout << "2. Capture by Value\n";
    cout << "3. Capture by Value + mutable\n";
    cout << "4. Capture by Reference\n";
    cout << "5. Capture by Pointer\n";
    cout << "6. Capture All by Value [=]\n";
    cout << "7. Capture All by Reference [&]\n";
    cout << "8. Mixed Capture [=, &b]\n";
    cout << "9. Pointer + Reference Mix\n";
    cout << "Select case: ";

    int choice;
    cin >> choice;
    cout << "\n--- Execution Output ---\n";

    switch (choice) {
        case 1: case1_noCapture(); break;
        case 2: case2_byValue(); break;
        case 3: case3_mutableValue(); break;
        case 4: case4_byReference(); break;
        case 5: case5_byPointer(); break;
        case 6: case6_allByValue(); break;
        case 7: case7_allByRef(); break;
        case 8: case8_mixed(); break;
        case 9: case9_pointerAndRef(); break;
        default: cout << "Invalid selection.\n"; break;
    }

    cout << "\n--- Memory Representation Summary ---\n";
    cout << R"(
╔══════════════════════════════════════════════════════════╗
║           Lambda Capture: Memory Representation          ║
╠══════════════════════════════════════════════════════════╣
║ 1. [ ] No Capture → no closure, only code pointer        ║
║ 2. [x] Capture by Value → closure stores a copy of x     ║
║ 3. [x] mutable → same as (2) but allows modifying copy   ║
║ 4. [&x] by Reference → closure holds pointer to x        ║
║ 5. [ptr] by Pointer → copy of ptr → same address as &x   ║
║ 6. [=] all by value → copies all in-scope variables      ║
║ 7. [&] all by ref → stores pointers to all variables     ║
║ 8. [=, &b] → mix: copies a,c but references b            ║
║ 9. [=, &y, p] → copies ptr & captures ref to y           ║
╚══════════════════════════════════════════════════════════╝

 Stack vs Closure Objects:
 ┌────────────── Stack ───────────────┐
 │ int x=10, y=20;                    │
 │ auto f = [x,&y](){...};            │
 └────────────────────────────────────┘
           │
           ▼
 ┌─────── Closure Object ───────┐
 │ class <lambda> {             │
 │   int x_copy;                │ ← value
 │   int* y_ref;                │ ← reference
 │   operator()() { ... }       │
 └──────────────────────────────┘
)";

    return 0;
}
