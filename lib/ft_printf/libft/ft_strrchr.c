/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:47:12 by teliet            #+#    #+#             */
/*   Updated: 2022/11/10 15:08:04 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;

	result = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c % 256)
			result = ((char *)s + i);
		i++;
	}
	if (s[i] == c % 256)
		result = ((char *)s + i);
	return (result);
}
