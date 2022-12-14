/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:58:54 by teliet            #+#    #+#             */
/*   Updated: 2022/11/10 18:11:39 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_from_pos(char *pos, char *to_find, size_t i, size_t len)
{
	while (*to_find)
	{
		if (*to_find != *pos || i > len)
			return (0);
		pos++;
		to_find++;
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	char			*big_v;
	unsigned int	needle_size;
	unsigned int	hay_size;

	if (!len && !big)
		return (0);
	needle_size = ft_strlen(little);
	hay_size = ft_strlen(big);
	i = 0;
	big_v = (char *)big;
	if (*little == 0)
		return ((char *)big);
	while (*big_v && i <= len - needle_size && i <= hay_size - needle_size)
	{
		if (check_from_pos(big_v, (char *)little, i, len))
			return (big_v);
		big_v++;
		i++;
	}
	return (0);
}
