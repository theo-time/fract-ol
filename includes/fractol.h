/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:00:42 by teliet            #+#    #+#             */
/*   Updated: 2022/12/09 19:31:05 by teliet           ###   ########.fr       */
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
# define MAX_ITER 200

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef struct complex_double
{
	double		r;
	double		i;
}				c_double;

typedef struct vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct camera
{
	t_vector	pos;
	t_vector	size;
}				t_camera;

typedef struct Model
{
	double		a;
	int			(*color_algo)(int, int, int, int);
	int		color_algo_id;
	int			color_shift;
	int			color_precision;
	int			*histogram;
	double			*hues;
	unsigned long			histogram_total;
	int			max_iter;
	char		*formula_name;
	double		**values;
	void		*mlx;
	void		*win;
	t_camera	camera;
	t_data		img;
	t_vector	c;
}				t_model;

typedef struct color_params
{
	double		a;
	int			(*color_algo)(int, t_model);
	int			shift;
	int			precision;
}				t_color_params;

// Controller
int				handle_mouse(int keycode, int x, int y, t_model *m);
int				handle_motion(int x, int y, t_model *m);
int				handle_key(int keycode, t_model *m);
int				close_window(t_model *m);
int				close_app(t_model *m);
int				print_params(t_model *model);

// UI
void			print_menu(void);

// Camera
t_vector		pixel_to_pos(int x, int y, t_camera camera);
void 			move_camera(int keycode, t_model *m);
void			zoom_in(t_camera *camera, int x, int y);
void			zoom_out(t_camera *camera, int x, int y);

// Color conversions
int				create_trgb(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);
int				create_HSV(float H, float S, float V);

// Color operations
int				add_shade(int trgb, int shade);

// Coloring algos
int				coloring(int n, t_model *model);
int				neutral(int n, int color_shift, int color_precision,
					int max_iter);
int				one_color_gradient(int n, int color_shift, int color_precision,
					int max_iter);
int				one_color_gradient2(int n, int color_shift, int color_precision,
					int max_iter);
int				multicolor2(int n, int color_shift, int color_precision,
					int max_iter);
int				basic_HSV(int n, int color_shift, int color_precision,
					int max_iter);
int				shaded_HSV(int n, int color_shift, int color_precision,
					int max_iter);
int				rainbow_efficient(int n, int color_shift, int color_precision,
					int max_iter);
int				rainbow_efficient2(int n, int color_shift, int color_precision,
					int max_iter);
int				black_n_white(int n, int color_shift, int color_precision,
					int max_iter);
int				polynomials(int n, int color_shift, int color_precision,
					int max_iter);
int    			histogram(int n, t_model *m);
// Formulas
int				xor_formula(double x, double y, t_model *model);
int				xor_formula_2(double x, double y, t_model *model);
int				mandelbrot(double x, double y, t_model *model);
int				julia(double c_r, double c_i, t_model *model);
int				burning_ship(double c_r, double c_i, t_model *model);

void			render(t_model *m);
void			compute(t_model *m);
#endif