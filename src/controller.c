/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:39:48 by teliet            #+#    #+#             */
/*   Updated: 2022/12/09 18:00:41 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int keycode, int x, int y, t_model *m)
{
	// printf("%d\n", keycode);
	if (keycode == 5)
		zoom_out(&(m->camera), x, y);
	if (keycode == 4)
		zoom_in(&(m->camera), x, y);
	// m->c = pixel_to_pos(x, y, m->camera);
	compute(m);
	render(m);
	return (0);
}

// Allows the user to set the value of c constant with mouse and right click
int	handle_motion(int x, int y, t_model *m)
{
	t_vector mouse_pos;
	mouse_pos = pixel_to_pos(x, y, m->camera);

    m->c = pixel_to_pos(x, y, m->camera);
	compute(m);
	render(m);
	return (0);
}

void free_tab(t_model *model)
{
	int i;

	i = 0;
	while(i < WINDOW_X_SIZE)
	{
		free(model->values[i]);
		i++;
	}
	free(model->values);
}

int close_app(t_model *m)
{
	free_tab(m);
	mlx_destroy_window(m->mlx, m->win);
	mlx_destroy_image(m->mlx, m->img.img);
	mlx_destroy_display(m->mlx);
	free(m->mlx);
	free(m->histogram);
	free(m->hues);
	exit(0);
}

int close_window(t_model *m)
{
	mlx_destroy_window(m->mlx, m->win);
}

int change_color_shift(int keycode, t_model *model)
{
	if (keycode == 100)
		model->color_shift = (model->color_shift + 1) % model->max_iter;
	if (keycode == 97 )
		model->color_shift = (model->color_shift - 1) % model->max_iter;
	
	if(model->color_shift == 0)
		model->color_shift = model->max_iter;
	// printf("color shift : %d \n",  model->color_shift);
	render(model);
}

int change_color_precision(int keycode, t_model *model)
{
	// printf("color precision : %d\n", model->color_precision );
	if (keycode == 119)
		model->color_precision = (model->color_precision + 1);
	if (keycode == 115 && 1 < model->color_precision)
		model->color_precision = (model->color_precision - 1);
	// printf("color shift : %d \n",  model->color_shift);
	render(model);
}

int change_max_iter(int keycode, t_model *model)
{
	if (keycode == 114)
		model->max_iter = (model->max_iter + 10);
	if (keycode == 102 && 1 < model->max_iter)
		model->max_iter = (model->max_iter - 10);
	
	free(model->histogram);
	model->histogram = malloc(model->max_iter * sizeof(int));

	free(model->hues);
	model->hues = malloc(model->max_iter * sizeof(double));

	compute(model);
	render(model);
}

int	handle_key(int keycode, t_model *model)
{
	// printf("%d\n", keycode);
	if (keycode == 100 || keycode == 97)
		change_color_shift( keycode, model);
	
	if (keycode == 119 || keycode == 115)
		change_color_precision( keycode, model);

	if (keycode == 102 || keycode == 114)
		change_max_iter( keycode, model);

	if (keycode == 32)
		print_params(model);

	if (keycode == 65307)
		close_app(model);

	else if(65361 <= keycode && keycode <= 65364)
		move_camera(keycode, model);
		
	return (0);
}
int print_double(double db)
{
	int units;
	double db_tmp = db;
	long decimals;
	long digits;

	// printf("\n-------------\n");
	
	// printf("double : %.16f\n",db);
	
	if( db < 0)
	{
		db *= -1;
		ft_printf(" -");
	}
	else
		ft_printf(" ");

	units = 0;
	while(db_tmp > 1)
	{
		units++;
		db_tmp /= 10;
	}
	digits = (int) db;
	decimals = (db - (double) digits);
	decimals = db * pow(10,8);
	ft_printf("%d", digits);
	ft_printf(".");
	ft_printf("%d ", decimals);
}

int	print_params(t_model *model)
{
	ft_printf("\n\n+---------------- Params --------------------+\n");
	ft_printf("fractal         : %s\n",  model->formula_name);
	ft_printf("camera_center   : ");
	print_double(model->camera.pos.x);
	print_double(model->camera.pos.x);
	ft_printf("\ncamera_size     : ");
	print_double(model->camera.size.x);
	print_double(model->camera.size.y);
	ft_printf("\ncolor_shift     : %d\n",  model->color_shift);
	ft_printf("color_precision : %d\n",  model->color_precision);
	ft_printf("max_iter        : %d\n",  model->max_iter);
	ft_printf("+--------------------------------------------+\n");
}