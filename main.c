/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:54:15 by theo              #+#    #+#             */
/*   Updated: 2022/12/30 16:33:52 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_color_algos(t_model *m)
{
	m->color_algos[0] = &neutral;
	m->color_algos[1] = &yellow_bnw;
	m->color_algos[2] = &black_n_white;
	m->color_algos[3] = &one_color_gradient;
	m->color_algos[4] = &one_color_gradient2;
	m->color_algos[5] = &multicolor2;
	m->color_algos[6] = &polynomials_2_colors_tweak;
	m->color_algos[7] = &polynomials_red;
	m->color_algos[8] = &basic_HSV2;
	m->color_algos[9] = &basic_HSV;
	m->color_algos[10] = &shaded_HSV;
	m->color_algos[11] = &shaded_HSV_2;
	m->color_algos[12] = &polynomials;
	m->color_algos[13] = &histogram;
	m->color_algo_id = 14;
	m->color_algo = m->color_algos[m->color_algo_id];
}

void	init_palettes(t_model *m)
{
	// m->palette.size = 2;
	// m->palette.colors[0] = create_trgb(255, 255, 255, 255);
	// m->palette.colors[1] = create_trgb(255, 0, 125, 45);
	// m->palette.colors[2] = create_trgb(255, 0, 0, 0);

	// INFERNO
	m->palette.size = 4;
	m->palette.colors[0] = create_trgb(255, 20, 11, 52);
	m->palette.colors[1] = create_trgb(255, 132, 32, 107);
	m->palette.colors[2] = create_trgb(255, 229, 92, 48);
	m->palette.colors[3] = create_trgb(255, 246, 215, 70);

	// B & W
	m->palette.size = 2;
	m->palette.colors[0] = create_trgb(255, 200, 200, 200);
	m->palette.colors[1] = create_trgb(255, 100, 100, 100);

	// m->palette.size = 4;
	// m->palette.colors[0] = create_trgb(255, 255, 255, 255);
	// m->palette.colors[1] = create_trgb(28, 91, 32, 102);
	// m->palette.colors[2] = create_trgb(255, 31, 24, 110);
	// m->palette.colors[3] = create_trgb(255, 33, 170, 191);
	// m->palette.size = 2;
	// m->palette.colors[0] = create_trgb(255, 214, 246, 94);
	// m->palette.colors[1] = create_trgb(255, 0, 139, 175);
}

void	init_images(t_model *m)
{
	t_data	img;
	t_data	img_hd;

	// Explorer image
	img.img = mlx_new_image(m->mlx, WINDOW_X_SIZE, WINDOW_Y_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	img.width = WINDOW_X_SIZE;
	img.height = WINDOW_Y_SIZE;
	m->img = img;
	// HD image
	img_hd.img = mlx_new_image(m->mlx, HD_X_SIZE, HD_Y_SIZE);
	img_hd.addr = mlx_get_data_addr(img_hd.img, &img_hd.bits_per_pixel,
			&img_hd.line_length, &img_hd.endian);
	img_hd.width = HD_X_SIZE;
	img_hd.height = HD_Y_SIZE;
	m->img_hd = img_hd;
	m->c.x = -0.4f;
	m->c.y = 0.6f;
}

void	init_various_params(t_model *m)
{
	// Common init
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WINDOW_X_SIZE, WINDOW_Y_SIZE, "Explore");
	m->win_hd = NULL;
	m->camera = get_camera(WINDOW_X_SIZE, WINDOW_Y_SIZE);
	m->color_shift = 0;
	m->color_precision = 1;
	m->max_iter = MAX_ITER;
	m->values = get_empty_tab(WINDOW_X_SIZE, WINDOW_Y_SIZE);
	m->values_hd = get_empty_tab(HD_X_SIZE, HD_Y_SIZE);
	m->histogram = malloc(MAX_ITER * sizeof(int));
	m->hues = malloc(MAX_ITER * sizeof(double));
	m->light_angle = 45;
	if (!m->histogram || !m->hues)
		exit(1);
}

int	main(int argc, char **argv)
{
	t_model	m;

	print_menu();
	if (argc < 2)
		return (1);
	m.formula_name = argv[1];
	set_formula(argv[1], &m);
	init_various_params(&m);
	init_images(&m);
	init_color_algos(&m);
	init_palettes(&m);
	// Julia init
	if (m.formula_name[0] == 'J')
	{
		m.camera.pos.x = 0;
		m.camera.pos.y = 0.0f;
	}
	compute(&m);
	render(&m, 0);
	mlx_hook(m.win, 17, 0, close_app, &m);
	mlx_hook(m.win, 2, 1L << 0, handle_key, &m);
	mlx_hook(m.win, 6, 1L << 8, handle_motion, &m);
	mlx_mouse_hook(m.win, handle_mouse, &m);
	mlx_loop(m.mlx);
}
