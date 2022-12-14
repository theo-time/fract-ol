/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:40:41 by teliet            #+#    #+#             */
/*   Updated: 2022/12/09 12:40:43 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double my_abs(double d)
{
    if( d < 0)
        return -d;
    else
        return d;
}

int	burning_ship(double c_r, double c_i, t_model *model)
{
	(void) model;
	c_double c;
	c_double z;
	c.r = c_r;
	c.i = c_i;
	// printf("x : %f | y : %f \n", c.r, c.i);
	z.r = 0;
	z.i = 0;
	int i = 0;
	double tmp;

	while (z.r * z.r + z.i * z.i < 4 && i < model->max_iter)
	{
        z.r = my_abs(z.r);
        z.i = my_abs(z.i);
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
		// printf("x : %d | y : %d --> i : %d\n", x, y, i);
	}

	return (i);
}