#include <iostream>

class myData {
public:
    // Constructor increases shared counter
    myData() { counter++; }

    // (8) Static function belongs to the class, not an object
    static void myFun() {
        std::cout << "[myFun] Hello from static function" << std::endl;
        std::cout << "counter = " << counter << std::endl; // (11) Accessing static variable
        // std::cout << n; // ERROR: can't access non-static members
    }

    // (1) Declaration only - must define outside class
    static int counter;

    // (4) Allowed: static const integral initialized inside class
    static const int MAX = 5;

    // (6) Declared only: must define outside
    static const int MIN;
    static const float PI;

    int n; // normal variable
};

// (1) Definition of static members (must be outside class)
int myData::counter = 0;

// (6) Definitions for constants declared inside class
const int myData::MIN = 0;
const float myData::PI = 3.14f;

int main() {
    myData d1, d2, d3;

    // (2) Preferred access via class name
    std::cout << "Access via class: " << myData::counter << std::endl;

    // (3) Allowed (but not preferred) access via instance
    std::cout << "Access via object: " << d1.counter << std::endl;

    // Call static function (9) via class name
    myData::myFun();

    // (10) Also possible via object, but not preferred
    d2.myFun();

    // Access to constants
    std::cout << "MAX = " << myData::MAX << std::endl;
    std::cout << "MIN = " << myData::MIN << std::endl;
    std::cout << "PI  = " << myData::PI << std::endl;

    return 0;
}
