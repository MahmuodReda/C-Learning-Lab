#include <iostream>

// Define a simple struct to represent a 2D point
struct Point {
    int x, y; // Coordinates of the point
};

// Overload the << operator to print Point objects in (x, y) format
std::ostream& operator<<(std::ostream &os, const Point &p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    // Create a Point object with coordinates (2,3)
    Point a{2,3};

    // Print the point using the overloaded << operator
    std::cout << "Point a = " << a << "\n";
}
