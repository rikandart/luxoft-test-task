#pragma once

#include <stdint.h>
#include <stdbool.h>

bool math_mul(int32_t* result, int32_t left_value, int32_t right_value);
bool math_mul_overflow(int32_t* res, int32_t left_value, int32_t right_value);
int32_t math_sat_mul(int32_t left_value, int32_t right_value);

bool math_add(int32_t* result, int32_t left_value, int32_t right_value);
bool math_add_overflow(int32_t* res, int32_t left_value, int32_t right_value);
int32_t math_sat_add(int32_t left_value, int32_t right_value);

bool math_64to32_convert(const int64_t source_value, int32_t* dest);
bool math_64to32_convert_overflow(const int64_t source_value);
int32_t math_sat_64to32_convert(const int64_t source_value);

