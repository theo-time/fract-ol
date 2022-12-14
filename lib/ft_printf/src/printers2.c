/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:42:17 by teliet            #+#    #+#             */
/*   Updated: 2022/11/16 11:53:23 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list ap)
{
	void	*tmp;

	tmp = va_arg(ap, char *);
	if (tmp == NULL)
		return (ft_putstr_len_fd("(null)", 1));
	else
		return (ft_putstr_len_fd(tmp, 1));
}

int	print_char(va_list ap)
{
	ft_putchar_fd(va_arg(ap, int), 1);
	return (1);
}

int	print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	print_unknown(char c)
{
	ft_putchar_fd('%', 1);
	ft_putchar_fd(c, 1);
	return (2);
}
