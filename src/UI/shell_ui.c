/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:39:10 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 19:41:41 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_menu(void)
{
	int		fd;
	char	*line;

	fd = open("./src/UI/Title", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	print_double(double db)
{
	int		units;
	double	db_tmp;
	long	decimals;
	long	digits;

	db_tmp = db;
	if (db < 0)
	{
		db *= -1;
		ft_printf(" -");
	}
	else
		ft_printf(" ");
	units = 0;
	while (db_tmp > 1)
	{
		units++;
		db_tmp /= 10;
	}
	digits = (int)db;
	decimals = (db - (double)digits);
	decimals = db * pow(10, 8);
	ft_printf("%d", digits);
	ft_printf(".");
	ft_printf("%d ", decimals);
}

void	print_params(t_model *model)
{
	ft_printf("\n\n+---------------- Params --------------------+\n");
	ft_printf("fractal         : %s\n", model->formula_name);
	ft_printf("camera_center   : ");
	print_double(model->camera.pos.x);
	print_double(model->camera.pos.x);
	ft_printf("\ncamera_size     : ");
	print_double(model->camera.size.x);
	print_double(model->camera.size.y);
	ft_printf("\ncolor_shift     : %d\n", model->color_shift);
	ft_printf("color_precision : %d\n", model->color_precision);
	ft_printf("max_iter        : %d\n", model->max_iter);
	ft_printf("+--------------------------------------------+\n");
}
