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
		zoom_in(m, &(m->camera), x, y);
	// m->c = pixel_to_pos(x, y, m->camera);
	compute(m);
	render(m,0);
	return (0);
}

// Allows the user to set the value of c constant with mouse and right click
int	handle_motion(int x, int y, t_model *m)
{
    m->c = pixel_to_pos(x, y, m->camera, m->img);
	compute(m);
	render(m,0);
	return(1);
}

void free_tab(double **values, int width)
{
	int i;

	i = 0;
	while(i < width)
	{
		free(values[i]);
		i++;
	}
	free(values);
}

int close_app(t_model *m)
{
	mlx_destroy_window(m->mlx, m->win);
	if(m->win_HD)
		mlx_destroy_window(m->mlx, m->win_HD);
	mlx_destroy_image(m->mlx, m->img.img);
	mlx_destroy_image(m->mlx, m->img_HD.img);
	mlx_destroy_display(m->mlx);
	free(m->mlx);
	free(m->histogram);
	free(m->hues);
	free_tab(m->values, WINDOW_X_SIZE);
	free_tab(m->values_HD, HD_X_SIZE);
	exit(0);
}

int close_window_HD(t_model *m)
{
	mlx_destroy_window(m->mlx, m->win_HD);
	m->win_HD = NULL;
	return(1);
}

void change_color_shift(int keycode, t_model *model)
{
	if (keycode == 100)
		model->color_shift = (model->color_shift + 1) % model->max_iter;
	if (keycode == 97 )
		model->color_shift = (model->color_shift - 1) % model->max_iter;
	
	if(model->color_shift <= 0)
		model->color_shift = model->max_iter;
	// printf("color shift : %d \n",  model->color_shift);
	render(model,0);
}

void change_color_precision(int keycode, t_model *model)
{
	// printf("color precision : %d\n", model->color_precision );
	if (keycode == 119)
		model->color_precision = (model->color_precision + 1);
	if (keycode == 115 && 1 < model->color_precision)
		model->color_precision = (model->color_precision - 1);
	// printf("color shift : %d \n",  model->color_shift);
	render(model,0);
}

void change_max_iter(int keycode, t_model *model)
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
	render(model,0);
}

void change_color_algo(int keycode, t_model *model)
{
	if (keycode == 122)
	{
		model->color_algo_id--;
		if(model->color_algo_id < 0)
			model->color_algo_id = COLOR_ALGOS_NB - 1;
	}
	if (keycode == 120 )
		model->color_algo_id = (model->color_algo_id + 1) % COLOR_ALGOS_NB;

	printf("color algo id : %d\n", model->color_algo_id);
	if(model->color_algo_id == 13)
		compute(model);
	model->color_algo = model->color_algos[model->color_algo_id];
	render(model,0);
}

void upscale(t_model *m)
{
	//mlx_destroy_window(m->mlx, m->win);
	if(!m->win_HD)
	{
		m->win_HD = mlx_new_window(m->mlx, HD_X_SIZE, HD_Y_SIZE, "Final picture");
		mlx_hook(m->win_HD, 17, 0, close_window_HD, m);
	}
	compute_HD(m);
	render(m,1);
}


int	handle_key(int keycode, t_model *model)
{
	printf("%d\n", keycode);
	if (keycode == 100 || keycode == 97)
		change_color_shift( keycode, model);
	
	if (keycode == 119 || keycode == 115)
		change_color_precision( keycode, model);

	if (keycode == 102 || keycode == 114)
		change_max_iter( keycode, model);

	if (keycode == 120 || keycode == 122)
		change_color_algo( keycode, model);

	if (keycode == 32)
		print_params(model);

	if (keycode == 117)
		upscale(model);
		

	if (keycode == 65307)
		close_app(model);

	else if(65361 <= keycode && keycode <= 65364)
		move_camera(keycode, model);
		
	return (0);
}

void print_double(double db)
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

void	print_params(t_model *model)
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