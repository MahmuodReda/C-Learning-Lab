
cmake_minimum_required(VERSION 3.16) # Specify the minimum CMake version required

project(MyProject VERSION 1.0 LANGUAGES CXX) # Define the project name and version


add_executable(reda main.cpp   src/calc.cpp ) # Add an executable target named 'reda' with source file 'main.cpp'


add_custom_target(run
    COMMAND reda                # Command to execute the 'reda' program
    DEPENDS reda          
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}  
    COMMENT "Running the program..."
)
target_include_directories(reda PUBLIC include/)