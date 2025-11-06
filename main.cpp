#include <iostream>
using namespace std;

class Example {
    int a;
    int b;
public:
    // Here we try to initialize members using initializer list
    // But the order of initialization follows the order of declaration in the class
    // First 'b' is initialized because it is declared before 'a'
    // Then 'a' is initialized using 'b'
    // This can lead to unexpected values if we use a member before it is set
    Example(int x, int y) : b(x), a(b) { //'Example::b' will be initialized after [-Wreorder]
        cout << "a = " << a << ", b = " << b << endl;
    }
};

int main() {
    Example obj(10, 20); // passing 10 and 20, but 'a' depends on 'b'
}

// Output may look strange like: a = 32758, b = 10
// Reason: initialization order follows declaration order, not the list order
