/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:30:51 by theo              #+#    #+#             */
/*   Updated: 2022/12/21 20:50:50 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

h2 = 1.5  // height factor of the incoming light
angle = 45  // incoming direction of light
t_vector v;
v.x = cos(angle)  // unit 2D vector in this direction
v.x = sin(angle)  
// incoming light 3D vector = (v.re,v.im,h2)
R = 100  // do not take R too small

int	normal_map(int n, t_model *m)
{


}