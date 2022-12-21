/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:40:41 by teliet            #+#    #+#             */
/*   Updated: 2022/12/21 18:06:15 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	my_abs(double d)
{
	if (d < 0)
		return (-d);
	else
		return (d);
}

int	burning_ship(double c_r, double c_i, t_model *model)
{
	c_double	c;
	c_double	z;
	int			i;
	double		tmp;

	c.r = c_r;
	c.i = c_i;
	z.r = 0;
	z.i = 0;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < model->max_iter)
	{
		z.r = my_abs(z.r);
		z.i = my_abs(z.i);
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	return (i);
}
