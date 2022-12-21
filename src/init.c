/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:30:50 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 17:35:41 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	**get_empty_tab(int size_x, int size_y)
{
	double	**output;
	int		i;

	i = 0;
	output = malloc(size_x * sizeof(double *));
	while (i < size_x)
	{
		output[i] = malloc(size_y * sizeof(double));
		i++;
	}
	return (output);
}

t_camera	get_camera(int width, int height)
{
	t_camera	camera;
	double		prop_image;

	prop_image = (double)width / (double)height;
	camera.pos.x = -0.75f;
	camera.pos.y = 0.0f;
	camera.size.y = 2.4;
	camera.size.x = camera.size.y * prop_image;
	return (camera);
}

void	set_formula(char *formula_name, t_model *m)
{
	if (formula_name[0] == 'M')
		m->formula = &mandelbrot;
	else if (formula_name[0] == 'J')
		m->formula = &julia;
	else if (formula_name[0] == 'X')
		m->formula = &xor_formula;
	else if (formula_name[0] == 'B')
		m->formula = &burning_ship;
	else if (formula_name[0] == 'S')
		m->formula = &mandelbrot_strange;
	else if (formula_name[0] == 'I')
		m->formula = &inverse_mandelbrot;
	else if (formula_name[0] == 'b')
		m->formula = &binary_mandelbrot;
}
