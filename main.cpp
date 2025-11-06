#include <iostream>
#include <string>
using namespace std;

class Person {
    const string name; // must use initializer list
    int age;
    int &refAge;       // reference must be initialized
public:
    Person(string n, int a, int &ref) 
        : name(n), age(a), refAge(ref) { // initializer list used here
        cout << "Person Created: " << name << ", " << age << endl;
    }

    void show() {
        cout << "Name: " << name << ", Age: " << age << ", Ref: " << refAge << endl;
    }
};

int main() {
    int realAge = 30;
    Person p1("Mahmoud", 25, realAge);
    p1.show();

    return 0;
}
