#include <iostream>     // For input/output operations
#include <vector>       // For using the dynamic array (vector)
#include <numeric>      // For std::accumulate to sum elements

// Define a class that calculates the sum of elements in a vector
class MyClass
{
public:
    MyClass();  // Default constructor (not used here)

    // Static function to calculate sum of vector elements
    static void Calculate(std::vector<int> &arr) {
        // Use std::accumulate to sum all elements in the vector
        MyClass::sum = std::accumulate(arr.begin(), arr.end(), 0);

        // Print the calculated sum
        std::cout << "Sum = " << MyClass::sum << std::endl;
    }

    // Static member variable to hold the sum
    static int sum;

private:
    // Private section (currently unused, but reserved for future members)
};

// Initialize static member variable
int MyClass::sum = 0;

int main() {
    // Create a vector of size 10
    std::vector<int> arr(10);

    // Fill the vector with values from 0 to 9
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    // Call the static function to calculate and display the sum
    MyClass::Calculate(arr);

    return 0; // Indicate successful program termination
}
