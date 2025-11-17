#include <iostream>
#include <string>

// ================================================================
//  Class A: Needs a custom copy constructor (Dynamic Memory)
// ================================================================
class A {
public:
    int size;
    int* buffer;  // dynamic resource that requires deep copy

public:
    // Constructor
    A(int s) : size(s) {
        buffer = new int[size];
        for (int i = 0; i < size; i++)
            buffer[i] = i;          // fill with simple pattern
        std::cout << "A Constructor: allocated buffer\n";
    }

    // Copy Constructor (Deep Copy)
    A(const A& other) : size(other.size) {
        buffer = new int[size];     // allocate new memory
        for (int i = 0; i < size; i++)
            buffer[i] = other.buffer[i];  // copy data, not address
        std::cout << "A Copy Constructor: deep copy\n";
    }

    // Destructor
    ~A() {
        delete[] buffer;
        std::cout << "A Destructor: freed buffer\n";
    }
};

// ==================================================================
//  Class B: Does NOT need a copy constructor
//  Everything is safe (int + std::string), so the default behavior is OK
// ==================================================================
class B {
public:
    int id;
    std::string name;  // std::string already manages memory safely

public:
    // Constructor
    B(int id, std::string name) : id(id), name(name) {
        std::cout << "B Constructor\n";
    }

    // Copy constructor NOT written → compiler generates a safe one automatically
};

// ==================================================================
//  Class C: Copying is FORBIDDEN
//  Example: a class that manages a unique resource (socket, file handle)
// ==================================================================
class C {
public:
    C() { std::cout << "C Constructor: resource acquired\n"; }

    // Delete copy constructor (copying not allowed)
    C(const C&) = delete;

    // Delete copy assignment operator as well
    C& operator=(const C&) = delete;
};

int main() {
    std::cout << "\n--- Demonstrating Class A (Custom Copy Constructor) ---\n";
    A a1(5);
    A a2 = a1;  // calls deep-copy constructor
    // a2.buffer[2] =10 ; 
    // std::cout <<  a2.buffer[2] << std::endl ;
    // std::cout <<  a1.buffer[2] << std::endl ;
    a2.buffer[2] = 10; // modify a2's buffer
    std::cout << "a1.buffer[2]: " << a1.buffer[2] << "\n"; // should remain unchanged
    std::cout << "a2.buffer[2]: " << a2.buffer[2] << "\n"; // should reflect the change

    std::cout << "\n--- Demonstrating Class B (No Need for Custom Copy) ---\n";
    B b1(10, "Mahmoud");
    B b2 = b1;  // default copy constructor works fine

    b1.name = "Changed Name";
    std::cout << "b1.name: " << b1.name << "\n";   
    std::cout << "b2.name: " << b2.name << "\n";

    std::cout << "\n--- Demonstrating Class C (Copy Forbidden) ---\n";
    C c1;
    // C c2 = c1;  // ERROR: copy constructor is deleted

    return 0;
}

// --- Demonstrating Class A (Custom Copy Constructor) ---
// A Constructor: allocated buffer
// A Copy Constructor: deep copy
// a1.buffer[2]: 2
// a2.buffer[2]: 10

// --- Demonstrating Class B (No Need for Custom Copy) ---
// B Constructor
// b1.name: Changed Name
// b2.name: Mahmoud

// --- Demonstrating Class C (Copy Forbidden) ---
// C Constructor: resource acquired
// A Destructor: freed buffer
// A Destructor: freed buffer