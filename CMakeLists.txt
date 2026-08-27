cmake_minimum_required(VERSION 3.20)

project(jcrMathLib
    VERSION 0.0.5
    LANGUAGES CXX
)

add_library(jcrMathLib
    src/vector2.cpp
    src/vector3.cpp
)

target_include_directories(jcrMathLib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(jcrMathLib PUBLIC cxx_std_17)

# Tests
add_executable(jcrMathTest
    tests/main.cpp
)

target_link_libraries(jcrMathTest
    PRIVATE
        jcrMathLib
)