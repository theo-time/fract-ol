/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_app.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:45:23 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 20:01:13 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_tab(double **values, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		free(values[i]);
		i++;
	}
	free(values);
}

int	close_app(t_model *m)
{
	mlx_destroy_window(m->mlx, m->win);
	if (m->win_hd)
		mlx_destroy_window(m->mlx, m->win_hd);
	mlx_destroy_image(m->mlx, m->img.img);
	mlx_destroy_image(m->mlx, m->img_hd.img);
	mlx_destroy_display(m->mlx);
	free(m->mlx);
	free(m->histogram);
	free(m->hues);
	free_tab(m->values, WINDOW_X_SIZE);
	free_tab(m->values_hd, HD_X_SIZE);
	exit(0);
}

int	close_window_hd(t_model *m)
{
	mlx_destroy_window(m->mlx, m->win_hd);
	m->win_hd = NULL;
	return (1);
}
