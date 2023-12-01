cmake_minimum_required(VERSION 3.10)

project(adventofcode2022)

add_executable(trebuchet trebuchet.cc)
set_property(TARGET trebuchet PROPERTY CXX_STANDARD 20)

add_executable(trebuchet_part_two trebuchet_part_two.cc)
set_property(TARGET trebuchet_part_two PROPERTY CXX_STANDARD 20)

