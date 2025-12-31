cmake_minimum_required(VERSION 3.16)  # Minimum CMake version
project(wifi_lib)                      # Library project name

# Create a static library from wifi.cpp
add_library(wifi_lib STATIC wifi.cpp)

# Include directory for library headers
target_include_directories(wifi_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# PUBLIC → any target linking this library will also use this include path
