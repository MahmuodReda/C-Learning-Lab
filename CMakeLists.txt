cmake_minimum_required(VERSION 3.16)  # Require at least CMake 3.16
project(MyProject VERSION 1.0 LANGUAGES CXX)  # Project name, version, language

# List of source files
set(files
    main.cpp
    sum.cpp
)

# Debug messages
message(STATUS "Source files: ${files}")
message(STATUS "Project path: ${CMAKE_SOURCE_DIR}")

# Add subdirectory for library (important!)
add_subdirectory(lib)  

# Create executable from source files
add_executable(Sec_Files ${files})

# Include directories for headers
target_include_directories(Sec_Files PUBLIC 
    include/   # Project headers
    lib/       # Library headers
)


target_include_directories(Sec_Files PUBLIC ${PROJECT_BINARY_DIR})

# Link the executable with the library
target_link_libraries(Sec_Files PUBLIC wifi_lib)

#1- File
# FILE(READ "main.cpp" MAIN_Text)
# Message("${MAIN_Text}")
# FILE(STRINGS "main.cpp" MAIN_Text)
# Message("${MAIN_Text}")
# FILE(STRINGS "main.cpp" MAIN_Text REGEX "^Ke")
# Message("${MAIN_Text}")
# file(GLOB_RECURSE SRCS "*.cpp")
# Message("${SRCS}")

# #2-String
# FILE(READ "main.cpp" MAIN_Text)
# STRING(REGEX REPLACE "int" "void" OUT "${MAIN_Text}")
# Message("${OUT}")
