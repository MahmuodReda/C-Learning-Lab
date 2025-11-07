#include <iostream>

class Box;  // forward declaration

// --- 1. Friend Function Declaration ---
void showDimensions(const Box& b);

class Box {
private:
    double width, height, depth;

    // Declare friendship
    friend class Builder;                     // 2. Friend Class
    friend void showDimensions(const Box& b); // 3. Friend Function
    friend std::ostream& operator<<(std::ostream& os, const Box& b); // 4. Friend Operator

public:
    Box(double w, double h, double d) : width(w), height(h), depth(d) {}
};

// --- Friend Function Implementation ---
void showDimensions(const Box& b) {
    std::cout << "[showDimensions] Width: " << b.width
              << ", Height: " << b.height
              << ", Depth: " << b.depth << std::endl;
}

// --- Friend Class Implementation ---
class Builder {
public:
    void resize(Box& b, double w, double h, double d) {
        // Access private members directly
        b.width = w;
        b.height = h;
        b.depth = d;
    }
};

// --- Friend Operator Implementation ---
std::ostream& operator<<(std::ostream& os, const Box& b) {
    os << "[Box] " << b.width << " x " << b.height << " x " << b.depth;
    return os;
}

int main() {
    Box myBox(3.0, 4.0, 5.0);
    Builder maker;

    std::cout << myBox << std::endl; // friend operator
    showDimensions(myBox);           // friend function
    maker.resize(myBox, 10.0, 12.0, 15.0); // friend class

    std::cout << "After resizing: " << myBox << std::endl;
    return 0;
}
