# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teliet <teliet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:41:39 by teliet            #+#    #+#              #
#    Updated: 2022/11/10 18:12:05 by teliet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
	ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_bzero.c ft_toupper.c ft_tolower.c ft_strlcat.c ft_strlcpy.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_calloc.c \
	ft_strjoin.c ft_substr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c  \
	ft_split.c  ft_strtrim.c ft_itoa.c  ft_strmapi.c  ft_striteri.c \
	
SRC_BONUS = ${SRC} ft_lstnew_bonus.c  ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c
	
SRC_debug =	${SRC}	main.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: ${NAME}

${NAME}: ${OBJ}
	ar -rc $@ ${OBJ}

bonus: ${OBJ_BONUS}
	ar -rc libft.a ${OBJ_BONUS} 
	
debug: ${SRC_debug}
	gcc ${SRC_debug} -g3 -o a.out

%.o:	%.c
	gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o) -lbsd

clean:
	/bin/rm -f ${OBJ_BONUS}

fclean: clean
	/bin/rm -f ${NAME}

re: fclean all
