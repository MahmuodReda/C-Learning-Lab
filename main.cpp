#include <iostream>

class A
{
public:
    A() { std::cout << "A: Constructor\n"; }
    ~A() { std::cout << "A: Destructor\n"; }

    void ShowA()
    {
        std::cout << "A: Base function\n";
    }
};

class B : public A
{
public:
    B() { std::cout << "B: Constructor\n"; }
    ~B() { std::cout << "B: Destructor\n"; }

    void ShowB()
    {
        std::cout << "B: Function\n";
    }
};

class C : public A
{
public:
    C() { std::cout << "C: Constructor\n"; }
    ~C() { std::cout << "C: Destructor\n"; }

    void ShowC()
    {
        std::cout << "C: Function\n";
    }
};

class D : public B, public C
{
public:
    D() { std::cout << "D: Constructor\n"; }
    ~D() { std::cout << "D: Destructor\n"; }

    void ShowD()
    {
        std::cout << "D: Final child\n";
    }
};

int main()
{
    {
        D obj;
        obj.ShowB();
        obj.ShowC();
        obj.ShowD();
    }

    std::cout << "*************************************" << std::endl;
    D obj;
    // obj.ShowA(); //Error "D::ShowA" is ambiguous
    obj.B::ShowA(); // Resolving ambiguity by specifying the path

    return 0;
}

//     A
//    / \
//   B   C
//    \ /
//     D

// A: Constructor
// B: Constructor
// A: Constructor
// C: Constructor
// D: Constructor
// B: Function
// C: Function
// D: Final child
// D: Destructor
// C: Destructor
// A: Destructor
// B: Destructor
// A: Destructor
// *************************************
// A: Constructor
// B: Constructor
// A: Constructor
// C: Constructor
// D: Constructor
// A: Base function
// D: Destructor
// C: Destructor
// A: Destructor
// B: Destructor
// A: Destructor
