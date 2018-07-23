# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 20:42:37 by awoimbee          #+#    #+#              #
#    Updated: 2018/07/21 20:42:39 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	eval_expr

SRCS =	./srcs/eval_expr.c	\
		./srcs/functions.c	\
		./srcs/main.c		\
		./srcs/calc.c

INCLUDES =	./includes

all	:
		@make $(NAME)

$(NAME)	:
		cc -Werror -Wall -Wextra $(SRCS) -I $(INCLUDES) -o $(NAME)

clean	:
		rm -f $(NAME)

fclean	:	clean				

re	:	fclean all
