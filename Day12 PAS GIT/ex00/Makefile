# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 11:55:20 by awoimbee          #+#    #+#              #
#    Updated: 2018/07/16 11:55:23 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	ft_display_file

SRCS	=	./srcs/*.c

HEADERS =	./incs/

all	:
		@make $(NAME)

$(NAME)	:
		gcc -Werror -Wall -Wextra $(SRCS) -I $(HEADERS) -o $(NAME)

clean	:
		rm -f ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
