/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:47:34 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 20:01:13 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_model *m, int hd)
{
	if (hd)
		paint_window(m, m->win_hd, m->img_hd, m->values_hd);
	else
		paint_window(m, m->win, m->img, m->values);
}

t_vector	pixel_to_pos(int x, int y, t_camera camera, t_data img)
{
	t_vector	pos;

	pos.x = (double)x / (double)img.width * camera.size.x + camera.pos.x
		- camera.size.x / 2;
	pos.y = (double)y / (double)img.height * camera.size.y + camera.pos.y
		- camera.size.y / 2;
	return (pos);
}

void	paint_image_true_coord(t_model m, int (*formula)(int, int, t_model *),
		int (*color_algo)(int, int, int, int))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < WINDOW_X_SIZE)
	{
		j = 0;
		while (j < WINDOW_Y_SIZE)
		{
			my_mlx_pixel_put(&(m.img), i, j, color_algo(formula(i, j, &m), 0, 0,
					0));
			j++;
		}
		i++;
	}
}

void	paint_window(t_model *m, void *win, t_data img, double **values)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < img.width)
	{
		j = 0;
		while (j < img.height)
		{
			my_mlx_pixel_put(&img, i, j, coloring(values[i][j], m));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(m->mlx, win, img.img, 0, 0);
}
