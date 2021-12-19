#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdint.h>

#include "geometry.h"

void test_intersect_line_line_no_point(void **test)
{
    struct geom_line line_1 = {.first_pt.x = 0, .first_pt.y = 0,
                            .second_pt.x = 0, .second_pt.y = 10},
                     line_2 = {.first_pt.x = 20, .first_pt.y = 30,
                            .second_pt.x = 20, .first_pt.y = 0};
    struct geom_point result_point = {0, 0};
    bool result = intersect_line_line(&result_point, &line_1, &line_2);
    assert_false(result);
}

int main(int argc, char* argv[])
{
    const struct CMUnitTest tests[] = 
    {
        cmocka_unit_test(test_geom_distance),
        cmocka_unit_test(test_geom_zero_distance),
        cmocka_unit_test(test_geom_overflow_distance),
        cmocka_unit_test(test_geom_move_point),
        cmocka_unit_test(test_geom_move_point_overflow),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}

