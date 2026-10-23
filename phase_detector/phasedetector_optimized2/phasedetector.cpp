/*
	Filename: phasedetector.cpp
		Phase detector

	INPUT:
		I: signal for I sample
		Q: signal for Q sample

	OUTPUT:
		R: Radius
		Theta: Angle

*/

#include "phasedetector.h"


void phasedetector(
  data_t I,
  data_t Q,

  data_t *R,
  data_t *Theta
  )
  {
	#pragma HLS PIPELINE II=1

	data_t X={};
	data_t Y={};
	// Write your code here
	fir(I, Q, &X, &Y);	//complex matched filter
	cordiccart2pol(X,Y,R,Theta); //xy-polar transformation
}




