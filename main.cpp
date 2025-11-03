#include <iostream>

class PersonWithoutThis {
private:
    int age;  // Data member of the class

public:
    // Constructor without 'this' - demonstrates the name shadowing problem
    PersonWithoutThis(int age) {
        age = age;  // Name shadowing: This assigns the parameter to itself, not the class member!
                    // As a result, the class member 'age' remains uninitialized (may have garbage value).
    }

    void printAge() {
        std::cout << "Age (without this): " << age << std::endl;  // Prints uninitialized or garbage value due to shadowing
    }
};

class PersonWithThis {
private:
    int age;  // Data member of the class

public:
    // Constructor with 'this' - solves the name shadowing problem
    PersonWithThis(int age) {
        this->age = age;  // 'this->age' refers to the class member, assigning the parameter value to it correctly.
                          // This avoids shadowing and ensures proper initialization.
    }

    void printAge() {
        std::cout << "Age (with this): " << this->age << std::endl;  // Prints the correct value; 'this' is optional here but shown for clarity
    }
};

int main() {
    // Create object from the class without 'this' - shows the problem
    PersonWithoutThis p1(30);
    p1.printAge();  // Output: Age (without this): 0 (or some garbage value, depending on compiler)

    // Create object from the class with 'this' - shows the solution
    PersonWithThis p2(30);
    p2.printAge();  // Output: Age (with this): 30 (correct value)

    return 0;
}