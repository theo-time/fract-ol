# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teliet <teliet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:41:39 by teliet            #+#    #+#              #
#    Updated: 2022/12/09 12:44:31 by teliet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c  \
      src/color/color_ops.c src/color/color_algos.c src/color/color_converts.c src/color/color_converts2.c \
	  src/formulas/bitwise_formulas.c src/formulas/mandelbrot.c src/formulas/julia.c src/formulas/burning_ship.c \
	  src/camera.c \
	  src/controller.c \
	  lib/gnl/get_next_line.c lib/gnl/get_next_line_utils.c \
	  src/UI/GUI.c 

CC = gcc

HEADERS = -I ./includes

LFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIBS = lib/ft_printf/libftprintf.a 

OBJ = $(SRC:.c=.o)

all: ${NAME}
 
$(NAME): $(OBJ) $(LIBS)
	$(CC) $(OBJ) $(LIBS) $(HEADERS) $(LFLAGS) -o $(NAME)

$(LIBS):
	make -C lib/ft_printf
	
debug: $(LIBS)
	$(CC) $(SRC) $(LIBS) $(HEADERS) $(LFLAGS) -g3 -o $(NAME) 


%.o: %.c
	$(CC) -Wall -Wextra -Werror $(HEADERS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	/bin/rm -f ${OBJ}

fclean: clean
	/bin/rm -f ${NAME}

re: fclean all
