/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:29:04 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 18:53:08 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute(t_model *m)
{
	if (m->color_algo_id == 13)
		compute_values_histo(*m, m->formula, m->values);
	else
		compute_values(*m, m->formula, m->values, m->img);
}

void	compute_HD(t_model *m)
{
	if (m->color_algo_id == 13)
		compute_values_histo(*m, m->formula, m->values_HD);
	else
		compute_values(*m, m->formula, m->values_HD, m->img_HD);
}

void	compute_values(t_model m, int (*formula)(double, double, t_model *), double **values_tab, t_data img)
{
	int			i;
	int			j;
	t_vector	pos;

	i = 0;
	j = 0;
	while (i < img.width)
	{
		j = 0;
		while (j < img.height)
		{
			pos = pixel_to_pos(i, j, m.camera, img);
			values_tab[i][j] = formula(pos.x, pos.y, &m);
			j++;
		}
		i++;
	}
}
