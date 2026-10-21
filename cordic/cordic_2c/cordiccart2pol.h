#ifndef CORDICCART2POL_H
#define CORDICCART2POL_H

#define NO_ITER 20

#include <ap_fixed.h>

typedef ap_fixed<32,3> coef_t;
typedef float data_t;
typedef ap_fixed<16,3> acc_t;
typedef ap_fixed<32,3> angle_t;

void cordiccart2pol(data_t x, data_t y, data_t * r,  data_t * theta);

#endif
