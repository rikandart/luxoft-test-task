cmake_minimum_required(VERSION 3.0)

project(test_task VERSION 0.1 LANGUAGES C)
set(WITH_STATIC_LIB ON)
add_subdirectory(cmocka-1.1.0)

add_library(mathematic STATIC mathematics/mathematics.c)

add_library(geometry STATIC geometry/geometry.c)
target_include_directories(geometry PUBLIC mathematics/)
target_link_libraries(geometry mathematic)

# add_library(parking STATIC parking/parking.c)
# target_include_directories(parking PUBLIC geometry/ mathematics/ vehicle/)
# target_link_libraries(parking mathematic geometry)

add_executable(math_unit_test mathematics/math_unit_test.c)
target_include_directories(math_unit_test PUBLIC cmocka-1.1.0/include)
target_link_libraries(math_unit_test cmocka_static)
target_link_libraries(math_unit_test mathematic)

add_executable(geom_unit_test geometry/geom_unit_test.c)
target_include_directories(geom_unit_test PUBLIC cmocka-1.1.0/include)
target_link_libraries(geom_unit_test cmocka_static)
target_link_libraries(geom_unit_test geometry)

# add_executable(park_unit_test parking/park_unit_test.c)
# target_include_directories(park_unit_test PUBLIC cmocka-1.1.0/include)
# target_link_libraries(park_unit_test cmocka_static)
# target_link_libraries(park_unit_test parking)
