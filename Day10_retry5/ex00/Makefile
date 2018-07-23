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


NAME	=	libft.a

SRCS	=	./srcs/ft_putchar.c			\
			./srcs/ft_putstr.c			\
			./srcs/ft_strcmp.c			\
			./srcs/ft_strlen.c			\
			./srcs/ft_swap.c

HEADERS =	./includes/

all	:
		@make $(NAME)

$(NAME)	:
		gcc -Werror -Wall -Wextra -I $(HEADERS) -c $(SRCS)
		ar rcs $(NAME) ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

clean	:
		rm -f ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
