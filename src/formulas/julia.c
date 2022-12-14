
#include "fractol.h"

int	julia(double x, double y, t_model *model)
{
	c_double c;
	c_double z;
	c.r = model->c.x; //model->z_init.r;
	c.i = model->c.y; //model->z_init.i;
	// printf("x : %f | y : %f \n", c.r, c.i);
	z.r = x;
	z.i = y;
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

	return (i);
}