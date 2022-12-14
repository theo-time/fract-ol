/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:51:24 by teliet            #+#    #+#             */
/*   Updated: 2022/11/09 17:48:57 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	int				dest_size;

	dest_size = ft_strlen(dest);
	i = 0;
	while (src[i] != 0)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = 0;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*output;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	output = malloc(size * sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (i < size)
		output[i++] = 0;
	i = 0;
	ft_strcat(output, (char *)s1);
	ft_strcat(output, (char *)s2);
	return (output);
}
