
#include "fractol.h"

int	add_shade(int trgb, int shade)
{
	int r, g, b;

	r = get_t(trgb) * shade;
	g = get_t(trgb) * shade;
	b = get_t(trgb) * shade;

	return (create_trgb(255, r, g, b));
}