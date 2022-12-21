/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_algos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:30:49 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 20:24:46 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	coloring(int n, t_model *model)
{
	if (n < model->max_iter)
	{
		// Smootheming
		n = pow(n, 1);
		// Color shift
		n = (n + model->color_shift) % model->max_iter;
		// Color precision adjust
		n = n * model->color_precision % model->max_iter;
	}
	if (model->color_algo_id == 13)
		return (histogram(n, model));
	if (model->color_algo_id == 14)
		return (palette_coloring_smooth(n, model));
	return ((model->color_algo)(n, model->color_shift, model->color_precision,
		model->max_iter));
}

int	neutral(int n, int color_shift, int color_precision, int max_iter)
{
	(void)max_iter;
	(void)color_shift;
	(void)color_precision;
	return (n);
}

int	yellow_bnw(int n, int color_shift, int color_precision, int max_iter)
{
	int	r;
	int	g;
	int	b;

	(void)color_shift;
	(void)color_precision;
	r = 255 - ((float)n * 10 / (float)max_iter) * 255;
	g = 255 - ((float)n * 10 / (float)max_iter) * 255;
	b = 255 - ((float)n * 10 / (float)max_iter) * 255;
	return (create_trgb(255, r, g, b));
}

int	black_n_white(int n, int color_shift, int color_precision, int max_iter)
{
	int	r;
	int	g;
	int	b;

	(void)color_shift;
	(void)color_precision;
	r = (int)(((float)(n) / (float)max_iter) * 255) % 255;
	g = (int)(((float)(n) / (float)max_iter) * 255) % 255;
	b = (int)(((float)(n) / (float)max_iter) * 255) % 255;
	return (create_trgb(255, r, g, b));
}

int	one_color_gradient(int n, int color_shift, int color_precision,
		int max_iter)
{
	int	r;
	int	g;
	int	b;

	(void)max_iter;
	(void)color_shift;
	(void)color_precision;
	r = 255 - n * 255 / 100;
	g = 0;
	b = 0;
	return (create_trgb(255, r, g, b));
}

int	one_color_gradient2(int n, int color_shift, int color_precision,
		int max_iter)
{
	int	r;
	int	g;
	int	b;

	(void)color_shift;
	(void)color_precision;
	r = (float)(n * n) / (float)(max_iter * max_iter) * 255;
	g = 0;
	b = 0;
	if (n == max_iter)
		return (create_trgb(255, 0, 0, 0));
	return (create_trgb(255, r, g, b));
}

int	multicolor2(int n, int color_shift, int color_precision, int max_iter)
{
	int	r;
	int	g;
	int	b;

	(void)max_iter;
	(void)color_shift;
	(void)color_precision;
	r = n * 1000 % 255;
	g = n % 255;
	b = n * 1000 % 255;
	return (create_trgb(255, r, g, b));
}

float	lerp(float color1, float color2, int t)
{
	return (color1 * (float)(1 - t) + (float)color2 * t);
}
