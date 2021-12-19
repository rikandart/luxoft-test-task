#include<stdarg.h>
#include<stddef.h>
#include<setjmp.h>
#include<cmocka.h>

#include "mathematics.h"
#include <stdint.h>

void math_mul_test(void **test)
{
    int32_t first_value = 10;
    int32_t second_value = 10;
    int32_t sum = 0;

    bool result = math_mul(&sum, first_value, second_value);
    assert_true(result == true);
    assert_true(sum == 100);
}

int main(int argc, char* argv[])
{
    const struct CMUnitTest tests[] = 
    {
        cmocka_unit_test(math_mul_test),
        cmocka_unit_test(math_64to32_convert_test),
        cmocka_unit_test(math_64to32_convert_overflow_test),
        cmocka_unit_test(math_add_test),
        cmocka_unit_test(math_add_overflow_test),
        cmocka_unit_test(math_sat_add_test),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
