cmake_minimum_required(VERSION 3.10)
project (algorithm)

enable_testing()

find_package(GTest REQUIRED)
find_package(OpenSSL REQUIRED)

add_subdirectory(adventofcode2015)
add_subdirectory(leetcode)
