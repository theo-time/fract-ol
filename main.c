#include "fractol.h"
#include "mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	compute_hues(t_model m)
{
	int		i;
	double	hue;

	hue = 0;
	i = 0;
	while (i < m.max_iter)
	{
		hue += (float)m.histogram[i] / (float)m.histogram_total;
		// printf("histo : %d / %ld :\n",  m.histogram[i], m.histogram_total);
		// printf("hue : %f \n", hue);
		m.hues[i] = hue;
		i++;
	}
}

unsigned long	sum_histogram(t_model m)
{
	int				i;
	unsigned long	sum;

	i = 0;
	sum = 0;
	while (i < m.max_iter)
	{
		sum += m.histogram[i];
		i++;
	}
	return (sum);
}

void	reset_histogram(t_model m)
{
	int	i;

	i = 0;
	while (i < m.max_iter)
	{
		m.histogram[i] = 0;
		i++;
	}
}

void	compute_values_histo(t_model m, int (*formula)(double, double,
			t_model *), double **values_tab)
{
	int			i;
	int			j;
	int			result;
	t_vector	pos;

	reset_histogram(m);
	i = 0;
	j = 0;
	while (i < WINDOW_X_SIZE)
	{
		j = 0;
		while (j < WINDOW_Y_SIZE)
		{
			pos = pixel_to_pos(i, j, m.camera, m.img);
			result = formula(pos.x, pos.y, &m);
			values_tab[i][j] = result;
			if (result < m.max_iter)
				m.histogram[(int)floor(result)] += 1;
			j++;
		}
		i++;
	}
	m.histogram_total = sum_histogram(m);
	compute_hues(m);
}

void	compute_values(t_model m, int (*formula)(double, double, t_model *), double **values_tab, t_data img)
{
	int			i;
	int			j;
	t_vector	pos;

	i = 0;
	j = 0;
	while (i < img.width)
	{
		j = 0;
		while (j < img.height)
		{
			pos = pixel_to_pos(i, j, m.camera, img);
			values_tab[i][j] = formula(pos.x, pos.y, &m);
			j++;
		}
		i++;
	}
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

t_vector	pixel_to_pos(int x, int y, t_camera camera, t_data img)
{
	t_vector	pos;

	pos.x = (double)x / (double)img.width * camera.size.x + camera.pos.x
		- camera.size.x / 2;
	pos.y = (double)y / (double)img.height * camera.size.y + camera.pos.y
		- camera.size.y / 2;
	return (pos);
}

void	compute(t_model *m)
{
	if (m->color_algo_id == 13)
		compute_values_histo(*m, m->formula, m->values);
	else
		compute_values(*m, m->formula, m->values, m->img);
}

void	compute_HD(t_model *m)
{
	if (m->color_algo_id == 13)
		compute_values_histo(*m, m->formula, m->values_HD);
	else
		compute_values(*m, m->formula, m->values_HD, m->img_HD);
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

void	render(t_model *m, int hd)
{
	if(hd)
		paint_window(m , m->win_HD, m->img_HD, m->values_HD);
	else
		paint_window(m , m->win, m->img, m->values);
}


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

int	main(int argc, char **argv)
{
	t_model	m;
	t_data	img;
	t_data	img_HD;

	print_menu();

	if (argc < 2)
		return (1);
	
	// Common init
	m.formula_name = argv[1];
	set_formula(argv[1], &m);
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WINDOW_X_SIZE, WINDOW_Y_SIZE, "Explore");
	m.camera = get_camera(WINDOW_X_SIZE, WINDOW_Y_SIZE);

	// explorer image 
	img.img = mlx_new_image(m.mlx, WINDOW_X_SIZE, WINDOW_Y_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	m.img = img;
	m.img.width = WINDOW_X_SIZE;
	m.img.height = WINDOW_Y_SIZE;

	// HD image
	img_HD.img = mlx_new_image(m.mlx, HD_X_SIZE, HD_Y_SIZE);
	img_HD.addr = mlx_get_data_addr(img_HD.img, &img_HD.bits_per_pixel, &img_HD.line_length,
			&img_HD.endian);
	m.img_HD = img_HD;
	m.img_HD.width = HD_X_SIZE;
	m.img_HD.height = HD_Y_SIZE;

	m.color_shift = 0;
	m.color_precision = 1;
	m.max_iter = MAX_ITER;
	m.values = get_empty_tab(WINDOW_X_SIZE, WINDOW_Y_SIZE);
	m.values_HD = get_empty_tab(HD_X_SIZE, HD_Y_SIZE);
	m.histogram = malloc(MAX_ITER * sizeof(int));
	m.hues = malloc(MAX_ITER * sizeof(double));
	if (!m.histogram || !m.hues)
		return (1);
	m.color_algos[0] = &neutral;
	m.color_algos[1] = &yellow_BnW;
	m.color_algos[2] = &black_n_white;
	m.color_algos[3] = &one_color_gradient;
	m.color_algos[4] = &one_color_gradient2;
	m.color_algos[5] = &multicolor2;
	m.color_algos[6] = &polynomials_2_colors_tweak;
	m.color_algos[7] = &polynomials_red;
	m.color_algos[8] = &basic_HSV2;
	m.color_algos[9] = &basic_HSV;
	m.color_algos[10] = &shaded_HSV;
	m.color_algos[11] = &shaded_HSV_2;
	m.color_algos[12] = &polynomials;
	m.color_algos[13] = &histogram;

	// MDB init
	m.c.x = 0;
	m.c.y = 0;
	m.color_algo_id = 8;
	m.color_algo = m.color_algos[m.color_algo_id];

	// Julia init
	if (m.formula_name[0] == 'J')
	{
		m.c.x = -0.4f;
		m.c.y = 0.6f;
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
	// Clean garbage
}
