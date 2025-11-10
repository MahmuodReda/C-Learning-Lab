#include <iostream>     // include for input/output (not used here but standard)
#include <vector>       // include the vector container from STL

int main() {

    std::vector<int> arr;  // create an empty vector of integers named arr

    // loop from 10 to 999 (inclusive)
    for (int i = 10; i < 1001; i++)
    {
        arr.push_back(i);  // add each value of i to the end of the vector
    }

    // at the end, arr contains all integers from 10 to 999
    // total number of elements = 990 (1000 - 10)

    return 0; // indicate successful program termination
}
