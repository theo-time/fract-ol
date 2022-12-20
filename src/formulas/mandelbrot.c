
#include "fractol.h"

double complex_abs(c_double c)
{
	return(sqrt(c.r * c.r + c.i * c.i));
}

int in_disk(c_double c)
{
	c.r++;
	return(complex_abs(c) < 0.25);
}

int in_cardioid(c_double c)
{
	double q = (c.r - 0.25) * (c.r - 0.25) + c.i * c.i;
	return(q * (q + (c.r - 0.25)) < c.i * c.i * 0.25);
}


int	mandelbrot(double c_r, double c_i, t_model *model)
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

	if(in_disk(c) || in_cardioid(c))
		return(model->max_iter);

	while (z.r * z.r + z.i * z.i < 4000 && i < model->max_iter)
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