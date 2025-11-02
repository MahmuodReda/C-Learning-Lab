#include <iostream>
using namespace std;

// ======= Global & Static Variables =======
int globalA = 5;             // Static initialization (known at compile time)
int globalB = globalA + 5;   // Dynamic initialization (evaluated at runtime)

// ======= Function for dynamic init =======
int calcValue() {
    cout << "calcValue() called\n";
    return 42;
}

// ======= Main Function =======
int main() {
    cout << "=== Demonstrating All Initialization Types ===\n";

    // 1. Default initialization
    int a; // Uninitialized - contains garbage value
    cout << "Default-initialized a = " << a << " (undefined)\n";

    // 2. Copy initialization
    int b = 10;
    cout << "Copy-initialized b = " << b << "\n";

    // 3. Direct initialization
    int c(20);
    cout << "Direct-initialized c = " << c << "\n";

    // 4. List initialization
    int d{30};
    cout << "List-initialized d = " << d << "\n";

    // 5. Aggregate initialization (struct + array)
    struct Point { int x; int y; };
    Point p = {3, 4};
    cout << "Aggregate-initialized struct p = (" << p.x << ", " << p.y << ")\n";

    int arr[3]= {1, 2, 3} ;
    cout << "Aggregate-initialized array = {" << arr[0] << ", " << arr[1] << ", " << arr[2] << "}\n";

    // 6. Reference initialization
    int& ref = b;
    cout << "Reference-initialized ref (refers to b): " << ref << "\n";

    // 7. Dynamic initialization
    int dyn = calcValue(); // Value returned by a function at runtime
    cout << "Dynamic-initialized dyn = " << dyn << "\n";

    // 8. Static local initialization
    static int localStatic = 77;
    cout << "Static local var localStatic = " << localStatic << "\n";

    cout << "Global variables: globalA = " << globalA << ", globalB = " << globalB << "\n";

    cout << "=== End of Demonstration ===\n";
    return 0;
}
