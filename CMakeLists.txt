cmake_minimum_required(VERSION 3.28)
project(grokking_meta)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/f8d7d77.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(toeplitz 1_toeplitz_matrix.cpp)
target_link_libraries(toeplitz GTest::gtest_main)

add_executable(remove_adjacent_duplicates 2_remove_adjacent_duplicates.cpp)
target_link_libraries(remove_adjacent_duplicates GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(toeplitz)
gtest_discover_tests(remove_adjacent_duplicates)
