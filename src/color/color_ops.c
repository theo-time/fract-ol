/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:17:38 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 20:17:44 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	add_shade(int trgb, int shade)
{
	int r, g, b;

	r = get_t(trgb) * shade;
	g = get_t(trgb) * shade;
	b = get_t(trgb) * shade;

	return (create_trgb(255, r, g, b));
}