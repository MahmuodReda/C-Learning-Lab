cmake_minimum_required(VERSION 3.16)  # Require at least CMake 3.16
project(MyProject VERSION 1.0 LANGUAGES CXX)  # Project name, version, language

set(MyValue "on" CACHE STRING "Argument options")
message(STATUS "Argument Value is ${MyValue}")
message(STATUS "CMAKE_CXX_STANDARD (${CMAKE_CXX_STANDARD})")

# MSYS2 / MinGW temporary folder setup
# if(MINGW)
#     if(NOT DEFINED ENV{TMPDIR})
#         set(ENV{TMPDIR} "${CMAKE_BINARY_DIR}/tmp")  # Set TMPDIR if not defined
#         file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/tmp")  # Create the temp folder
#     endif()
#     set(ENV{TMP} "$ENV{TMPDIR}")    # Set TMP environment variable
#     set(ENV{TEMP} "$ENV{TMPDIR}")   # Set TEMP environment variable
# endif()

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
set(DEBUG "1")
if(DEBUG)
    set(DEBUGINFO "Debug mode is ON")
    message(STATUS "${DEBUGINFO}")
endif()

foreach(R IN ITEMS M A H M O U D)

    message(STATUS "${R}")
    
endforeach(R IN Items)

set(PRODUCT_YEAR "2025")
set(HELLOAPP_VERSION_MAJOR 1)
set(HELLOAPP_VERSION_MINOR 0)

configure_file(defaultConfig.hpp.in defaultConfig.hpp)
target_include_directories(Sec_Files PUBLIC ${PROJECT_BINARY_DIR})

# Link the executable with the library
target_link_libraries(Sec_Files PUBLIC wifi_lib)
