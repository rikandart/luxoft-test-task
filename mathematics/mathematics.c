#include "mathematics.h"

bool math_mul(int32_t* result, int32_t left_value, int32_t right_value)
{
    int tmp_res = 0;
    bool overflow = math_mul_overflow(&tmp_res, left_value, right_value);
    if(overflow) return !overflow;
    *result = tmp_res;
    return true;
}

bool math_mul_overflow(int32_t* res, int32_t left_value, int32_t right_value){
    *res = math_sat_mul(left_value, right_value);
    return left_value != 0 && right_value != 0
           && left_value != (*res/right_value);
}

int32_t math_sat_mul(int32_t left_value, int32_t right_value)
{
    return left_value*right_value;
}

bool math_add(int32_t* result, int32_t left_value, int32_t right_value)
{
    int tmp_res = 0;
    bool overflow = math_add_overflow(&tmp_res, left_value, right_value);
    if(overflow) return !overflow;
    *result = tmp_res;
    return true;
}

bool math_add_overflow(int32_t* res, int32_t left_value, int32_t right_value){
    *res = math_sat_add(left_value, right_value);
    bool cond_1 = left_value > 0 && right_value > 0 && *res < left_value;
    bool cond_2 = left_value < 0 && right_value  < 0 && *res > left_value;
    return cond_1 || cond_2;
}

int32_t math_sat_add(int32_t left_value, int32_t right_value)
{
    return left_value+right_value;
}

bool math_64to32_convert(const int64_t source_value, int32_t* dest){
    bool overflow = math_64to32_convert_overflow(source_value);
    if(overflow) return !overflow;
    *dest = math_sat_64to32_convert(source_value);
    return true;
}
bool math_64to32_convert_overflow(const int64_t source_value){
    return source_value > (int64_t)INT32_MAX || source_value < (int64_t)INT32_MIN;
}
int32_t math_sat_64to32_convert(const int64_t source_value){
    return (int32_t)source_value;
}
