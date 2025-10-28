#include <iostream>
#include <typeinfo>
#include <initializer_list>

int main() {
    auto a = 42;                  // int
    auto b = 3.14;                // double
    auto c = 'x';                 // char
    auto d = "hello";            // const char*
    auto e = std::string("hi");  // std::string

    int x = 10;
    int& rx = x;
    const int& crx = x;

    auto f = rx;                 // int (copy)
    auto g = crx;                // int (copy)
    auto& h = crx;               // const int& (preserves reference)

    auto p = &x;                 // int*
    auto q = &crx;               // const int*


    // Print deduced types using typeid
    std::cout << "a: " << typeid(a).name() << "\n";
    std::cout << "b: " << typeid(b).name() << "\n";
    std::cout << "c: " << typeid(c).name() << "\n";
    std::cout << "d: " << typeid(d).name() << "\n";
    std::cout << "e: " << typeid(e).name() << "\n";
    std::cout << "f: " << typeid(f).name() << "\n";
    std::cout << "g: " << typeid(g).name() << "\n";
    std::cout << "h: " << typeid(h).name() << "\n";
    std::cout << "p: " << typeid(p).name() << "\n";
    std::cout << "q: " << typeid(q).name() << "\n";


    return 0;
}

/*
| Expression         | Deduced Type               | Notes                            |
|--------------------|----------------------------|----------------------------------|
| auto a = 42;       | int                        | Integer literal                  |
| auto b = 3.14;     | double                     | Floating-point literal           |
| auto c = 'x';      | char                       | Character literal                |
| auto d = "hello";  | const char*                | String literal                   |
| auto e = string    | std::string                | Explicit string object           |
| auto f = rx;       | int                        | Reference dropped (copy)         |
| auto g = crx;      | int                        | Const reference dropped (copy)   |
| auto& h = crx;     | const int&                 | Reference preserved              |
| auto p = &x;       | int*                       | Pointer to int                   |
| auto q = &crx;     | const int*                 | Pointer to const int             |
*/

// a: i
// b: d
// c: c
// d: PKc
// e: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
// f: i
// g: i
// h: i
// p: Pi
// q: PKi