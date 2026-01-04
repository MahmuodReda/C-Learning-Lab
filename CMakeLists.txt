cmake_minimum_required(VERSION 3.16)

project(MyProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(files
    main.cpp
    sum.cpp
)

message(STATUS "Source_File files: ${files}")
message(STATUS "Project path: ${CMAKE_SOURCE_DIR}")

add_subdirectory(lib)

add_executable(Source_File ${files})

target_include_directories(Source_File PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/lib
)

find_package(fmt CONFIG REQUIRED)

   find_package(spdlog CONFIG REQUIRED)

target_link_libraries(Source_File PRIVATE
    spdlog::spdlog
    fmt::fmt
    wifi_lib
)


 