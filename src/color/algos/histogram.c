/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histogram.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:29:55 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 18:39:43 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	histogram(int n, t_model *m)
{
	static float	hue;
	float			saturation;
	float			value;

	hue = 0;
	hue = 360.0f - (360.0f * lerp(m->hues[(int)floor(n)], m->hues[(int)ceil(n)],
				n % 1));
	saturation = 100;
	if (n < m->max_iter)
		value = 100;
	else
		value = 0;
	// if(value == 0)
	// 	printf("%f \n", value);
	return (create_hsv(hue, saturation, value));
}

void	reset_histogram(t_model m)
{
	int	i;

	i = 0;
	while (i < m.max_iter)
	{
		m.histogram[i] = 0;
		i++;
	}
}

unsigned long	sum_histogram(t_model m)
{
	int				i;
	unsigned long	sum;

	i = 0;
	sum = 0;
	while (i < m.max_iter)
	{
		sum += m.histogram[i];
		i++;
	}
	return (sum);
}


void	compute_values_histo(t_model m, int (*formula)(double, double,
			t_model *), double **values_tab)
{
	int			i;
	int			j;
	int			result;
	t_vector	pos;

	reset_histogram(m);
	i = 0;
	j = 0;
	while (i < WINDOW_X_SIZE)
	{
		j = 0;
		while (j < WINDOW_Y_SIZE)
		{
			pos = pixel_to_pos(i, j, m.camera, m.img);
			result = formula(pos.x, pos.y, &m);
			values_tab[i][j] = result;
			if (result < m.max_iter)
				m.histogram[(int)floor(result)] += 1;
			j++;
		}
		i++;
	}
	m.histogram_total = sum_histogram(m);
	compute_hues(m);
}

void	compute_hues(t_model m)
{
	int		i;
	double	hue;

	hue = 0;
	i = 0;
	while (i < m.max_iter)
	{
		hue += (float)m.histogram[i] / (float)m.histogram_total;
		// printf("histo : %d / %ld :\n",  m.histogram[i], m.histogram_total);
		// printf("hue : %f \n", hue);
		m.hues[i] = hue;
		i++;
	}
}
