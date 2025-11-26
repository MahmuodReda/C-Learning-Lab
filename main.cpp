#include <iostream>

class A
{
public:
    A() { std::cout << "A: Constructor\n"; } // Constructor
    ~A() { std::cout << "A: Destructor\n"; } // Destructor

    void Show()
    {
        std::cout << "A: Parent function\n";
    }
};

class B : public A
{
public:
    B() { std::cout << "B: Constructor\n"; } // Constructor
    ~B() { std::cout << "B: Destructor\n"; } // Destructor

    void Print()
    {
        std::cout << "B: Child function\n";
    }
};

int main()
{
    B obj;
    obj.Show();  // Call parent class function
    obj.Print(); // Call child class function
}

// Class A
//  ↓
// Class B
// Inheritance: B inherits from A

// A: Constructor
// B: Constructor
// A: Parent function
// B: Child function
// B: Destructor
// A: Destructor