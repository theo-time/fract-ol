/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:56:07 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 20:01:59 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	binary_mandelbrot(double c_r, double c_i, t_model *model)
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
	if (0 < z.i)
		return (i + 1 - log(log2(sqrt(z.r * z.r + z.i * z.i))));
	else
		return ((i + 1 - log(log2(sqrt(z.r * z.r + z.i * z.i)))) / 2);
}
