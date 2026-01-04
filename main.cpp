#include <iostream>
#include "calc.hpp"
#include "wifi.hpp"
#include <fmt/core.h>
#include <spdlog/spdlog.h>

int main()
{

    // c = 10;
    spdlog::info("Hello from spdlog via vcpkg + MSVC");
    std::cout << "Hello, World!" << std::endl;
    fmt::print("Hello, vcpkg fmt!\n");
    wifi_init();
    spdlog::info("Hello from spdlog via vcpkg + MSVC");
    return 0;
}
