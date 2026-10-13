cmake_minimum_required(VERSION 3.20)

project(jcrMathLib
    VERSION 0.0.6
    LANGUAGES CXX
)

add_library(jcrMathLib INTERFACE)

target_include_directories(jcrMathLib
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(jcrMathLib INTERFACE cxx_std_20)

add_library(jcrMathLib::jcrMathLib ALIAS jcrMathLib)

# ========================================
# Tests
# ========================================

if(PROJECT_IS_TOP_LEVEL)

    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    )

    FetchContent_MakeAvailable(googletest)


    add_executable(jcrMathTests
        tests/run.cpp
        #tests/vector2_test.cpp
        #tests/vector3_test.cpp
        #tests/constants_test.cpp
    )

    target_link_libraries(jcrMathTests
        PRIVATE
            jcrMathLib
            GTest::gtest_main
    )


    include(GoogleTest)

    gtest_discover_tests(jcrMathTests)

endif()