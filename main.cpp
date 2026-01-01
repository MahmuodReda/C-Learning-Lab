#include <iostream>
#include "calc.hpp"
#include "wifi.hpp"
#include "defaultConfig.hpp"

int main()
{

    std::cout << "Product Type: " << ProductType << std::endl;
    std::cout << "Product Year: " << PRODUCT_YEAR << std::endl;
    std::cout << "Debug Mode: " << DEBUGINFO << std::endl;
    wifi_init();

    return 0;
}

// Product Type: BMW
// Product Year: 2025
// HelloApp Version: 1.0
// WiFi initialized.