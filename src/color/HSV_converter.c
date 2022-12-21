/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HSV_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:14:41 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 18:29:54 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	double_abs(double db)
{
	if (db < 0)
		return (-db);
	return (db);
}

int	create_hsv(float h, float s, float v)
{
	float	x;
	int		R;
	int		G;
	int		B;
	float	c;
	float	m;

	if (h > 360 || h < 0 || s > 100 || s < 0 || v > 100 || v < 0)
	{
		printf("The givem HSV values are not in valid range : %f %f %f \n", h,
				s, v);
		exit(0);
		return (create_trgb(255, 30, 30, 30));
	}
	c = ((float) s / 100.0f ) * ((float)v / 100.0f);
	x = c * (float)(1 - double_abs(fmod(h / 60.0f, 2.0f) - 1));
	m = ((float)v / 100.0f) - c;
	float r, g, b;
	if (h >= 0 && h < 60)
	{
		r = c;
		g = x;
		b = 0;
	}
	else if (h >= 60 && h < 120)
	{
		r = x;
		g = c;
		b = 0;
	}
	else if (h >= 120 && h < 180)
	{
		r = 0;
		g = c;
		b = x;
	}
	else if (h >= 180 && h < 240)
	{
		r = 0;
		g = x;
		b = c;
	}
	else if (h >= 240 && h < 300)
	{
		r = x;
		g = 0;
		b = c;
	}
	else
	{
		r = c;
		g = 0;
		b = x;
	}
	R = (r + m) * 255.0f;
	G = (g + m) * 255.0f;
	B = (b + m) * 255.0f;
	return (create_trgb(255, R, G, B));
}
