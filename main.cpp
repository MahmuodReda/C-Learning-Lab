#include <iostream>
#include <type_traits>

struct A { int x; };           // trivial
struct B { 
    int x; 
    B() {}                     // non-trivial (custom constructor)
};
struct C {
    int x;
    ~C() {}                    // non-trivial (custom destructor)
};

int main() {
    std::cout << "A trivial? " << std::is_trivial<A>::value << "\n";
    std::cout << "B trivial? " << std::is_trivial<B>::value << "\n";
    std::cout << "C trivial? " << std::is_trivial<C>::value << "\n";
}

// A trivial? 1
// B trivial? 0
// C trivial? 0