/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow_efficient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:31:18 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 18:40:55 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rainbow_efficient(int n, int color_shift, int color_precision, int max_iter)
{
	int	black;
	int	colors[11];

	(void)color_shift;
	(void)color_precision;
	black = create_trgb(255, 0, 0, 0);
	colors[0] = create_trgb(255, 255, 0, 0);
	colors[1] = create_trgb(255, 255, 128, 0);
	colors[2] = create_trgb(255, 128, 255, 0);
	colors[3] = create_trgb(255, 0, 255, 0);
	colors[4] = create_trgb(255, 0, 255, 128);
	colors[5] = create_trgb(255, 0, 255, 255);
	colors[6] = create_trgb(255, 0, 128, 255);
	colors[7] = create_trgb(255, 0, 0, 255);
	colors[8] = create_trgb(255, 127, 0, 255);
	colors[9] = create_trgb(255, 255, 0, 255);
	colors[10] = create_trgb(255, 255, 0, 127);
	if (n == max_iter)
		return (black);
	return (colors[(5 + (int)(((float)n / (float)max_iter) * 11.0f)) % 11]);
}

int	rainbow_efficient2(int n, int color_shift, int color_precision,
		int max_iter)
{
	int	black;
	int	color1;
	int	color2;
	int	color3;
	int	color4;
	int	color5;
	int	color6;
	int	color7;
	int	color8;
	int	color9;
	int	color10;
	int	color11;

	(void)color_shift;
	(void)color_precision;
	black = create_trgb(255, 0, 0, 0);
	color1 = create_trgb(255, 255, 0, 0);
	color2 = create_trgb(255, 255, 128, 0);
	color3 = create_trgb(255, 128, 255, 0);
	color4 = create_trgb(255, 0, 255, 0);
	color5 = create_trgb(255, 0, 255, 128);
	color6 = create_trgb(255, 0, 255, 255);
	color7 = create_trgb(255, 0, 128, 255);
	color8 = create_trgb(255, 0, 0, 255);
	color9 = create_trgb(255, 127, 0, 255);
	color10 = create_trgb(255, 255, 0, 255);
	color11 = create_trgb(255, 255, 0, 127);
	if (n == max_iter)
		return (black);
	n = (n + 50) % max_iter;
	if (n < 5)
		return (color1);
	else if (n < (float)10 / (float)100 * max_iter)
		return (color2);
	else if (n < (float)20 / (float)100 * max_iter)
		return (color3);
	else if (n < (float)30 / (float)100 * max_iter)
		return (color4);
	else if (n < (float)40 / (float)100 * max_iter)
		return (color5);
	else if (n < (float)50 / (float)100 * max_iter)
		return (color6);
	else if (n < (float)60 / (float)100 * max_iter)
		return (color7);
	else if (n < (float)70 / (float)100 * max_iter)
		return (color8);
	else if (n < (float)80 / (float)100 * max_iter)
		return (color9);
	else if (n < (float)90 / (float)100 * max_iter)
		return (color10);
	else
		return (color11);
	return (create_trgb(255, 255, 0, 127));
}

int	rainbow_efficient3(int n, int color_shift, int color_precision,
		int max_iter)
{
	(void)color_shift;
	(void)color_precision;
	// n = (model->max_iter - n) % model->max_iter;
	if (n == max_iter)
		return (create_trgb(255, 0, 0, 0));
	else if (n < 60)
		return (create_trgb(255, 255, 0, 0));
	else if (n < 70)
		return (create_trgb(255, 255, 128, 0));
	else if (n < 80)
		return (create_trgb(255, 0, 255, 0));
	else if (n < 90)
		return (create_trgb(255, 0, 128, 255));
	else if (n < (5 / 5) * max_iter)
		return (create_trgb(255, 255, 0, 255));
	return (create_trgb(255, 255, 0, 127));
}
