/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:43:14 by teliet            #+#    #+#             */
/*   Updated: 2022/11/10 14:57:15 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == 0 && *s == 0)
		return ((char *)s);
	while (s[i])
	{
		if (s[i] == c % 256)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c % 256)
		return ((char *)s + i);
	return (NULL);
}
