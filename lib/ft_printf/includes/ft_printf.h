/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:00:42 by teliet            #+#    #+#             */
/*   Updated: 2022/11/16 11:52:19 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putnbr_base(long nbr, char *base);
int		ft_putstr_len_fd(char *str, int fd);
char	*ft_getnbr_base_signed(long n, char *base_to);
char	*ft_getnbr_base_unsigned(unsigned long n, char *base_to);

int		print_ulong_base(va_list ap, char *base);
int		print_long_base(va_list ap, char *base);
int		print_int_base(va_list ap, char *base);
int		print_unsigned_base(va_list ap, char *base);
int		print_pointer(va_list ap);
int		print_string(va_list ap);
int		print_char(va_list ap);
int		print_percent(void);
int		print_unknown(char c);

#endif