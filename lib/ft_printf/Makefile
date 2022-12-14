# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teliet <teliet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:41:39 by teliet            #+#    #+#              #
#    Updated: 2022/11/17 18:03:05 by teliet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/ft_printf.c src/printers.c src/printers2.c src/utils.c src/ft_convert_base.c 

LIBS = libft.a

SRC_DEBUG =	${SRC} src/main.c
OBJ_DEBUG = $(SRC_DEBUG:.c=.o)

HEADERS = -I ./includes

OBJ = $(SRC:.c=.o)

FLAGS = -c -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJ}
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	# $(CC) $(FLAGS) $(HEADERS) $(SRC)
	ar -rcs $(NAME) ${OBJ}

debug: libft.a
	gcc ${SRC_DEBUG} libft/libft.a ${HEADERS} -g3 -o a.out

%.o:	%.c
	gcc ${FLAGS} ${HEADERS} -c $< -o $(<:.c=.o)

clean:
	$(MAKE) fclean -C ./libft
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
