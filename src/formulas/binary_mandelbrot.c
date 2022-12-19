
#include "fractol.h"

int	binary_mandelbrot(double c_r, double c_i, t_model *model)
{
	(void) model;
	c_double c;
	c_double z;
	c.r = c_r;
	c.i = c_i;
	// printf("x : %f | y : %f \n", c.r, c.i);
	z.r = 0;
	z.i = 0;
	int i = 0;
	double tmp;

	while (z.r * z.r + z.i * z.i < 5000 && i < model->max_iter)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
		// printf("x : %d | y : %d --> i : %d\n", x, y, i);
	}

    if (i == model->max_iter)
	{
        return (model->max_iter);
	}

	if( 0 < z.i)
		return (i + 1 - log(log2(sqrt(z.r*z.r + z.i * z.i))));
	else
		return ((i + 1 - log(log2(sqrt(z.r*z.r + z.i * z.i)))) / 2);
}