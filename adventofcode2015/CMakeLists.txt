cmake_minimum_required(VERSION 3.10)
project (adventofcode2015)

add_executable(not_quite_lisp src/not_quite_lisp.cc)
set_property(TARGET not_quite_lisp PROPERTY CXX_STANDARD 20)

add_executable(not_quite_lisp_part_two src/not_quite_lisp_part_two.cc)
set_property(TARGET not_quite_lisp_part_two PROPERTY CXX_STANDARD 20)
