add_executable(not_quite_lisp not_quite_lisp.cc)
set_property(TARGET not_quite_lisp PROPERTY CXX_STANDARD 20)

add_executable(not_quite_lisp_part_two not_quite_lisp_part_two.cc)
set_property(TARGET not_quite_lisp_part_two PROPERTY CXX_STANDARD 20)

add_executable(i_was_told_there_would_be_no_math
               i_was_told_there_would_be_no_math.cc)
set_property(TARGET i_was_told_there_would_be_no_math PROPERTY CXX_STANDARD 20)

add_executable(i_was_told_there_would_be_no_math_part_two
               i_was_told_there_would_be_no_math_part_two.cc)
set_property(TARGET i_was_told_there_would_be_no_math_part_two
             PROPERTY CXX_STANDARD 20)

add_executable(perfectly_spherical_houses_in_a_vacuum
               perfectly_spherical_houses_in_a_vacuum.cc)
set_property(TARGET perfectly_spherical_houses_in_a_vacuum PROPERTY CXX_STANDARD
                                                                    20)

add_executable(perfectly_spherical_houses_in_a_vacuum_part_two
               perfectly_spherical_houses_in_a_vacuum_part_two.cc)
set_property(TARGET perfectly_spherical_houses_in_a_vacuum_part_two
             PROPERTY CXX_STANDARD 20)

add_executable(the_ideal_stocking_stuffer the_ideal_stocking_stuffer.cc)
target_link_libraries(the_ideal_stocking_stuffer PRIVATE OpenSSL::SSL)
set_property(TARGET the_ideal_stocking_stuffer PROPERTY CXX_STANDARD 20)

add_executable(the_ideal_stocking_stuffer_part_two
               the_ideal_stocking_stuffer_part_two.cc)
target_link_libraries(the_ideal_stocking_stuffer_part_two PRIVATE OpenSSL::SSL)
set_property(TARGET the_ideal_stocking_stuffer_part_two PROPERTY CXX_STANDARD
                                                                 20)

add_executable(doesn_t_he_have_intern_elves_for_this
               doesn_t_he_have_intern_elves_for_this.cc)
set_property(TARGET doesn_t_he_have_intern_elves_for_this PROPERTY CXX_STANDARD
                                                                   20)

add_executable(doesn_t_he_have_intern_elves_for_this_part_two
               doesn_t_he_have_intern_elves_for_this_part_two.cc)
set_property(TARGET doesn_t_he_have_intern_elves_for_this_part_two
             PROPERTY CXX_STANDARD 20)

add_executable(probably_a_fire_hazard probably_a_fire_hazard.cc)
set_property(TARGET probably_a_fire_hazard PROPERTY CXX_STANDARD 20)

add_executable(probably_a_fire_hazard_part_two
               probably_a_fire_hazard_part_two.cc)
set_property(TARGET probably_a_fire_hazard_part_two PROPERTY CXX_STANDARD 20)

add_executable(some_assembly_required some_assembly_required.cc)
set_property(TARGET some_assembly_required PROPERTY CXX_STANDARD 20)
