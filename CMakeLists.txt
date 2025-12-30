cmake_minimum_required(VERSION 3.16) # Specify the minimum CMake version required

project(MyProject VERSION 1.0 LANGUAGES CXX) # Define the project name and version
set(files
     main.cpp
     sum.cpp) # List of source files

 message(STATUS "SER File has ${files}")   
 message(STATUS "path is ${CMAKE_SOURCE_DIR} ") 

add_executable(Sec_Files ${files}) # Add an executable target named 'Sec_Files' with source file 'main.cpp'


target_include_directories(Sec_Files PUBLIC include/)