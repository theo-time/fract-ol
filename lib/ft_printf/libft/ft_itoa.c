/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:45:16 by teliet            #+#    #+#             */
/*   Updated: 2022/11/09 17:48:57 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long n)
{
	int	i;

	i = 1;
	while (10 <= n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*get_zero(void)
{
	char	*output;

	output = malloc(2);
	if (!output)
		return (NULL);
	output[0] = '0';
	output[1] = 0;
	return (output);
}

static void	fill_output(char **output, long num, int str_size)
{
	int	i;

	i = str_size - 1;
	while (num > 0)
	{
		(*output)[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
	if (i == 0)
		(*output)[0] = '-';
	(*output)[str_size] = 0;
}

char	*ft_itoa(int n)
{
	long	num;
	int		str_size;
	char	*output;

	str_size = 0;
	num = (long)n;
	if (num == 0)
		return (get_zero());
	if (num < 0)
	{
		num *= -1;
		str_size++;
	}
	str_size += (long)get_size(num);
	output = malloc(str_size + 1);
	if (!output)
		return (NULL);
	fill_output(&output, num, str_size);
	return (output);
}
