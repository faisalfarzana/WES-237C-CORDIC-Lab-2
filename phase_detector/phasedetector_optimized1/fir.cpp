/*
	Filename: fir.cpp
		Complex FIR or Match filter
		firI1 and firI2 share coef_t c[N]
		firQ1 and firQ2 share coef_t c[N]
		
	INPUT:
		I: signal for I sample
		I: signal for Q sample

	OUTPUT:
		X: filtered output
		Y: filtered output

*/

#include "phasedetector.h"

void firI1 (
  data_t *y,
  data_t x
  ) {

	coef_t c[N] = {1,    -1,    1,    -1,    -1,    -1,    1,    1,    -1,    -1,    -1,    1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    1,    1,    1,    1,    -1,    -1,    1,    1,    1,    -1,    -1,    -1};

	// Write your code here
	//based off fir project 1
	static data_t shift_reg[N] = {0};
    acc_t acc = 0;

    for (int i = N - 1; i > 0; i--) {
        #pragma HLS PIPELINE II=1
        shift_reg[i] = shift_reg[i - 1];
    }
    shift_reg[0] = x;

    for (int i = 0; i < N; i++) {
        #pragma HLS PIPELINE II=1
        acc += shift_reg[i] * c[i];
    }
    *y = acc;
	
}


void firI2 (
  data_t *y,
  data_t x
  ) {

	coef_t c[N] = {1,    -1,    1,    -1,    -1,    -1,    1,    1,    -1,    -1,    -1,    1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    1,    1,    1,    1,    -1,    -1,    1,    1,    1,    -1,    -1,    -1};

	// Write your code here
	//based off fir project 1
	static data_t shift_reg[N] = {0};
    acc_t acc = 0;

    for (int i = N - 1; i > 0; i--) {
        #pragma HLS PIPELINE II=1
        shift_reg[i] = shift_reg[i - 1];
    }
    shift_reg[0] = x;

    for (int i = 0; i < N; i++) {
        #pragma HLS PIPELINE II=1
        acc += shift_reg[i] * c[i];
    }
    *y = acc;
}




void firQ1 (
  data_t *y,
  data_t x
  ) {

	coef_t c[N] = {-1,    -1,    1,    -1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    -1,    1,    -1,    1,    1,    -1,    1,    -1,    -1,    1,    -1,    1,    1,    1,    1,    -1,    1,    -1,    1,    1};


	// Write your code here
	//based off fir project 1
	static data_t shift_reg[N] = {0};
    acc_t acc = 0;

    for (int i = N - 1; i > 0; i--) {
        #pragma HLS PIPELINE II=1
        shift_reg[i] = shift_reg[i - 1];
    }
    shift_reg[0] = x;

    for (int i = 0; i < N; i++) {
        #pragma HLS PIPELINE II=1
        acc += shift_reg[i] * c[i];
    }
    *y = acc;
	
}

void firQ2 (
  data_t *y,
  data_t x
  ) {

	coef_t c[N] = {-1,    -1,    1,    -1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    -1,    1,    -1,    1,    1,    -1,    1,    -1,    -1,    1,    -1,    1,    1,    1,    1,    -1,    1,    -1,    1,    1};


	// Write your code here
	//based off fir project 1
	static data_t shift_reg[N] = {0};
    acc_t acc = 0;

    for (int i = N - 1; i > 0; i--) {
        #pragma HLS PIPELINE II=1
        shift_reg[i] = shift_reg[i - 1];
    }
    shift_reg[0] = x;

    for (int i = 0; i < N; i++) {
        #pragma HLS PIPELINE II=1
        acc += shift_reg[i] * c[i];
    }
    *y = acc;
	
}


void fir (
  data_t I,
  data_t Q,

  data_t *X,
  data_t *Y
){

	// Write your code here
	data_t i_gi = {};
	data_t q_gq = {};
	data_t q_gi = {};
	data_t i_gq = {};

	//pass I and Q thru real filters
	firI1(&i_gi, I); // I * G_I
    firQ1(&q_gq, Q); // Q * G_Q
    firI2(&q_gi, Q); // Q * G_I
    firQ2(&i_gq, I); // I * G_Q
	
	//complex matched filters
	//Calculate X
	*X = i_gi + q_gq;

	//Calculate Y
	*Y = q_gi - i_gq;
}


