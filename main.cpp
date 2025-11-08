#include <iostream>
#include <vector>
#include <cctype> // for isdigit (used for char)
using namespace std;

class data1 {
public:
    void fun(const vector<int>& arr) {
        cout << "[data1] Checking if all elements are digits (0-9):" << endl;

        bool allDigits = true;
        for (int num : arr) {
            if (num % 2 !=0 ) {
                allDigits = false;
                break;
            }
        }

        if (allDigits)
            cout << " All elements are even." << endl;
        else
            cout << " Not all elements are even." << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

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
