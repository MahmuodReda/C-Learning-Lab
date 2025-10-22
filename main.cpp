#include <cstdio> // Standard C I/O library for printf

int main() {
    // Integer type: basic whole number
    int x = 1;
    printf("int: %d (size: %zu bytes)\n", x, sizeof(x));

    // Character type: single ASCII character
    char c = 'A';
    printf("char: %c (size: %zu bytes)\n", c, sizeof(c));

    // Short integer: smaller range than int
    short s = 123;
    printf("short: %d (size: %zu bytes)\n", s, sizeof(s));

    // Larger integer value
    int i = 1234567890;
    printf("int: %d (size: %zu bytes)\n", i, sizeof(i));

    // Long integer: may vary in size depending on system
    long l = 1234567890L;
    printf("long: %ld (size: %zu bytes)\n", l, sizeof(l));

    // Long long integer: extended range for large values
    long long ll = 1234567890123456789LL;
    printf("long long: %lld (size: %zu bytes)\n", ll, sizeof(ll));

    // Floating-point number: single precision
    float f = 3.14f;
    printf("float: %f (size: %zu bytes)\n", f, sizeof(f));

    // Double-precision floating-point number
    double d = 3.141592653589793;
    printf("double: %f (size: %zu bytes)\n", d, sizeof(d));

    // Extended precision floating-point number
    long double ld = 3.141592653589793L;
    printf("long double: %Lf (size: %zu bytes)\n", ld, sizeof(ld));

    // Boolean type: true or false
    bool b = true;
    printf("bool: %d (size: %zu bytes)\n", b, sizeof(b));   
    

    return 0;
}
