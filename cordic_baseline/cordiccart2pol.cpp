#include "cordiccart2pol.h"

data_t Kvalues[NO_ITER] = {1,	0.500000000000000,	0.250000000000000,	0.125000000000000,	0.0625000000000000,	0.0312500000000000,	0.0156250000000000,	0.00781250000000000,	0.00390625000000000,	0.00195312500000000,	0.000976562500000000,	0.000488281250000000,	0.000244140625000000,	0.000122070312500000,	6.10351562500000e-05,	3.05175781250000e-05};

data_t angles[NO_ITER] = {0.785398163397448,	0.463647609000806,	0.244978663126864,	0.124354994546761,	0.0624188099959574,	0.0312398334302683,	0.0156237286204768,	0.00781234106010111,	0.00390623013196697,	0.00195312251647882,	0.000976562189559320,	0.000488281211194898,	0.000244140620149362,	0.000122070311893670,	6.10351561742088e-05,	3.05175781155261e-05};



void cordiccart2pol(data_t x, data_t y, data_t * r,  data_t * theta)
{
	// Write your code here
	data_t current_x = x; // current x and y values
	data_t current_y = y;
	data_t current_theta = 0;

	if (y >= 0) // if y is positive then rotate -90
	{
		current_y = 0 - x;
		current_x = y;
		current_theta = (355.0f / 113.0f) / 2.0f;
	}
	if(y < 0) // if y is negative then rotate 90
	{
		current_y = x;
		current_x = 0 - y;
		current_theta = (-355.0f / 113.0f) / 2.0f;
	}
	if (y == 0 && x == 0)
	{
		*r = 0;
		*theta = 0;
		return;
	}

		for(int j = 0; j < NO_ITER; j++)
	{
		int sigma = (current_y < 0) ? -1 : 1;

		data_t x_shift = current_y * sigma * Kvalues[j];
		data_t y_shift = current_x * sigma * Kvalues[j];

		current_x = current_x + x_shift;
		current_y = current_y - y_shift;

		current_theta += sigma * angles[j];

	}

	*theta = current_theta;
	*r = 0.607252935 * current_x;





	
}
