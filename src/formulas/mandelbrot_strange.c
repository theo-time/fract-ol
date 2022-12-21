/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_strange.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:12:19 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 20:01:59 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_strange(double c_r, double c_i, t_model *model)
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
	while (z.r * z.r + z.i * z.i < 4 && i < model->max_iter)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	if (i == model->max_iter)
		return (model->max_iter);
	return (i + 1 - log(log2(abs((int)z.r))));
}
