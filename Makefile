# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 12:02:41 by mottjes           #+#    #+#              #
#    Updated: 2023/06/13 18:47:08 by mottjes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	./ft_printf.c				\
		./ft_printf_character.c		\
		./ft_printf_numbers.c		\

OBJS = $(SRC:.c=.o)

HDR = ft_printf.h

all: $(NAME)

$(NAME):
	cc -c -Wall -Wextra -Werror $(HDR) $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS) $(HDR).gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
