#include "fractol.h"
#include "mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// void	paint_image(t_model m, int (*formula)(double, double, t_model*))
// {
// 	int	i;
// 	int	j;
// 	t_vector pos;

// 	i = 0;
// 	j = 0;
// 	while (i < WINDOW_X_SIZE)
// 	{
// 		j = 0;
// 		while (j < WINDOW_Y_SIZE)
// 		{
// 			pos = pixel_to_pos(i, j, m.camera);
// 			my_mlx_pixel_put(&(m.img), i, j, coloring(m.values[x][y]));
// 			j++;
// 		}
// 		i++;
// 	}
// }

void compute_hues(t_model m)
{
	int i;
	double hue;

	hue = 0;
	i = 0;
	while(i < m.max_iter)
	{
		hue += (float) m.histogram[i] / (float) m.histogram_total;
		// printf("histo : %d / %ld :\n",  m.histogram[i], m.histogram_total);
		// printf("hue : %f \n", hue);
		m.hues[i] = hue;
		i++;
	}
}

unsigned long sum_histogram(t_model m)
{
	int i;
	unsigned long sum;

	i = 0;
	sum = 0;
	while(i < m.max_iter)
	{
		sum += m.histogram[i];
		i++;
	}
	return sum;
}

void reset_histogram(t_model m)
{
	int i;

	i = 0;
	while(i < m.max_iter)
	{
		m.histogram[i] = 0;
		i++;
	}
}


void	compute_values_histo(t_model m, int (*formula)(double, double, t_model*))
{
	int	i;
	int	j;
	int result;
	t_vector pos;

	reset_histogram(m);
	i = 0;
	j = 0;
	while (i < WINDOW_X_SIZE)
	{
		j = 0;
		while (j < WINDOW_Y_SIZE)
		{
			pos = pixel_to_pos(i, j, m.camera);
			result = formula(pos.x, pos.y, &m);
			m.values[i][j] = result;
			if(result < m.max_iter)
				m.histogram[(int) floor(result)] += 1;
			j++;
		}
		i++;
	}
	m.histogram_total = sum_histogram(m);
	compute_hues(m);
}

void	compute_values(t_model m, int (*formula)(double, double, t_model*))
{
	int	i;
	int	j;
	t_vector pos;

	i = 0;
	j = 0;
	while (i < WINDOW_X_SIZE)
	{
		j = 0;
		while (j < WINDOW_Y_SIZE)
		{
			pos = pixel_to_pos(i, j, m.camera);
			m.values[i][j] = formula(pos.x, pos.y, &m);
			j++;
		}
		i++;
	}
}


void	paint_image_true_coord(t_model m, int (*formula)(int, int, t_model*), int (*color_algo)(int, int, int, int))
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
			my_mlx_pixel_put(&(m.img), i, j, color_algo(formula(i, j, &m), 0 , 0, 0));
			j++;
		}
		i++;
	}
}

t_camera	get_camera()
{
	t_camera camera;
	double prop_image = (double) WINDOW_X_SIZE / (double) WINDOW_Y_SIZE;

	camera.pos.x = -0.75f;
	camera.pos.y = 0.0f;

	camera.size.y =  2.4 ;
	camera.size.x = camera.size.y * prop_image;
	return(camera);
}

t_vector		pixel_to_pos(int x, int y, t_camera camera)
{
	t_vector pos;

	pos.x = (double)x / (double) WINDOW_X_SIZE * camera.size.x + camera.pos.x - camera.size.x/2;
	pos.y = (double)y / (double) WINDOW_Y_SIZE * camera.size.y + camera.pos.y - camera.size.y/2;
	return pos;
}

int parameters_msg()
{
	ft_printf("#-------- Fract-Ol Parameters -----------#\n");
	ft_printf("|                                        |\n");
	ft_printf("| 1. Formula :                           |\n");
	ft_printf("|    (M)andelbrot                        |\n");
	ft_printf("|    (J)ulia                             |\n");
	ft_printf("|    (B)urning ship                      |\n");
	ft_printf("|    (X)or gate                          |\n");
	ft_printf("#----------------------------------------#\n");
	return (1);
}

void compute(t_model *m)
{
	if ((m->formula_name)[0] == 'M')
		compute_values_histo(*m, &mandelbrot);
	else if(m->formula_name[0] == 'J')
		compute_values(*m, &julia);
	else if(m->formula_name[0] == 'X')
		compute_values(*m, &xor_formula);
	else if(m->formula_name[0] == 'B')
		compute_values(*m, &burning_ship);
	
}

void render(t_model *m)
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
			my_mlx_pixel_put(&(m->img), i, j, coloring(m->values[i][j], m));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img.img, 0, 0);
}

double	**get_empty_tab(int size_x, int size_y)
{
	double **output;
	int i;

	i= 0;
	output = malloc(size_x * sizeof(double*));
	while(i < size_x)
	{
		output[i] = malloc(size_y * sizeof(double) );
		i++;
	}
	return (output);
}

int	main(int argc, char **argv)
{
	t_model	m;
	t_data	img;

	if(argc < 2)
		return (parameters_msg());
	print_menu();
	// Common init
	m.formula_name = argv[1];
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WINDOW_X_SIZE, WINDOW_Y_SIZE, "Hello world!");
	m.camera = get_camera();
	img.img = mlx_new_image(m.mlx, WINDOW_X_SIZE, WINDOW_Y_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	m.img = img;
	m.color_shift = 0;
	m.color_precision = 1;
	m.max_iter = MAX_ITER;
	m.values = get_empty_tab(WINDOW_X_SIZE, WINDOW_Y_SIZE);
	m.histogram = malloc(MAX_ITER * sizeof(int));
	m.hues = malloc(MAX_ITER * sizeof(double));
	if(!m.histogram || !m.hues)
		return (1);

	// MDB init
	m.c.x = 0;
	m.c.y = 0;
	m.color_algo = &basic_HSV;
	m.color_algo_id = 1;

	// Julia init 
	if(m.formula_name[0] == 'J')
	{
		m.c.x = -0.4f;
		m.c.y = 0.6f;
		m.camera.pos.x = 0;
		m.camera.pos.y = 0.0f;	
	}
	compute(&m);
	render(&m);
	mlx_hook(m.win, 17, 0, close_app, &m);
	mlx_hook(m.win, 2, 1L << 0, handle_key, &m);
	mlx_hook(m.win, 6, 1L<<8, handle_motion, &m);
	mlx_mouse_hook(m.win, handle_mouse, &m);
	mlx_loop(m.mlx);

	// Clean garbage

}
