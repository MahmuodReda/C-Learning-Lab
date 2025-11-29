#include <iostream>

// ================= Interface (Pure Abstract Class) =================
class Base
{
public:
    virtual void print() = 0;  // pure virtual
    virtual void print2() = 0; // pure virtual
    virtual void print3() = 0; // pure virtual
};

// ================= Abstract Class (NOT pure) ======================
class baseabstract
{
public:
    // Virtual but NOT pure -> class is NOT abstract
    virtual void print()
    {
        std::cout << "baseabstract\n";
    }
};

// ================= Derived from abstract class ====================
class data : public baseabstract
{
public:
    void print() override
    {
        std::cout << "data\n";
    }
};

// ================= Derived from Interface =========================
class derived : public Base
{
public:
    void print() override
    {
        std::cout << "print()\n";
    }

    void print2() override
    {
        std::cout << "print2()\n";
    }

    void print3() override
    {
        std::cout << "print3()\n";
    }
};

// =============================== MAIN =============================
int main()
{
    data d2;
    d2.print(); // Calls overridden version -> "data"

    // Base is an INTERFACE -> cannot create:
    // Base b; // ERROR

    derived d;
    d.print();
    d.print2();
    d.print3();

    return 0;
}

// data
// print()
// print2()
// print3()