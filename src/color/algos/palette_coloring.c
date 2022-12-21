/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_coloring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:34:59 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 20:16:34 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	palette_coloring(int n, t_model *m)
{
	if (n == m->max_iter)
		return (create_trgb(255, 0, 0, 0));
	return (m->palette.colors[((int)(((float)n / (float)m->max_iter)
				* m->palette.size)) % m->palette.size]);
}

float	color_interpolate(int color1, int color2, double t)
{
	int	r;
	int	g;
	int	b;

	r = t * (double)(get_r(color2) - get_r(color1)) + get_r(color1);
	g = t * (double)(get_g(color2) - get_g(color1)) + get_g(color1);
	b = t * (double)(get_b(color2) - get_b(color1)) + get_b(color1);
	return (create_trgb(255, r, g, b));
}

int	palette_coloring_smooth(int n, t_model *m)
{
	int		color1;
	int		color2;
	float	diff;

	color1 = m->palette.colors[(int)(floor((((float)n / (float)m->max_iter)
					* m->palette.size))) % m->palette.size];
	color2 = m->palette.colors[(int)(ceil((((float)n / (float)m->max_iter)
					* m->palette.size))) % m->palette.size];
	diff = fmod((((float)n / (float)m->max_iter) * m->palette.size), 1);
	if (n == m->max_iter)
		return (create_trgb(255, 0, 0, 0));
	return (color_interpolate(color1, color2, diff));
}
