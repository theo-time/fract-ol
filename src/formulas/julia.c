/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:10:15 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 20:01:59 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double x, double y, t_model *model)
{
	t_complex	c;
	t_complex	z;
	int			i;
	double		tmp;

	c.r = model->c.x;
	c.i = model->c.y;
	z.r = x;
	z.i = y;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < model->max_iter)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	return (i);
}
