/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_converts2.c                                  :+:      :+:    :+:   */
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

int	create_hsv(float H, float S, float V)
{
	float	X;
	int		R;
	int		G;
	int		B;
	float	s;
	float	v;
	float	C;
	float	m;

	if (H > 360 || H < 0 || S > 100 || S < 0 || V > 100 || V < 0)
	{
		printf("The givem HSV values are not in valid range : %f %f %f \n", H,
				S, V);
		exit(0);
		return (create_trgb(255, 30, 30, 30));
	}
	s = (float)S / (float)100;
	v = V / (float)100;
	C = (float)s * (float)v;
	X = C * (float)(1 - double_abs(fmod(H / 60.0f, 2.0f) - 1));
	m = v - C;
	float r, g, b;
	if (H >= 0 && H < 60)
	{
		r = C;
		g = X;
		b = 0;
	}
	else if (H >= 60 && H < 120)
	{
		r = X;
		g = C;
		b = 0;
	}
	else if (H >= 120 && H < 180)
	{
		r = 0;
		g = C;
		b = X;
	}
	else if (H >= 180 && H < 240)
	{
		r = 0;
		g = X;
		b = C;
	}
	else if (H >= 240 && H < 300)
	{
		r = X;
		g = 0;
		b = C;
	}
	else
	{
		r = C;
		g = 0;
		b = X;
	}
	R = (r + m) * 255.0f;
	G = (g + m) * 255.0f;
	B = (b + m) * 255.0f;
	return (create_trgb(255, R, G, B));
}
