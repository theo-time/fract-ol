/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:32:12 by teliet            #+#    #+#             */
/*   Updated: 2022/12/21 17:54:44 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_not_null(char *dest, char *src)
{
	char	*output;
	char	*todup;
	int		i;
	int		size;

	todup = NULL;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (src == NULL)
		todup = dest;
	if (dest == NULL)
		todup = src;
	size = ft_strlen(todup);
	output = malloc(size + 1);
	i = 0;
	while (todup[i])
	{
		output[i] = todup[i];
		i++;
	}
	output[i] = 0;
	return (output);
}

char	*ft_strcat_realloc(char *dest, char *src)
{
	int		i;
	int		j;
	int		size_tot;
	char	*long_dest;

	if (src == NULL || dest == NULL)
		return (str_not_null(dest, src));
	size_tot = ft_strlen(dest) + ft_strlen(src);
	long_dest = (char *)malloc((size_tot + 1) * sizeof(char));
	if (long_dest == NULL)
		return (NULL);
	i = 0;
	while (dest[i] != '\0')
	{
		long_dest[i] = dest[i];
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		long_dest[i + j] = src[j];
		j++;
	}
	long_dest[size_tot] = '\0';
	return (long_dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

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
		return (NULL);
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
