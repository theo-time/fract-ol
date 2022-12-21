/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomials.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:33:42 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 18:34:42 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	polynomials(int n, int color_shift, int color_precision, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	(void)color_shift;
	(void)color_precision;
	t = (double)n / (double)max_iter;
	g = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
	b = 8.5 * pow((1 - t), 3) * t * 255;
	r = 9 * (1 - t) * pow(t, 3) * 255;
	return (((int)r << 16) | ((int)g << 8) | ((int)b));
}


int	polynomials_red(int n, int color_shift, int color_precision, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	(void)color_shift;
	(void)color_precision;
	t = pow(((double)((n * color_precision) % max_iter) / (double)max_iter), 1);
	r = 9 * (1 - t) * pow(t, 3) * 255;
	g = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
	b = 8.5 * pow((1 - t), 3) * t * 255;
	return (((int)r << 16) | ((int)g << 8) | ((int)b));
}

int	polynomials_2_colors_tweak(int n, int color_shift, int color_precision,
		int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	(void)color_shift;
	(void)color_precision;
	t = ((double)n / (double)max_iter);
	r = (int)(9 * (1 - t) * pow(t, 3) * 255 * color_precision) % 255;
	g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255 * color_precision) % 255;
	b = (int)(8.5 * pow((1 - t), 3) * t * 255 * color_precision) % 255;
	return (((int)r << 16) | ((int)g << 8) | ((int)b));
}
