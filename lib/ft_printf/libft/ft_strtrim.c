/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:44:53 by teliet            #+#    #+#             */
/*   Updated: 2022/11/10 16:17:50 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	includes(const char *charset, const char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*get_empty_str(void)
{
	char	*null_str;

	null_str = malloc(sizeof(*null_str));
	*null_str = 0;
	return (null_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	trim_start;
	unsigned int	trim_end;
	int				i;
	char			*output;
	int				final_size;

	i = 0;
	while (includes(set, s1[i]))
		i++;
	trim_start = i;
	i = ft_strlen(s1) - 1;
	trim_end = 0;
	if (ft_strlen(s1) == trim_start)
		return (get_empty_str());
	while (includes(set, s1[i]) && i-- > 0)
		trim_end++;
	final_size = ft_strlen(s1) - trim_start - trim_end;
	output = ft_substr(s1, trim_start, final_size);
	if (!output)
		return (NULL);
	output[final_size] = 0;
	return (output);
}
