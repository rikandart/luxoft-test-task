#include <math.h>
#include "mathematics.h"
#include "geometry.h"

bool intersect_line_line(struct geom_point* p_result_point,
                         const struct geom_line* p_line_1,
                         const struct geom_line* p_line_2)
{
    // Ay + Bx = C
    // (y-y1)/(y2-y1) = (x-x1)/(x2-x1)
    // (x2-x1)*y + (y1-y2)*x = y1*x2 - x1*y2
    /*  Using Cramer's Rule
    *   |C1 B1|   
    *   |C2 B2|          det1
    *   -------    =    ------  =   p_result_point->x
    *   |A1 B1|          det
    *   |A2 B2|
    *   
    * 
    *   |A1 C1|   
    *   |A2 C2|          det2
    *   -------    =    ------  =   p_result_point->y
    *   |A1 B1|          det
    *   |A2 B2|
    */

    // if p_result_point == {INT32_MIN, INT32_MIN} lines are coincident, function returns true
    // else p_result_point == {INT32_MAX, INT32_MAX} lines are parallel, function returns false
    // otherwise p_result_point is intersection point of p_line_1 and p_line_2, function returns true
    bool coincident = p_line_1->first_pt.x == p_line_2->first_pt.x
                          && p_line_1->first_pt.y == p_line_2->first_pt.y
                          && p_line_1->second_pt.x == p_line_2->second_pt.x
                          && p_line_1->second_pt.y == p_line_2->second_pt.y;
    if(coincident){
        p_result_point->x = INT32_MIN;
        p_result_point->y = INT32_MIN;
        return true;
    }

    int32_t A1 = 0, B1 = 0, C1 = 0,
            A2 = 0, B2 = 0, C2 = 0,
            det = 0, det1 = 0, det2 = 0;
    
    bool calc_res = calc_A(&A1, p_line_1);
    if(!calc_res) return false;
    calc_res = calc_B(&B1, p_line_1);
    if(!calc_res) return false;
    calc_res = calc_C(&C1, p_line_1);
    if(!calc_res) return false;
    
    bool calc_res = calc_A(&A2, p_line_2);
    if(!calc_res) return false;
    calc_res = calc_B(&B2, p_line_2);
    if(!calc_res) return false;
    calc_res = calc_C(&C2, p_line_2);
    if(!calc_res) return false;
    
    calc_res = calc_det(&det, A1, B1, A2, B2);
    if(!calc_res) return false;
    if(det == 0){
        // lines are parallel        
        p_result_point->x = INT32_MAX;
        p_result_point->y = INT32_MAX;
        return false;
    }
    calc_res = calc_det(&det1, C1, B1, C2, B2);
    if(!calc_res) return false;
    calc_res = calc_det(&det2, A1, C1, A2, C2);
    if(!calc_res) return false;
    p_result_point->x = det1/det;
    p_result_point->y = det2/det;
    return true;
}

bool calc_det(int32_t* det, int32_t A,
        int32_t B, int32_t  C, int32_t D){
    int32_t l_det = 0, r_det = 0;
    bool mul_res = math_mul(&l_det, A, D);
    if(!mul_res) return false;
    mul_res = math_mul(&r_det, B, C);
    if(!mul_res) return false;
    return math_add(&det, l_det, -r_det);
}

bool calc_A(int32_t* A, const struct geom_line* p_line){
    // A = x2 - x1  
    return math_add(A, p_line->second_pt.x, -p_line->first_pt.x);
}

bool calc_B(int32_t* B, const struct geom_line* p_line){
    // B = y1 - x2
    return math_add(B, p_line->first_pt.y, -p_line->second_pt.y);
}

bool calc_C(int32_t* C, const struct geom_line* p_line){
    /*
    * C = y1*x2 - x1*y2  
    * l_C = y1*x2, r_c = x1*y2 
    */
    int32_t l_C = 0, r_C = 0;
    bool mul_res = math_mul(&l_C, p_line->first_pt.y, p_line->second_pt.x);
    if(!mul_res) return false;
    mul_res = math_mul(&r_C, p_line->first_pt.x, p_line->second_pt.y);
    if(!mul_res) return false;
    bool add_res = math_add(C, l_C, -r_C);
    if (!add_res) return false;
    return true;
}