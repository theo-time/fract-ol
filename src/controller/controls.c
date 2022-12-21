/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:48:25 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 20:00:37 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color_algo(int keycode, t_model *model)
{
	if (keycode == 122)
	{
		model->color_algo_id--;
		if (model->color_algo_id < 0)
			model->color_algo_id = COLOR_ALGOS_NB - 1;
	}
	if (keycode == 120)
		model->color_algo_id = (model->color_algo_id + 1) % COLOR_ALGOS_NB;
	printf("color algo id : %d\n", model->color_algo_id);
	if (model->color_algo_id == 13)
		compute(model);
	model->color_algo = model->color_algos[model->color_algo_id];
	render(model, 0);
}

void	change_color_shift(int keycode, t_model *model)
{
	if (keycode == 100)
		model->color_shift = (model->color_shift + 1) % model->max_iter;
	if (keycode == 97)
		model->color_shift = (model->color_shift - 1) % model->max_iter;
	if (model->color_shift <= 0)
		model->color_shift = model->max_iter;
	render(model, 0);
}

void	change_color_precision(int keycode, t_model *model)
{
	if (keycode == 119)
		model->color_precision = (model->color_precision + 1);
	if (keycode == 115 && 1 < model->color_precision)
		model->color_precision = (model->color_precision - 1);
	render(model, 0);
}

void	change_max_iter(int keycode, t_model *model)
{
	if (keycode == 114)
		model->max_iter = (model->max_iter + 10);
	if (keycode == 102 && 1 < model->max_iter)
		model->max_iter = (model->max_iter - 10);
	if (keycode == 116)
		model->max_iter = (model->max_iter + 500);
	if (keycode == 103 && 1 < model->max_iter)
		model->max_iter = (model->max_iter - 500);
	free(model->histogram);
	model->histogram = malloc(model->max_iter * sizeof(int));
	free(model->hues);
	model->hues = malloc(model->max_iter * sizeof(double));
	compute(model);
	render(model, 0);
}

void	upscale(t_model *m)
{
	if (!m->win_hd)
	{
		m->win_hd = mlx_new_window(m->mlx, HD_X_SIZE, HD_Y_SIZE,
				"Final picture");
		mlx_hook(m->win_hd, 17, 0, close_window_hd, m);
	}
	compute_hd(m);
	render(m, 1);
}
