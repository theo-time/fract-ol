/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:00:42 by teliet            #+#    #+#             */
/*   Updated: 2022/12/30 16:29:26 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./ft_printf.h"
# include "./libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <sys/stat.h>
# include <sys/types.h>

# define WINDOW_X_SIZE 720
# define WINDOW_Y_SIZE 480
// # define WINDOW_X_SIZE 2400
// # define WINDOW_Y_SIZE 1340
# define HD_X_SIZE 1440
# define HD_Y_SIZE 960
# define MAX_ITER 200
# define COLOR_ALGOS_NB 15

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_data;

typedef struct complex_double
{
	double			r;
	double			i;
}					t_complex;

typedef struct vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct camera
{
	t_vector		pos;
	t_vector		size;
}					t_camera;

typedef struct palette
{
	int				size;
	int				colors[10];
}					t_palette;

typedef struct Model
{
	double			a;
	int				(*color_algo)(int, int, int, int);
	void			*color_algos[COLOR_ALGOS_NB];
	int				color_algo_id;
	int				color_shift;
	int				color_precision;
	int				*histogram;
	double			*hues;
	unsigned long	histogram_total;
	t_palette		palettes[3];
	t_palette		palette;
	int				max_iter;
	char			*formula_name;
	void			*formula;
	void			*mlx;
	void			*win;
	double			**values;
	void			*win_hd;
	double			**values_hd;
	int				light_angle;
	t_camera		camera;
	t_data			img;
	t_data			img_hd;
	t_vector		c;
}					t_model;

typedef struct color_params
{
	double			a;
	int				(*color_algo)(int, t_model);
	int				shift;
	int				precision;
}					t_color_params;

// Init
double				**get_empty_tab(int size_x, int size_y);
t_camera			get_camera(int width, int height);
void				set_formula(char *formula_name, t_model *m);

// Event handler
int					handle_mouse(int keycode, int x, int y, t_model *m);
int					handle_motion(int x, int y, t_model *m);
int					handle_key(int keycode, t_model *m);

// Controls
void				close_window(t_model *m);
int					close_app(t_model *m);
int					close_window_hd(t_model *m);
void				change_color_algo(int keycode, t_model *model);
void				change_color_shift(int keycode, t_model *model);
void				change_color_precision(int keycode, t_model *model);
void				change_max_iter(int keycode, t_model *model);
void				upscale(t_model *m);

// Shell UI
void				print_menu(void);
void				print_params(t_model *model);

// Camera
t_vector			pixel_to_pos(int x, int y, t_camera camera, t_data img);
void				move_camera(int keycode, t_model *m);
void				zoom_in(t_model *m, t_camera *camera, int x, int y);
void				zoom_out(t_camera *camera, int x, int y);

// Color conversions
int					create_trgb(int t, int r, int g, int b);
int					get_t(int trgb);
int					get_r(int trgb);
int					get_g(int trgb);
int					get_b(int trgb);
int					create_hsv(float H, float S, float V);

// Color operations
int					add_shade(int trgb, int shade);
float				lerp(float color1, float color2, int t);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);

// Coloring algos
int					coloring(int n, t_model *model);
int					neutral(int n, int color_shift, int color_precision,
						int max_iter);
int					one_color_gradient(int n, int color_shift,
						int color_precision, int max_iter);
int					one_color_gradient2(int n, int color_shift,
						int color_precision, int max_iter);
int					multicolor2(int n, int color_shift, int color_precision,
						int max_iter);
int					basic_HSV(int n, int color_shift, int color_precision,
						int max_iter);
int					basic_HSV2(int m, int color_shift, int color_precision,
						int max_iter);
int					shaded_HSV(int n, int color_shift, int color_precision,
						int max_iter);
int					shaded_HSV_2(int m, int color_shift, int color_precision,
						int max_iter);
int					rainbow_efficient(int n, int color_shift,
						int color_precision, int max_iter);
int					rainbow_efficient2(int n, int color_shift,
						int color_precision, int max_iter);
int					black_n_white(int n, int color_shift, int color_precision,
						int max_iter);
int					polynomials(int n, int color_shift, int color_precision,
						int max_iter);
int					polynomials_red(int n, int color_shift, int color_precision,
						int max_iter);
int					polynomials_2_colors_tweak(int n, int color_shift,
						int color_precision, int max_iter);
int					histogram(int n, t_model *m);
int					yellow_bnw(int n, int color_shift, int color_precision,
						int max_iter);
int					rainbow_efficient3(int n, int color_shift,
						int color_precision, int max_iter);
int					palette_coloring(int n, t_model *m);
int					palette_coloring_smooth(int n, t_model *m);
int					normal_map(int n, t_model *m);

// Complex plane maths
double				complex_abs(t_complex c);
int					in_disk(t_complex c);
int					in_cardioid(t_complex c);

// Formulas
int					xor_formula(double x, double y, t_model *model);
int					xor_formula_2(double x, double y, t_model *model);
int					mandelbrot(double x, double y, t_model *model);
int					julia(double c_r, double c_i, t_model *model);
int					burning_ship(double c_r, double c_i, t_model *model);
int					mandelbrot_strange(double c_r, double c_i, t_model *model);
int					inverse_mandelbrot(double c_r, double c_i, t_model *model);
int					binary_mandelbrot(double c_r, double c_i, t_model *model);

// Render & array computations
void				paint_window(t_model *m, void *win, t_data img,
						double **values);
void				render(t_model *m, int HD);
void				compute(t_model *m);
void				compute_hd(t_model *m);
void				compute_values(t_model m, int (*formula)(double, double,
							t_model *), double **values_tab, t_data img);
void				compute_values_histo(t_model m, int (*formula)(double,
							double, t_model *), double **values_tab);
void				compute_hues(t_model m);

#endif