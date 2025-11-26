#include <iostream>

class A
{
public:
    A() { std::cout << "A: Constructor\n"; } // Constructor
    ~A() { std::cout << "A: Destructor\n"; } // Destructor

    void ShowA() { std::cout << "A: Function\n"; }
};

class B
{
public:
    B() { std::cout << "B: Constructor\n"; } // Constructor
    ~B() { std::cout << "B: Destructor\n"; } // Destructor

    void ShowB() { std::cout << "B: Function\n"; }
};

class C : public A, public B
{
public:
    C() { std::cout << "C: Constructor\n"; } // Constructor
    ~C() { std::cout << "C: Destructor\n"; } // Destructor

    void ShowC() { std::cout << "C: Function\n"; }
};

int main()
{
    C obj;
    obj.ShowA(); // Accessing base class A function
    obj.ShowB(); // Accessing base class B function
    obj.ShowC(); // Accessing derived class C function
}

//   A     B
//    \   /
//      C
// Multiple Inheritance Example
// A: Constructor
// B: Constructor
// C: Constructor
// A: Function
// B: Function
// C: Function
// C: Destructor
// B: Destructor
// A: Destructor