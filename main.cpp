#include <iostream>

class A
{
public:
    A() { std::cout << "A: Constructor\n"; }
    ~A() { std::cout << "A: Destructor\n"; }

    void ShowA() { std::cout << "A: Function\n"; }
};

class B : virtual public A
{
public:
    B() { std::cout << "B: Constructor\n"; }
    ~B() { std::cout << "B: Destructor\n"; }

    void ShowB() { std::cout << "B: Function\n"; }
};

class C : virtual public A
{
public:
    C() { std::cout << "C: Constructor\n"; }
    ~C() { std::cout << "C: Destructor\n"; }

    void ShowC() { std::cout << "C: Function\n"; }
};

class D : public B, public C
{
public:
    D() { std::cout << "D: Constructor\n"; }
    ~D() { std::cout << "D: Destructor\n"; }

    void ShowD() { std::cout << "D: Function\n"; }
};

int main()
{
    D obj;

    obj.ShowA();
    // obj.ShowB();
    // obj.ShowC();
    // obj.ShowD();

    return 0;
}

//          A
//      /       \
//   virtual  virtual
//     B         C
//       \     /
//          D

// A: Constructor
// B: Constructor
// C: Constructor
// D: Constructor
// A: Function
// D: Destructor
// C: Destructor
// B: Destructor
// A: Destructor
