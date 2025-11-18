#include <iostream>
#include <cstring>


// CLASS A — Demonstrates COPY CONSTRUCTOR

class A {
private:
    char* buffer;   // stored on HEAP
    int size;

public:
    // Constructor
    A(const char* text) {
        size = strlen(text);
        buffer = new char[size + 1];   // allocate on HEAP
        memcpy(buffer, text, size + 1);
        std::cout << "A: Normal Constructor\n";
    }
  void modfayBuffer(const char* newText) {
        size_t newSize = strlen(newText);
        if (newSize <= size) {
            memcpy(buffer, newText, newSize + 1); // +1 to include null terminator
        } else {
            std::cout << "New text is too large to fit in the existing buffer.\n";
        }
    }

    // COPY CONSTRUCTOR (Deep Copy)
    A(const A& other) {
        std::cout << "A: Copy Constructor\n";

        size = other.size;
        buffer = new char[size + 1];           // allocate new memory
        memcpy(buffer, other.buffer, size + 1); // deep copy data

        /*
            MEMORY VIEW (Copy Constructor)
            -------------------------------
            STACK:
                other.buffer ---> [0x100 HEAP BLOCK] "ABC"
                this.buffer  ---> [0x200 HEAP BLOCK] "ABC"
        */
    }

    void print() const {
        std::cout << buffer << "\n";
    }

    ~A() {
        std::cout << "A: Destructor (delete buffer)\n";
        delete[] buffer;  // free HEAP memory
    }
};


// CLASS B — Demonstrates COPY ASSIGNMENT OPERATOR     

class B {
private:
    char* buffer;  
    int size;

public:
    B(const char* text) {
        size = strlen(text);
        buffer = new char[size + 1];
        memcpy(buffer, text, size + 1);
        std::cout << "B: Normal Constructor\n";
    }

    void modfayBuffer(const char* newText) {
        size_t newSize = strlen(newText);
        if (newSize <= size) {
            memcpy(buffer, newText, newSize + 1); // +1 to include null terminator
        } else {
            std::cout << "New text is too large to fit in the existing buffer.\n";
        }
    }

    // COPY ASSIGNMENT OPERATOR
    B& operator=(const B& other) {
        std::cout << "B: Copy Assignment Operator\n";

        // Self-assignment check
        if (this == &other)
            return *this;

        /*
            Before writing new data, we must clean the old HEAP block:

            MEMORY BEFORE ASSIGNMENT
            ------------------------
            STACK:
                this.buffer ---> [0x300 HEAP BLOCK] "XYZ"
                other.buffer ---> [0x400 HEAP BLOCK] "HELLO"
        */

        delete[] buffer; // delete old HEAP memory first (VERY IMPORTANT)

        // Allocate new block
        size = other.size;
        buffer = new char[size + 1];
        memcpy(buffer, other.buffer, size + 1);

        /*
            MEMORY AFTER ASSIGNMENT
            -----------------------
            STACK:
                this.buffer ---> [0x500 NEW HEAP BLOCK] "HELLO"
                other.buffer ---> [0x400 HEAP BLOCK] "HELLO"
        */

        return *this;
    }

    void print() const {
        std::cout << buffer << "\n";
    }

    ~B() {
        std::cout << "B: Destructor (delete buffer)\n";
        delete[] buffer;
    }
};


int main() {

    std::cout << "\n=== COPY CONSTRUCTOR DEMO (Class A) ===\n";
    A a1("ABC");
    A a2 = a1;      // calls COPY CONSTRUCTOR
    a2.print();
    a1.print();

    a1.modfayBuffer("DEF");
    std::cout << "After modifying a1's buffer:\n";
    a1.print();
    a2.print();     // should still be "ABC" if deep copy worked
    


    std::cout << "\n=== COPY ASSIGNMENT DEMO (Class B) ===\n";
    B b1("XYZ");
    B b2("HELLO");

    b1 = b2;       // calls COPY ASSIGNMENT
    b1.print();

    b1.modfayBuffer("WORLD");
    std::cout << "After modifying b1's buffer:\n";  
    b1.print();
    b2.print();     // should still be "HELLO" if deep copy worked

    std::cout << "\n=== SELF ASSIGNMENT TEST ===\n";
    b1 = b1;       // safe due to (this == &other) check

    return 0;
}


// === COPY CONSTRUCTOR DEMO (Class A) ===
// A: Normal Constructor
// A: Copy Constructor
// ABC
// ABC
// After modifying a1's buffer:
// DEF
// ABC

// === COPY ASSIGNMENT DEMO (Class B) ===
// B: Normal Constructor
// B: Normal Constructor
// B: Copy Assignment Operator
// HELLO
// After modifying b1's buffer:
// WORLD
// HELLO

// === SELF ASSIGNMENT TEST ===
// B: Copy Assignment Operator
// B: Destructor (delete buffer)
// B: Destructor (delete buffer)
// A: Destructor (delete buffer)
// A: Destructor (delete buffer)