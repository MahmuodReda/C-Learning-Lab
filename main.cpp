#include <iostream>
#include <vector>
#include <cctype> // for isdigit (used for char)
using namespace std;

class data1 {
public:
    void fun(const vector<char>& arr) {
        cout << "[data1] Checking if all elements are digits (0-9):" << endl;

        bool allDigits = true;
        for (char num : arr) {
            if (num < '0' || num > '9') {
                allDigits = false;
                break;
            }
        }

        if (allDigits)
            cout << " All elements are digits (0-9)." << endl;
        else
            cout << " Not all elements are digits." << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<char> arr(n);

    // Input array elements
    cout << "Enter array elements: ";
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Create object and call function
    data1 checker;
    checker.fun(arr);

    return 0;
}
