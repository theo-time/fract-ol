/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:54:58 by teliet            #+#    #+#             */
/*   Updated: 2022/11/09 17:48:57 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *begin_list, void (*f)(void *))
{
	if (!begin_list)
		return ;
	while (begin_list)
	{
		(*f)(begin_list->content);
		begin_list = begin_list->next;
	}
}
