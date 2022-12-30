/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:56:07 by theo              #+#    #+#             */
/*   Updated: 2022/12/30 15:55:53 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	complex_abs(t_complex c)
{
	return (sqrt(c.r * c.r + c.i * c.i));
}

int	in_disk(t_complex c)
{
	c.r++;
	return (complex_abs(c) < 0.25);
}

int	in_cardioid(t_complex c)
{
	double	q;

	q = (c.r - 0.25) * (c.r - 0.25) + c.i * c.i;
	return (q * (q + (c.r - 0.25)) < c.i * c.i * 0.25);
}

t_complex divide(t_complex n1, t_complex n2)
{
    t_complex rez;
    rez.r = (n1.r * n2.r + n1.i * n2.i) / (n2.r * n2.r + n2.i * n2.i);
    rez.i = (n1.i * n2.r - n1.r * n2.i) / (n2.r * n2.r + n2.i * n2.i);
    return rez;
}

t_complex mult(t_complex n1, t_complex n2)
{
    t_complex rez;
    rez.r = n1.r * n2.r - n1.i * n2.i;
    rez.i = n1.r * n2.i + n2.r * n1.i;
    return rez;
}


float h2 = 1.5;  // height factor of the incoming light
int angle = 45;  // incoming direction of light
t_complex v;

// incoming light 3D vector = (v.re,v.im,h2)
int R = 100;  // do not take R too small

int	mandelbrot(double c_r, double c_i, t_model *model)
{
	t_complex	c;
	t_complex	z;
	t_complex	der;
	t_complex	new_z;
	t_complex	new_der;
	t_complex	u;
	int			i;
	double		tmp;
	double		t;
    
    v.i = cos(angle);  // unit 2D vector in this direction
    v.r = sin(angle); 
	c.r = c_r;
	c.i = c_i;
    der.r = 1;
    der.i = 0;
	z.r = c_r;
	z.i = c_i;
	i = 0;
	if (in_disk(c) || in_cardioid(c))
		return (model->max_iter);
	while (z.r * z.r + z.i * z.i < 10000 && i < model->max_iter)
	{
		tmp = z.r;
		new_z.r = z.r * z.r - z.i * z.i + c.r;
		new_z.i = 2 * z.i * tmp + c.i;
        new_der.r = 2 * der.r * z.r + 1 - der.i * z.i;
        new_der.i = 2 * ( der.r * z.i +  der.i * z.r  );
        z.r = new_z.r;
        z.i = new_z.i;
        der.r = new_der.r;
        der.i = new_der.i;
		i++;
	}
	if (i == model->max_iter)
		return (model->max_iter);
    u = divide(z, der);
    u.r = u.r / complex_abs(u);
    u.i = u.i / complex_abs(u);
    t = u.r * v.r + u.i * v.i + h2;
    t = t / (float) (1+h2);
	return ((float) model->max_iter * t);
}
