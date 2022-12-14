
#include "fractol.h"

int	xor_formula(double x, double y, t_model *model)
{
	int x_int = (int) x;
	int y_int = (int) y;
	(void) model;
	return ((x_int ^ y_int));
}

int	xor_formula_2(double x, double y, t_model *model)
{
	int x_int = (int) x;
	int y_int = (int) y;
	(void) model;
	return (((x_int - y_int) ^ 3));
}