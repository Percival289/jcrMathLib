cmake_minimum_required(VERSION 3.20)

project(jcrMathLib
    VERSION 0.0.5
    LANGUAGES CXX
)

add_library(jcrMathLib INTERFACE)

target_include_directories(jcrMathLib
    INTERFACE
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(jcrMathLib INTERFACE cxx_std_17)

# Tests
add_executable(jcrMathTest
    tests/main.cpp
)

target_link_libraries(jcrMathTest
    PRIVATE
        jcrMathLib
)