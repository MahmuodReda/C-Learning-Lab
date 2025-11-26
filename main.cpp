#include <iostream>

class A
{
public:
    A() { std::cout << "A: Constructor\n"; }
    ~A() { std::cout << "A: Destructor\n"; }

    void Show()
    {
        std::cout << "A: Parent function\n";
    }
};

class B : public A
{
public:
    B() { std::cout << "B: Constructor\n"; }
    ~B() { std::cout << "B: Destructor\n"; }

    void MsgB()
    {
        std::cout << "B: Child B function\n";
    }
};

class C : public A
{
public:
    C() { std::cout << "C: Constructor\n"; }
    ~C() { std::cout << "C: Destructor\n"; }

    void MsgC()
    {
        std::cout << "C: Child C function\n";
    }
};

int main()
{
    B objB;
    objB.Show();
    objB.MsgB();

    std::cout << "----\n";

    C objC;
    objC.Show();
    objC.MsgC();
}

/*   A
   /   \
  B     C */
