#include <iostream>
using namespace std;

//-------------------------------------------
// Rule 1: Initialization order in constructor
//-------------------------------------------
class Rule1 {
public:
    int x;
    int y;

    // Even if you write (y(y), x(x)), initialization follows declaration order.
    Rule1() : y(10), x(y) { // 'x' is initialized first, then 'y'
        cout << "[Rule1] x = " << x << ", y = " << y << endl;
    }
};

//-------------------------------------------
// Rule 2: const member function cannot modify data members
//-------------------------------------------
class Rule2 {
public:
    int value = 5;

    void modify() const {
        // value++; //  Error: cannot modify member in const function
        cout << "[Rule2] const function can't modify normal members\n";
    }
};

//-------------------------------------------
// Rule 3: 'mutable' allows modification in const functions
//-------------------------------------------
class Rule3 {
public:
    mutable int counter = 0;

    void increase() const {
        counter++; //  allowed because of 'mutable'
        cout << "[Rule3] counter = " << counter << endl;
    }
};

//-------------------------------------------
// Rule 4: Reference member binds permanently to another variable
//-------------------------------------------
class Rule4 {
public:
    int &ref;
    Rule4(int &r) : ref(r) {} // must initialize reference in constructor
};

//-------------------------------------------
// Rule 5: Constructor calls automatically when object is created
//-------------------------------------------
class Rule5 {
public:
    Rule5() {
        cout << "[Rule5] Constructor called!\n";
    }
};

//-------------------------------------------
// Rule 6: const object can only call const functions
//-------------------------------------------
class Rule6 {
public:
    void normalFunc() { cout << "[Rule6] Normal function called\n"; }
    void constFunc() const { cout << "[Rule6] Const function called\n"; }
};

//-------------------------------------------
// Rule 8: Reference members must be initialized upon creation
//-------------------------------------------
class Rule8 {
public:
    int &ref;
    Rule8(int &r) : ref(r) {} //  Must initialize reference here
};

//-------------------------------------------
// Rule 9: const function cannot return non-const pointer/reference
//-------------------------------------------
class Rule9 {
private:
    int data = 42;
public:
    int* getPtr() const { return (int*)&data; }  //  Bad practice
    int& getRef() const { return (int&)data; }   //  Bad practice
};

//-------------------------------------------
// Rule 10: Static members can be changed in const function
//-------------------------------------------
class Rule10 {
public:
    static int counter;
    void increase() const {
        counter++; //  static members can be modified in const function
    }
};
int Rule10::counter = 0;

//-------------------------------------------
// MAIN
//-------------------------------------------
int main() {
    cout << "---- Rule 1 ----\n";
    Rule1 r1;

    cout << "\n---- Rule 2 ----\n";
    Rule2 r2;
    r2.modify();

    cout << "\n---- Rule 3 ----\n";
    const Rule3 r3;
    r3.increase();

    cout << "\n---- Rule 4 ----\n";
    int num = 10;
    Rule4 r4(num);
    cout << "[Rule4] ref = " << r4.ref << endl;
    num = 20;
    cout << "[Rule4] ref after change = " << r4.ref << endl;

    cout << "\n---- Rule 5 ----\n";
    Rule5 r5;

    cout << "\n---- Rule 6 ----\n";
    const Rule6 r6_const;
    // r6_const.normalFunc(); //  not allowed
    r6_const.constFunc();      //  allowed

    cout << "\n---- Rule 8 ----\n";
    int x = 50;
    Rule8 r8(x);
    cout << "[Rule8] ref = " << r8.ref << endl;

    cout << "\n---- Rule 9 ----\n";
    const Rule9 r9;
    cout << "[Rule9] data = " << *r9.getPtr() << endl;

    cout << "\n---- Rule 10 ----\n";
    const Rule10 r10a, r10b;
    r10a.increase();
    r10b.increase();
    cout << "[Rule10] static counter = " << Rule10::counter << endl;
}

// ---- Rule 1 ----
// [Rule1] x = 0, y = 10

// ---- Rule 2 ----
// [Rule2] const function can't modify normal members

// ---- Rule 3 ----
// [Rule3] counter = 1

// ---- Rule 4 ----
// [Rule4] ref = 10
// [Rule4] ref after change = 20

// ---- Rule 5 ----
// [Rule5] Constructor called!

// ---- Rule 6 ----
// [Rule6] Const function called

// ---- Rule 8 ----
// [Rule8] ref = 50

// ---- Rule 9 ----
// [Rule9] data = 42

// ---- Rule 10 ----
// [Rule10] static counter = 2