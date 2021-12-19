#pragma once

#include <stdint.h>
#include <stdbool.h>

struct geom_point
{
    int32_t x;
    int32_t y;
};

struct geom_line
{
    struct geom_point first_pt;
    struct geom_point second_pt;
};

bool intersect_line_line(struct geom_point* p_result_point,
                         const struct geom_line* p_line_1,
                         const struct geom_line* p_line_2);

bool geom_zero_distance(const struct geom_line* p_line);
bool check_coincident(const int32_t A1, const int32_t B1, const int32_t C1,
                      const int32_t A2, const int32_t B2, const int32_t C2);

bool calc_A(int32_t* A, const struct geom_line* p_line);
bool calc_B(int32_t* B, const struct geom_line* p_line);
bool calc_C(int32_t* C, const struct geom_line* p_line);

bool calc_det(int32_t* det, int32_t A,
        int32_t B, int32_t  C, int32_t D);
