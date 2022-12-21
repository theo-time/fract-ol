/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_hsv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:32:25 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 18:32:53 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	basic_HSV(int m, int color_shift, int color_precision, int max_iter)
{
	float	hue;
	int		saturation;
	int		value;

	(void)color_shift;
	(void)color_precision;
	if (m == max_iter)
		return (create_trgb(255, 0, 0, 0));
	hue = (int)(360 * ((float)m / (float)max_iter)) % 360;
	//ft_printf("m : %f / hue : %d", m, hue);
	if (hue < 0)
		hue = (360 + hue);
	//ft_printf(" / m : %f / hue : %d \n", m, hue);
	saturation = 100;
	// printf("%d\n", m);
	if (m < max_iter)
		value = 100;
	else
		value = 0;
	return (create_hsv(hue, saturation, value));
}

int	basic_HSV2(int m, int color_shift, int color_precision, int max_iter)
{
	float	hue;
	int		saturation;
	int		value;

	(void)color_shift;
	(void)color_precision;
	if (m == max_iter)
		return (create_trgb(255, 0, 0, 0));
	hue = (int)(360.f * powf((float)m / (float)max_iter, 1.5f)) % 360;
	//ft_printf("m : %f / hue : %d", m, hue);
	if (hue < 0)
		hue = (360 + hue);
	//ft_printf(" / m : %f / hue : %d \n", m, hue);
	saturation = 100;
	// printf("%d\n", m);
	if (m < max_iter)
		value = 100; //((float) m / (float) max_iter) * 100.f;
	else
		value = 0;
	return (create_hsv(hue, saturation, value));
}

int	shaded_HSV(int m, int color_shift, int color_precision, int max_iter)
{
	int	hue;
	int	saturation;
	int	value;

	(void)color_shift;
	(void)color_precision;
	if (m == max_iter)
		return (create_trgb(255, 0, 0, 0));
	// m = (m + model->color_shift + model->max_iter) % model->max_iter;
	hue = 100 + 100.0f * ((float)m / (float)max_iter);
	saturation = (100.0f * ((float)m / (float)max_iter));
	// printf("%d\n", m);
	if (m < max_iter)
		value = (int)(100.0f - 50.0f * ((float)m / (float)max_iter)) % 100;
	else
		value = 0;
	if (hue < 0)
		hue = (360 + hue);
	if (saturation < 0)
		saturation = (100 + saturation);
	if (value < 0)
		value = (100 + value);
	return (create_hsv(hue, saturation, value));
}

int	shaded_HSV_2(int m, int color_shift, int color_precision, int max_iter)
{
	int	hue;
	int	saturation;
	int	value;

	(void)color_shift;
	(void)color_precision;
	if (m == max_iter)
		return (create_trgb(255, 0, 0, 0));
	hue = 100; //(360.0f * ((float) m / (float) model->max_iter));
	saturation = (100.0f * ((float)m / (float)max_iter));
	// printf("%d\n", m);
	if (m < max_iter)
		value = (m * 5) % 100;
	else
		value = 0;
	if (hue < 0)
		hue = (360 + hue);
	if (saturation < 0)
		saturation = (100 + saturation);
	if (value < 0)
		value = (100 + value);
	return (create_hsv(hue, saturation, value));
}