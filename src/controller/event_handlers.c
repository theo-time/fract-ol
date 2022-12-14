/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:39:48 by teliet            #+#    #+#             */
/*   Updated: 2022/12/30 17:42:00 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int keycode, int x, int y, t_model *m)
{
	if (keycode == 5)
		zoom_out(&(m->camera), x, y);
	if (keycode == 4)
		zoom_in(m, &(m->camera), x, y);
	compute(m);
	render(m, 0);
	return (0);
}

t_complex get_light_vector(int x, int y)
{
	t_complex v;
	double magnitude;

	v.r = x - (float) WINDOW_X_SIZE / 2;
	v.i = y - (float) WINDOW_Y_SIZE / 2;
	magnitude = sqrt(v.r * v.r + v.i * v.i);
	v.r /= magnitude;
	v.i /= magnitude;
	return v;
}

int	handle_motion(int x, int y, t_model *m)
{
	if((m->formula_name)[0] == 'J')
		m->c = pixel_to_pos(x, y, m->camera, m->img);
	else
		m->light_vector = get_light_vector(x, y);
	compute(m);
	render(m, 0);
	return (1);
}

int	handle_key(int keycode, t_model *model)
{
	printf("%d\n", keycode);
	if (keycode == 100 || keycode == 97)
		change_color_shift(keycode, model);
	if (keycode == 119 || keycode == 115)
		change_color_precision(keycode, model);
	if (keycode == 102 || keycode == 114 || keycode == 103 || keycode == 116)
		change_max_iter(keycode, model);
	if (keycode == 120 || keycode == 122)
		change_color_algo(keycode, model);
	if (keycode == 32)
		print_params(model);
	if (keycode == 117)
		upscale(model);
	if (keycode == 65307)
		close_app(model);
	else if (65361 <= keycode && keycode <= 65364)
		move_camera(keycode, model);
	return (0);
}
