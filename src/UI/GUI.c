/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:40:22 by teliet            #+#    #+#             */
/*   Updated: 2022/12/09 12:50:24 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void print_menu()
{
    int fd;
    char *line;
    fd = open("./src/UI/Title", O_RDONLY);
    line = get_next_line(fd);
    while(line)
    {
        ft_printf("%s", line);
        free(line);
        line = get_next_line(fd);  
    }
    close(fd);
}