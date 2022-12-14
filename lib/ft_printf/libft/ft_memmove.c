/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:42:59 by teliet            #+#    #+#             */
/*   Updated: 2022/11/09 17:48:57 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	int				diff;

	diff = src - dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if ((int)n < diff || (int)n < -diff)
		return (ft_memcpy(dest, src, n));
	i = -1;
	if (0 < diff)
	{
		while (++i < n)
			((char *)dest)[i] = ((char *)src)[i];
	}
	else
	{
		while (++i < n)
			((char *)dest)[n - 1 - i] = ((char *)src)[n - 1 - i];
	}
	return (dest);
}
