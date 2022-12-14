/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:04:51 by teliet            #+#    #+#             */
/*   Updated: 2022/11/09 17:48:57 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sub_size(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;

	i = 0;
	while (s[start + i] && i < len)
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*output;
	unsigned int	size;
	unsigned int	i;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_calloc(1, 1));
	size = get_sub_size(s, start, len);
	output = malloc(size + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (i < size)
	{
		output[i] = s[start + i];
		i++;
	}
	output[i] = 0;
	return (output);
}
