/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_formulas.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:56:18 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 18:04:50 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	xor_formula(double x, double y, t_model *model)
{
	int	x_int;
	int	y_int;

	x_int = (int)x;
	y_int = (int)y;
	(void)model;
	return ((x_int ^ y_int));
}

int	xor_formula_2(double x, double y, t_model *model)
{
	int	x_int;
	int	y_int;

	x_int = (int)x;
	y_int = (int)y;
	(void)model;
	return (((x_int - y_int) ^ 3));
}
