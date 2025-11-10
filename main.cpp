#include <iostream>
#include <vector>


// -----------------------------
// Example functions
// -----------------------------
void fun3(int x) {

    std::cout << "fun3: begin\n";

    std::cout << "fun3: end\n";
  
}

void fun2(int x) {

    std::cout << "fun2: begin\n";
    fun3(x + 1);
    std::cout << "fun2: end\n";
}

void fun1(int x) {

    std::cout << "fun1: begin\n";
    fun2(x + 1);
    std::cout << "fun1: end\n";
}

int main(){

    std::cout << "Start program\n";

    fun1(1);

    std::cout << "Program finished\n";
    return 0;

}