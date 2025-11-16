#include <iostream>
#include <functional>

// A functor class because it defines operator()
class Complex {
private:
    int real;
    float img;

public:
    // Default constructor  
    Complex() 
    {
    std::cout << "Default Constructor Called" << std::endl;
    }
    ~Complex() 
    { 
    std::cout << "Destructor Called" << std::endl;
    }

    // Parameterized constructor
    Complex(int real, float img) : real(real), img(img) {}

    // This makes the object callable like a function
    void operator()() {
        std::cout << "Real is " << real << std::endl;
        std::cout << "Img is " << img << std::endl;
    }
};

// A function that accepts ANY callable (function, lambda, functor)
// as long as it matches: void(void)
void fun(std::function<void(void)> t) {
    t();   // Call the stored callable object
}

int main() {

    // 1) Create normal object B with real=2 and img=2.5
    Complex B(2, 2.5);

    // Call operator() directly on the object
    // Equivalent to: B.operator()();
    B();  

    // 2) Create a temporary (anonymous) Complex object
    // No operator() is called here because we didn't write Complex()();
    Complex();  

    // 3) Store a temporary Complex object inside std::function
    //
    // Complex() is a temporary functor object.
    // std::function will COPY this temporary object internally.
    std::function<void(void)> t = Complex();

    // // Call the stored functor
    // // Equivalent to: storedComplex.operator()();
    t();

    // // 4) We can also pass a temporary functor directly to fun()
    fun(Complex());  // functor temporary → copied inside fun → operator() called

    return 0;
}

// Real is 2
// Img is 2.5
// Default Constructor Called
// Destructor Called
// Default Constructor Called
// Destructor Called
// Real is 16
// Img is 0
// Default Constructor Called
// Real is 1
// Img is 0
// Destructor Called
// Destructor Called
// Destructor Called
// Destructor Called