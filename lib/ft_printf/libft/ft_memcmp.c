/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:51:08 by teliet            #+#    #+#             */
/*   Updated: 2022/11/10 14:42:28 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char			*c1;
	char			*c2;
	unsigned int	i;

	i = 0;
	c1 = (char *)s1;
	c2 = (char *)s2;
	while (i < n)
	{
		if (*c1 != *c2)
			return ((unsigned char)*c1 - (unsigned char)*c2);
		c1++;
		c2++;
		i++;
	}
	return (0);
}
