#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdint.h>

#include "geometry.h"

void test_intersect_line_line(void **test){
    struct geom_line line_1 = {.first_pt.x = 0, .first_pt.y = 0,
                            .second_pt.x = 0, .second_pt.y = 10},
                     line_2 = {.first_pt.x = 20, .first_pt.y = 30,
                            .second_pt.x = 10, .second_pt.y = 0};
    struct geom_point result_point = {0, 0};
    bool result = intersect_line_line(&result_point, &line_1, &line_2);
    assert_true(result == true);
}

void test_intersect_line_line_no_point(void **test)
{
    struct geom_line line_1 = {.first_pt.x = 0, .first_pt.y = 0,
                            .second_pt.x = 0, .second_pt.y = 10},
                     line_2 = {.first_pt.x = 20, .first_pt.y = 30,
                            .second_pt.x = 20, .first_pt.y = 0};
    struct geom_point result_point = {0, 0};
    bool result = intersect_line_line(0x0, &line_1, &line_2);
    assert_true(result == false);
    result = intersect_line_line(&result_point, 0x0, &line_2);
    assert_true(result == false);
    result = intersect_line_line(&result_point, &line_1, 0x0);
    assert_true(result == false);
}


void test_geom_zero_distance(void **test)
{
    struct geom_line line_1 = {.first_pt.x = 0, .first_pt.y = 0,
                            .second_pt.x = 0, .second_pt.y = 0},
                     line_2 = {.first_pt.x = 20, .first_pt.y = 30,
                            .second_pt.x = 20, .first_pt.y = 0};
    struct geom_point result_point = {0, 0};
    bool result = intersect_line_line(&result_point, &line_1, &line_2);
    assert_true(result == false);
}

void test_geom_overflow_distance(void **test)
{
    struct geom_line line_1 = {.first_pt.x = INT32_MIN, .first_pt.y = INT32_MAX,
                            .second_pt.x = INT32_MAX, .second_pt.y = INT32_MIN},
                     line_2 = {.first_pt.x = 20, .first_pt.y = 30,
                            .second_pt.x = 20, .first_pt.y = 0};
    struct geom_point result_point = {0, 0};
    bool result = intersect_line_line(&result_point, &line_1, &line_2);
    assert_true(result == false);
}

int main(int argc, char* argv[])
{
    const struct CMUnitTest tests[] = 
    {
        cmocka_unit_test(test_intersect_line_line_no_point),
        cmocka_unit_test(test_intersect_line_line),
        cmocka_unit_test(test_geom_zero_distance),
        cmocka_unit_test(test_geom_overflow_distance),
        /*cmocka_unit_test(test_geom_move_point),
        cmocka_unit_test(test_geom_move_point_overflow),*/
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
    // return 0;
}

