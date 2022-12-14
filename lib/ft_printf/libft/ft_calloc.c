/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:27:37 by teliet            #+#    #+#             */
/*   Updated: 2022/11/10 17:38:56 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*output;
	unsigned int	i;

	i = 0;
	if (INT_MAX / nmemb < size)
		return (NULL);
	output = malloc(nmemb * size);
	if (!output)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)output)[i] = 0;
		i++;
	}
	return (output);
}
