/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:56:07 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 20:01:59 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	complex_abs(t_complex c)
{
	return (sqrt(c.r * c.r + c.i * c.i));
}

int	in_disk(t_complex c)
{
	c.r++;
	return (complex_abs(c) < 0.25);
}

int	in_cardioid(t_complex c)
{
	double	q;

	q = (c.r - 0.25) * (c.r - 0.25) + c.i * c.i;
	return (q * (q + (c.r - 0.25)) < c.i * c.i * 0.25);
}

int	mandelbrot(double c_r, double c_i, t_model *model)
{
	t_complex	c;
	t_complex	z;
	int			i;
	double		tmp;

	c.r = c_r;
	c.i = c_i;
	z.r = 0;
	z.i = 0;
	i = 0;
	if (in_disk(c) || in_cardioid(c))
		return (model->max_iter);
	while (z.r * z.r + z.i * z.i < 400000 && i < model->max_iter)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	if (i == model->max_iter)
		return (model->max_iter);
	return (i + 1 - log(log2(sqrt(z.r * z.r + z.i * z.i))));
}
