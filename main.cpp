#include <iostream>

class A
{
public:
    A() { std::cout << "A: Constructor\n"; }
    ~A() { std::cout << "A: Destructor\n"; }

    void ShowA()
    {
        std::cout << "A: Level 1 function\n";
    }
};

class B : public A
{
public:
    B() { std::cout << "B: Constructor\n"; }
    ~B() { std::cout << "B: Destructor\n"; }

    void ShowB()
    {
        std::cout << "B: Level 2 function\n";
    }
};

class C : public B
{
public:
    C() { std::cout << "C: Constructor\n"; }
    ~C() { std::cout << "C: Destructor\n"; }

    void ShowC()
    {
        std::cout << "C: Level 3 function\n";
    }
};

int main()
{
    C obj;
    obj.ShowA();
    obj.ShowB();
    obj.ShowC();
}
// A → B → C
// A: Constructor
// B: Constructor
// C: Constructor
// A: Level 1 function
// B: Level 2 function
// C: Level 3 function
// C: Destructor
// B: Destructor
// A: Destructor