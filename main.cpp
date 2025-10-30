#include <iostream>
using namespace std;

int main() {
    // Case 1: Local variable inside the lambda body
    // 's' is declared inside the lambda, so a new 's' is created each time the lambda runs
    auto add1 = [](int a, int b) {
        int s = 10;  // Local variable, recreated for each call
        s++;         // Increment s
        return a + b + s;  // Return result using local s
    };

    // Case 2: Captured variable with an initialized value
    // 's' is captured and stored in the lambda object itself
    // 'mutable' allows modification of this internal copy
    auto add2 = [s = 10](int a, int b) mutable {
        s++;         // Modify the captured 's'
        return a + b + s;  // Return result using modified s
    };

    // Each call to add1 starts with a fresh 's' = 10
    cout << "add1 call 1: " << add1(1, 1) << endl; // s = 10 → 11 → result = 13
    cout << "add1 call 2: " << add1(1, 1) << endl; // new s again = 10 → 11 → result = 13

    cout << "_________________________________________________" << endl;
    // Each call to add2 uses the same lambda instance,
    // so 's' keeps its modified value between calls
    cout << "add2 call 1: " << add2(1, 1) << endl; // s = 10 → 11 → result = 13
    cout << "add2 call 2: " << add2(1, 1) << endl; // s = 11 → 12 → result = 14
    
    cout << "add2 call 1: " << add2(1, 1) << endl; 
    cout << "add2 call 2: " << add2(1, 1) << endl; 

}

/*
- Shows how a local variable inside a lambda is recreated per call.
- Demonstrates how captured 's' with 'mutable' persists its value across calls.
- Useful for understanding lambda object state in C++.
*/

// add1 call 1: 13
// add1 call 2: 13
// _________________________________________________
// add2 call 1: 13
// add2 call 2: 14
// add2 call 1: 15
// add2 call 2: 16