#include <iostream>
#include "calc.hpp"
#include "wifi.hpp"

int main()
{

    wifi_init();
    std::cout << X << std::endl;
    std::cout << "Sum of 3 and 5 is: " << sum(3, 5) << std::endl;
    int a = 5, b = 7;
    std::cout << "sum(" << a << ", " << b << ") = " << sum(a, b) << std::endl;
    return 0;
}
