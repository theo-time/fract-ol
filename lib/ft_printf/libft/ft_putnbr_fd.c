/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:57:11 by teliet            #+#    #+#             */
/*   Updated: 2022/11/14 14:47:50 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_int(long n, int fd)
{
	long	unit;
	long	quotient;

	quotient = n / 10;
	unit = n % 10 + 48;
	if (quotient > 0)
	{
		print_int(quotient, fd);
	}
	write(fd, &unit, 1);
}

void	ft_putnbr_fd(long nb, int fd)
{
	long	nl;

	nl = nb;
	if (nl < 0)
	{
		nl *= -1;
		write(fd, "-", 1);
	}
	print_int(nl, fd);
}
