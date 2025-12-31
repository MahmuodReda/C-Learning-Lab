cmake_minimum_required(VERSION 3.16)  # Require at least CMake 3.16
project(MyProject VERSION 1.0 LANGUAGES CXX)  # Project name, version, language

# MSYS2 / MinGW temporary folder setup
if(MINGW)
    if(NOT DEFINED ENV{TMPDIR})
        set(ENV{TMPDIR} "${CMAKE_BINARY_DIR}/tmp")  # Set TMPDIR if not defined
        file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/tmp")  # Create the temp folder
    endif()
    set(ENV{TMP} "$ENV{TMPDIR}")    # Set TMP environment variable
    set(ENV{TEMP} "$ENV{TMPDIR}")   # Set TEMP environment variable
endif()

# List of source files
set(files
    main.cpp
    sum.cpp
)

# Debug messages
message(STATUS "Source files: ${files}")
message(STATUS "Project path: ${CMAKE_SOURCE_DIR}")
message(STATUS "Temp folder for compiler: $ENV{TMPDIR}")

# Add subdirectory for library (important!)
add_subdirectory(lib)  

# Create executable from source files
add_executable(Sec_Files ${files})

# Include directories for headers
target_include_directories(Sec_Files PUBLIC 
    include/   # Project headers
    lib/       # Library headers
)

# Link the executable with the library
target_link_libraries(Sec_Files PUBLIC wifi_lib)
