#include <iostream>
#include <string>

//
// ========================= CLASS INT =========================
// A simple integer wrapper class to demonstrate operator overloading
//
class INT
{
public:
    int val;

    // Default constructor (initialize value to 0)
    INT() : val(0) {}

    // Parameterized constructor
    INT(int a) : val(a) {}

    // ---------------------- Arithmetic Operators ----------------------

    // Return a NEW INT object containing (this->val + obj.val)
    INT operator+(const INT &obj)
    {
        return INT(this->val + obj.val);
    }

    // Return a NEW INT object containing (this->val - obj.val)
    INT operator-(const INT &obj)
    {
        return INT(this->val - obj.val);
    }

    // Modify *this then return *this
    INT operator+=(const INT &obj)
    {
        this->val += obj.val;
        return *this;
    }

    INT operator-=(const INT &obj)
    {
        this->val -= obj.val;
        return *this;
    }

    // ---------------------- Comparison Operators ----------------------

    bool operator==(const INT &obj) { return this->val == obj.val; }
    bool operator!=(const INT &obj) { return this->val != obj.val; }
    bool operator<(const INT &obj) { return this->val < obj.val; }
    bool operator>(const INT &obj) { return this->val > obj.val; }

    // ---------------------- Assignment Operator ----------------------

    INT operator=(const INT &obj)
    {
        this->val = obj.val;
        return *this;
    }
};

//
// Overload << for INT to print the value
//
std::ostream &operator<<(std::ostream &os, const INT &p)
{
    os << "(" << p.val << ")";
    return os;
}

//
// ========================= CLASS MyString =========================
// A wrapper around std::string to demonstrate operator overloading
//
class MyString
{
public:
    std::string val;

    // Default constructor
    MyString() : val("") {}

    // Accept C-string literal
    MyString(const char *a) : val(a) {}

    // Accept std::string
    MyString(const std::string &a) : val(a) {}

    // ---------------------- Arithmetic Operators ----------------------

    // return NEW object (concatenation)
    MyString operator+(const MyString &obj)
    {
        return MyString(val + obj.val);
    }

    // append to *this then return *this
    MyString operator+=(const MyString &obj)
    {
        this->val += obj.val;
        return *this;
    }

    // ---------------------- Comparison Operators ----------------------

    bool operator==(const MyString &obj) { return this->val == obj.val; }
    bool operator!=(const MyString &obj) { return this->val != obj.val; }
    bool operator<(const MyString &obj) { return this->val < obj.val; }
    bool operator>(const MyString &obj) { return this->val > obj.val; }

    // ---------------------- Assignment Operator ----------------------

    MyString operator=(const MyString &obj)
    {
        this->val = obj.val;
        return *this;
    }
};

//
// Overload << for MyString
//
std::ostream &operator<<(std::ostream &os, const MyString &p)
{
    os << p.val;
    return os;
}

//
// ========================= TEST SECTION =========================
//
int main()
{
    std::cout << "===== Testing INT class =====\n";

    INT a(10);
    INT b(3);

    INT sum = a + b; // new object
    INT diff = a - b;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "a + b = " << sum << "\n";
    std::cout << "a - b = " << diff << "\n";

    a += b;
    std::cout << "a += b -> a = " << a << "\n";

    // comparisons
    std::cout << "a == b ? " << (a == b) << "\n";
    std::cout << "a >  b ? " << (a > b) << "\n";

    // assignment operator
    INT x;
    x = a;
    std::cout << "x = a -> x = " << x << "\n";

    std::cout << "\n===== Testing MyString class =====\n";

    MyString s1("Hello");
    MyString s2(" World");

    MyString s3 = s1 + s2; // new object

    std::cout << "s1 = " << s1 << "\n";
    std::cout << "s2 = " << s2 << "\n";
    std::cout << "s1 + s2 = " << s3 << "\n";

    s1 += s2;
    std::cout << "s1 += s2 -> s1 = " << s1 << "\n";

    // comparisons
    std::cout << "s1 == s3 ? " << (s1 == s3) << "\n";
    std::cout << "s1 <  s3 ? " << (s1 < s3) << "\n";

    // assignment
    MyString s4;
    s4 = s3;
    std::cout << "s4 = s3 -> s4 = " << s4 << "\n";

    return 0;
}

// ===== Testing INT class =====
// a = (10)
// b = (3)
// a + b = (13)
// a - b = (7)
// a += b -> a = (13)
// a == b ? 0
// a >  b ? 1
// x = a -> x = (13)

// ===== Testing MyString class =====
// s1 = Hello
// s2 =  World
// s1 + s2 = Hello World
// s1 += s2 -> s1 = Hello World
// s1 == s3 ? 1
// s1 <  s3 ? 0
// s4 = s3 -> s4 = Hello World
