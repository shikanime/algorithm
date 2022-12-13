cmake_minimum_required(VERSION 3.10)

project(adventofcode2022)

add_executable(calorie_counting calorie_counting.cc)
set_property(TARGET calorie_counting PROPERTY CXX_STANDARD 20)
