#include <iostream>
#include <string>
using namespace std;

// Default Constructor
class Car {
public:
    Car() {
        cout << "Default Constructor: Car created with default values." << endl;
    }
};

// Parameterized Constructor
class Engine {
public:
    Engine(int hp) {
        cout << "Parameterized Constructor: Engine with " << hp << " HP created." << endl;
    }
    Engine (){
          cout << "Default Constructor" << endl; 
    }
};

// Delegating Constructor
class Vehicle {
    int a ; 
    int b ;
public:
    // Constructor with parameters
    Vehicle(int b ) {
        cout << "Parameterized constructor 1  " <<  endl;
             std::cout << "b = " << b << std::endl;
    }

    // Delegating Constructor -> calls the parameterized one
    Vehicle(int a ,int b )  : Vehicle( b) {
        cout << "Parameterized constructor 2" << endl;
        std::cout << "a = " << a << std::endl;
         std::cout << "b = " << b << std::endl;
    }
};

int main() {
    Car c1;                    // Default constructor
    Engine e1(200);        // Parameterized constructor
    Engine e2 ;
    Vehicle v1(5);          // Delegating constructor
    Vehicle v2(1 , 2) ;  // Direct parameterized constructor
    return 0;
}

// Default Constructor: Car created with default values.
// Parameterized Constructor: Engine with 200 HP created.
// Default Constructor
// Parameterized constructor 1
// b = 5
// Parameterized constructor 1
// b = 2
// Parameterized constructor 2
// a = 1
// b = 2