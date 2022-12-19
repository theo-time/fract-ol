
#include "fractol.h"

int	inverse_mandelbrot(double c_r, double c_i, t_model *model)
{
	(void) model;
	c_double c;
	c_double z;
	c.r = c_r / (c_r * c_r + c_i * c_i);
	c.i = c_i/ (c_r * c_r + c_i * c_i);
	// printf("x : %f | y : %f \n", c.r, c.i);
	z.r = 0;
	z.i = 0;
	int i = 0;
	double tmp;

	while (z.r * z.r + z.i * z.i < 4 && i < model->max_iter)
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

	return (i + 1 - log(log2(sqrt(z.r*z.r + z.i * z.i))));
}