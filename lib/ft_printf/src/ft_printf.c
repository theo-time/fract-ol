/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:36 by teliet            #+#    #+#             */
/*   Updated: 2022/11/16 11:52:53 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(va_list ap, char c)
{
	if (c == 'c')
		return (print_char(ap));
	else if (c == 's')
		return (print_string(ap));
	else if (c == 'p')
		return (print_pointer(ap));
	else if (c == 'd')
		return (print_int_base(ap, "0123456789"));
	else if (c == 'i')
		return (print_int_base(ap, "0123456789"));
	else if (c == 'u')
		return (print_unsigned_base(ap, "0123456789"));
	else if (c == 'x')
		return (print_unsigned_base(ap, "0123456789abcdef"));
	else if (c == 'X')
		return (print_unsigned_base(ap, "0123456789ABCDEF"));
	else if (c == '%')
		return (print_percent());
	else
		return (print_unknown(c));
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += print_arg(ap, str[i + 1]);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
			i++;
		}
	}
	va_end(ap);
	return (count);
}
