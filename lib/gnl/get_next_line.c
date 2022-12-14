/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:32:12 by teliet            #+#    #+#             */
/*   Updated: 2022/12/09 12:37:51 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fractol.h"

int	get_n_index(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-2);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_to_next_line(int fd, char *static_buf)
{
	int		size;
	char	*buf;
	char	*tmp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	size = BUFFER_SIZE;
	while (get_n_index(static_buf) < 0 && size != 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[size] = 0;
		tmp = static_buf;
		static_buf = ft_strcat_realloc(static_buf, buf);
		free(tmp);
	}
	free(buf);
	return (static_buf);
}

char	*get_line(char **s_buf)
{
	char	*tmp;
	char	*line;
	int		n_index;

	n_index = get_n_index(*s_buf);
	if (n_index == -2)
		return (NULL);
	else if (n_index == -1)
	{
		line = ft_strdup(*s_buf);
		free(*s_buf);
		*s_buf = NULL;
	}
	else
	{
		line = ft_substr(*s_buf, 0, n_index + 1);
		tmp = *s_buf;
		*s_buf = ft_substr(*s_buf, n_index + 1, ft_strlen(*s_buf));
		free(tmp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s_buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s_buf = get_to_next_line(fd, s_buf);
	if (!s_buf || (s_buf && s_buf[0] == 0))
	{
		free(s_buf);
		s_buf = NULL;
		return (NULL);
	}
	line = get_line(&s_buf);
	return (line);
}
