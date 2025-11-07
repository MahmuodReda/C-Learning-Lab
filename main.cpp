#include <iostream>

// =======================================
// CLASS 1: Base class with static members
// =======================================
// class myData2; // forward declaration

class myData {
public:
    // (1) Constructor increments shared static counter

    myData();

    // (2) Static function: belongs to the class, not an instance
    static void myFun() ;
    // static void myFun() {
    //     std::cout << "[myFun] Called from myData" << std::endl;
    //     std::cout << "counter = " << counter << std::endl;
    //     std::cout << "PI = " << PI << std::endl;
    //     // std::cout << n; //  Error: non-static member can't be accessed

    //     // myData2::E += 1.0; // Error: cannot access private member    
    //     // std::cout << "myData2::E = " << myData2::E << std::endl; // Error: cannot access private member
    // }

    // (3) Declaration only — definition outside the class
    static int counter;

    // (4) Allowed: static const integral initialized inside class
    static const int MAX = 5;

    // (5) Declaration only — must define outside
    static const int MIN;

    // (6) Declaration of a static float (must define outside)
    static float PI;

    int n; // normal non-static variable
};

// ==============================
// CLASS 2: Modifier / Writer
// ==============================
class myData2 {
public:
    myData2() {
        std::cout << "\n[myData2] Modifying values..." << std::endl;
        myData::counter += 10;   // modify shared counter
        myData::PI = 6.28f;      // change static PI value
        myData::myFun();         // call static function from another class
    }

    static long double E; // Optional extra static member
};

myData::myData() {
    counter++; // Increment shared static counter
    std::cout << "[myData] Constructor called. counter = " << counter << std::endl;
    myData2::E += 0.1; // Just to use the static member
    std::cout << "[myData] myData2::E = " << myData2::E << std::endl;
}
 void myData::myFun() {
    std::cout << "[myFun] Called from myData" << std::endl;
    std::cout << "counter = " << counter << std::endl;
    std::cout << "PI = " << PI << std::endl;
    // std::cout << n; //  Error: non-static member can't be accessed

    myData2::E += 1.0; // Error: cannot access private member    
    std::cout << "myData2::E = " << myData2::E << std::endl; // Error: cannot access private member
}   
// ==============================
// CLASS 3: Reader / Viewer
// ==============================
class myData3 {
public:
    void display() {
        std::cout << "\n[myData3] Reading current static values..." << std::endl;
        std::cout << "counter = " << myData::counter << std::endl;
        std::cout << "PI = " << myData::PI << std::endl;
        std::cout << "MAX = " << myData::MAX << std::endl;
        std::cout << "MIN = " << myData::MIN << std::endl;
    }

    void triggerFunction() {
        std::cout << "\n[myData3] Triggering myData::myFun()" << std::endl;
        myData::myFun();
    }
};

// =======================================
// (7) Definitions of static members
// =======================================
int myData::counter = 0;
const int myData::MIN = 0;
float myData::PI = 3.14f;
long double myData2::E = 2.71828182845904523536; // Optional extra static member

// =======================================
// MAIN FUNCTION
// =======================================
int main() {
    std::cout << "[main] Program started...\n" << std::endl;

    // Create instances of myData (increasing the counter)
    myData d1, d2, d3;
    myData::myFun();

    // Create myData2 (modifies static values)
    myData2 writer;

    // Create myData3 (reads and shows values)
    myData3 reader;
    reader.display();

    // Trigger myFun() again to show updated values
    reader.triggerFunction();

    std::cout << "\n[main] Final static values:" << std::endl;
    std::cout << "counter = " << myData::counter << std::endl;
    std::cout << "PI = " << myData::PI << std::endl;

    return 0;
}

