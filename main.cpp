#include <bits/stdc++.h>
using namespace std;

class LCD {
public:
    string msg;       // Stores the text shown on the LCD screen
    int courser = 0;  // Represents the cursor position

    // Display the current message on the screen
    void display() { 
        cout << msg << endl; 
    }

    // ---------------------------------------------------
    // operator+= allows using syntax like: lcd1 += message;
    // It appends the given string to the current msg
    LCD &operator+=(const string &message) {
        this->msg += message;   // Concatenate message to msg
        return *this;           // Return reference to the same object
    }

    // ---------------------------------------------------
    // operator< compares the msg of two LCD objects
    bool operator<(const LCD &l) { 
        return this->msg < l.msg; 
    }

    // operator> checks if current msg is greater (lexicographically)
    bool operator>(const LCD &l) { 
        return this->msg > l.msg; 
    }

    // ---------------------------------------------------
    // Pre-increment (++lcd): increase courser first, then return object
    LCD &operator++() {
        cout << "pre increment ++x" << endl;
        this->courser++;
        return *this; // return by reference (so chaining is possible)
    }

    // ---------------------------------------------------
    // Post-increment (lcd++): return old value, then increase courser
    int operator++(int) {
        cout << "post increment x++" << endl;
        int temp = this->courser;  // store old value
        this->courser++;           // then increment
        return temp;               // return old value
    }

    // ---------------------------------------------------
    // operator- used here to set courser position manually
    // Example: lcd1 - 5; sets courser = 5
    LCD &operator-(int x) {
        cout << "operator-" << endl;
        this->courser = x;
        return *this;
    }
};

// -------------------------------------------------------
// operator+ is defined outside the class
// It allows expressions like: string s = lcd1 + "Text";
string operator+(const LCD &lcd, const string &msg) {
    return lcd.msg + msg;  // Combine LCD message and given text
}

int main() {
    // Create two LCD objects with initial messages
    LCD lcd1{ "Hello World"};  
    LCD lcd2{"From Egypt"};

    string message = " From Egypt ";
    
    // ---------------------------------------------
    // operator+= : append string to lcd1.msg
    lcd1 += message; // same as lcd1.operator+=(message)
    lcd1.display();

    // ---------------------------------------------
    // operator+ : concatenates lcd1.msg and message, returns a new string
    string result = lcd1 + message; 
    cout << result << endl;

    // ---------------------------------------------
    // operator< : compare lcd1.msg with lcd2.msg
    if (lcd1 < lcd2) { 
        cout << "lcd1 is less than lcd2" << endl;
    } else {
        cout << "lcd1 is not less than lcd2" << endl;
    }

    // ---------------------------------------------
    // Pre-increment (++lcd1)
    ++lcd1; 
    cout << "courser after ++lcd1 = " << lcd1.courser << endl;

    // Post-increment (lcd1++)
    int c = lcd1++;
    cout << "courser returned by lcd1++ = " << c 
         << ", current courser = " << lcd1.courser << endl;

    // ---------------------------------------------
    // Example of normal integer increment
    int y = 10;
    int l = y++;
    cout << "y=" << y << ", l=" << l << endl;

    // ---------------------------------------------
    // Pre-increment for integer
    int x = 100;
    ++x = 200; // ++x returns a reference, so assignment is valid
    cout << x << endl;

    // ---------------------------------------------
    // Test operator++ on another LCD object
    LCD lcd3{ "Hello World"};
    // ++lcd3 = 1; // Invalid logically: ++lcd3 returns LCD&, cannot assign int

    // ---------------------------------------------
    // Test operator- to set courser manually
    lcd3 - 5; // sets courser = 5
    cout << "lcd3 courser = " << lcd3.courser << endl;

    return 0;
}
