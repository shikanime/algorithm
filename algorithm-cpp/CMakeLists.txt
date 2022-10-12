cmake_minimum_required(VERSION 3.10)
project(algorithm)

enable_testing()

find_package(OpenSSL REQUIRED)
find_package(GTest REQUIRED)

add_subdirectory(src)
