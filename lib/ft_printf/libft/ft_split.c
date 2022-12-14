/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:14:50 by teliet            #+#    #+#             */
/*   Updated: 2022/11/09 17:48:57 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_elements(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] && (str[i] != c))
				i++;
			count++;
			i--;
		}
		i++;
	}
	return (count);
}

static char	*get_word(char *start, char *end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(end - start + sizeof(char));
	if (!word)
		return (NULL);
	while (&start[i] != end)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	*start_word;
	char	*end_word;
	char	**strs;
	int		count;
	int		i;

	strs = malloc(sizeof(char *) * (count_elements((char *)s, c) + 1));
	if (!strs)
		return (NULL);
	count = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c)
		{
			start_word = &((char *)s)[i];
			while (s[i] && (s[i] != c))
				i++;
			end_word = &((char *)s)[i];
			strs[count++] = get_word(start_word, end_word);
			i--;
		}
	}
	strs[count] = NULL;
	return (strs);
}
