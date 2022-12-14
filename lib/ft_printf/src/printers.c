/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:57:25 by teliet            #+#    #+#             */
/*   Updated: 2022/11/16 11:50:34 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ulong_base(va_list ap, char *base)
{
	void	*tmp;
	int		count;

	count = 0;
	tmp = ft_getnbr_base_unsigned(va_arg(ap, unsigned long), base);
	count = ft_putstr_len_fd(tmp, 1);
	free(tmp);
	return (count);
}

int	print_long_base(va_list ap, char *base)
{
	void	*tmp;
	int		count;

	count = 0;
	tmp = ft_getnbr_base_signed(va_arg(ap, long), base);
	count = ft_putstr_len_fd(tmp, 1);
	free(tmp);
	return (count);
}

int	print_int_base(va_list ap, char *base)
{
	void	*tmp;
	int		count;

	count = 0;
	tmp = ft_getnbr_base_signed(va_arg(ap, int), base);
	count = ft_putstr_len_fd(tmp, 1);
	free(tmp);
	return (count);
}

int	print_unsigned_base(va_list ap, char *base)
{
	void	*tmp;
	int		count;

	count = 0;
	tmp = ft_getnbr_base_unsigned(va_arg(ap, unsigned int), base);
	count = ft_putstr_len_fd(tmp, 1);
	free(tmp);
	return (count);
}

int	print_pointer(va_list ap)
{
	unsigned long	add;
	int				count;
	void			*tmp;

	count = 0;
	add = va_arg(ap, unsigned long);
	if (add == 0)
		return (ft_putstr_len_fd("(nil)", 1));
	ft_putstr_fd("0x", 1);
	tmp = ft_getnbr_base_unsigned(add, "0123456789abcdef");
	count = ft_putstr_len_fd(tmp, 1) + 2;
	free(tmp);
	return (count);
}
