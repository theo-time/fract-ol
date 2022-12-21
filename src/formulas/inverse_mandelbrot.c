/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:56:32 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 18:07:51 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	inverse_mandelbrot(double c_r, double c_i, t_model *model)
{
	c_double	c;
	c_double	z;
	int			i;
	double		tmp;

	c.r = c_r / (c_r * c_r + c_i * c_i);
	c.i = c_i / (c_r * c_r + c_i * c_i);
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
	return (i + 1 - log(log2(sqrt(z.r * z.r + z.i * z.i))));
}
