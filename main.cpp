#include <bits/stdc++.h>
#include <cstring>

// struct/class functions and variables
// 1- can allocate in same scope of object
// 2- from memory side: data members are allocated inside the object scope (stack or heap)
// 3- functions (methods) are stored in the .text section (code segment)

class personData {
    public:
    int age;
    char name[12];

    // Constructor
    // RAII: Resource Acquisition Is Initialization
    // Automatically called when an object is created
    personData() {
        std::cout << "Constructor called" << std::endl;
        age = 25;
        strcpy(name, "Mahmood");
    }

    // Destructor
    // Automatically called when object goes out of scope or is deleted
    ~personData() {
        std::cout << "Destructor called" << std::endl;
        age = 0;
        strcpy(name, "");
    }

    // If defined this way (inline, inside the class):
// void showInfo() { 
//     std::cout << "Name: " << name << ", Age: " << age << std::endl;
// }
// It is not stored in .text as a separate symbol unless called (and not fully inlined by the compiler).
 
    void showInfo(); 
//    { 
//        std::cout << "Name: " << name << ", Age: " << age << std::endl;
//    }
    // Example function
  
};
 void personData:: showInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
/*
/ STACK FRAME:
    p.age
    p.name
/ TEXT SECTION:
    personData::showInfo()
*/

// In this definition style (non-inline, defined outside the class), 
// the function is stored in the .text section even if not called, due to external linkage.


// Main function
int main() {
    personData Reda; // object created on stack -> constructor runs automatically

    std::cout << "Age: " << Reda.age << std::endl;
    std::cout << "Name: " << Reda.name << std::endl;

    Reda.showInfo(); // calling member function

    std::cout << "Program is ending..." << std::endl;

    return EXIT_SUCCESS;
} // when main ends, destructor runs automatically for 'Reda'