/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:51:24 by teliet            #+#    #+#             */
/*   Updated: 2022/11/16 11:27:11 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_zero_in_base(char *base)
{
	char	*output;

	output = (char *) malloc(sizeof(char) * 2);
	output[0] = base[0];
	output[1] = 0;
	return (output);
}

static char	*ft_int_base(unsigned long n, char *base, int minus)
{
	int				size;
	unsigned long	n_sizer;
	int				i;
	char			*output;
	unsigned long	nb;

	nb = n;
	n_sizer = ft_strlen(base);
	size = 1;
	while (n_sizer <= n && n_sizer != 0)
	{
		n_sizer *= ft_strlen(base);
		size++;
	}
	output = (char *)malloc(sizeof(char) * (size + minus + 1));
	if (minus)
		output[0] = '-';
	i = size + minus - 1;
	while (nb > 0)
	{
		output[i--] = base[nb % ft_strlen(base)];
		nb = nb / ft_strlen(base);
	}
	output[size + minus] = 0;
	return (output);
}

static int	check_base(char *base)
{
	char	*c1;
	char	*c2;

	c1 = base;
	c2 = base;
	if (ft_strlen(base) <= 1)
		return (0);
	while (*c1)
	{
		if (*c1 == '+' || *c1 == '-')
			return (0);
		c2 = c1 + 1;
		while (*c2)
		{
			if (*c2 == *c1)
				return (0);
			c2++;
		}
		c1++;
	}
	return (1);
}

char	*ft_getnbr_base_signed(long n, char *base_to)
{
	if (!(check_base(base_to)))
		return (NULL);
	if (n == 0)
		return (get_zero_in_base(base_to));
	if (n >= 0)
		return (ft_int_base(n, base_to, 0));
	else
		return (ft_int_base(n * -1, base_to, 1));
}

char	*ft_getnbr_base_unsigned(unsigned long n, char *base_to)
{
	if (!(check_base(base_to)))
		return (NULL);
	if (n == 0)
		return (get_zero_in_base(base_to));
	return (ft_int_base(n, base_to, 0));
}
