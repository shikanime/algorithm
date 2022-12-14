cmake_minimum_required(VERSION 3.10)

project(adventofcode2022)

add_executable(calorie_counting calorie_counting.cc)
set_property(TARGET calorie_counting PROPERTY CXX_STANDARD 20)

add_executable(calorie_counting_part_two calorie_counting_part_two.cc)
set_property(TARGET calorie_counting_part_two PROPERTY CXX_STANDARD 20)

add_executable(rock_paper_scissors rock_paper_scissors.cc)
set_property(TARGET rock_paper_scissors PROPERTY CXX_STANDARD 20)
