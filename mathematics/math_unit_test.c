#include<stdarg.h>
#include<stddef.h>
#include<setjmp.h>
#include<cmocka.h>

#include "mathematics.h"
#include <stdint.h>

void math_64to32_convert_test(void **test){
    int64_t value_64 = 256;
    int32_t value_32 = 0;
    bool result = math_64to32_convert(value_64, &value_32);
    assert_true(result == true);
    assert_true(value_32 == (int32_t)value_64);
}

void math_64to32_convert_overflow_test(void **test){
    int64_t value_64 = (int64_t)INT32_MAX+1;
    int32_t value_32 = 0;
    bool result = math_64to32_convert(value_64, &value_32);
    assert_true(result == false);
    assert_true(value_32 == 0);
}

void math_add_test(void **test)
{
    int32_t first_value = 10;
    int32_t second_value = 10;
    int32_t sum = 0;

    bool result = math_add(&sum, first_value, second_value);
    assert_true(result == true);
    assert_true(sum == 20);
}

void math_add_overflow_test(void **test)
{
    int32_t first_value = INT32_MAX;
    int32_t second_value = 10;
    int32_t sum = 0;

    bool result = math_add(&sum, first_value, second_value);
    assert_true(result == false);
    assert_true(sum == 0);
}

void math_sat_add_test(void **test)
{
    int32_t first_value = 10;
    int32_t second_value = 10;
    int32_t sum = math_sat_add(first_value, second_value);
    assert_true(sum == 20);
}

void math_mul_test(void **test)
{
    int32_t first_value = 10;
    int32_t second_value = 10;
    int32_t prod = 0;

    bool result = math_mul(&prod, first_value, second_value);
    assert_true(result == true);
    assert_true(prod == 100);
}

void math_mul_overflow_test(void **test)
{
    int32_t first_value = INT32_MAX;
    int32_t second_value = 10;
    int32_t prod = 0;

    bool result = math_mul(&prod, first_value, second_value);
    assert_true(result == false);
    assert_true(prod == 0);
}

void math_sat_mul_test(void **test)
{
    int32_t first_value = 10;
    int32_t second_value = 10;
    int32_t prod =  math_sat_mul(first_value, second_value);
    assert_true(prod == 100);
}

int main(int argc, char* argv[])
{
    const struct CMUnitTest tests[] = 
    {
        cmocka_unit_test(math_64to32_convert_test),
        cmocka_unit_test(math_64to32_convert_overflow_test),
        cmocka_unit_test(math_add_test),
        cmocka_unit_test(math_add_overflow_test),
        cmocka_unit_test(math_sat_add_test),
        cmocka_unit_test(math_mul_test),
        cmocka_unit_test(math_mul_overflow_test),
        cmocka_unit_test(math_sat_mul_test),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
